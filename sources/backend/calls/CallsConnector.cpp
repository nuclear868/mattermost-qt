/**
 * @file CallsConnector.cpp
 * @brief Manages Mattermost calls
 * @author Lyubomir Filipov
 * @date Aug 3, 2022
 *
 * Copyright 2021, 2022 Lyubomir Filipov
 *
 * This file is part of Mattermost-QT.
 *
 * Mattermost-QT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Mattermost-QT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Mattermost-QT; if not, see https://www.gnu.org/licenses/.
 */

#include "CallsConnector.h"

#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QtEndian>
#include "log.h"

#include <memory>
#include <algorithm>
#include <future>
#include <QDataStream>
#include <QFile>
#include <iostream>
#include <memory>
#include <random>
#include <stdexcept>
#include <thread>
#include <unordered_map>
#include "libdatachannel/include/rtc/rtc.hpp"


using namespace std::chrono_literals;
using std::shared_ptr;
using std::weak_ptr;

static std::unordered_map<std::string, shared_ptr<rtc::PeerConnection>> peerConnectionMap;
static std::unordered_map<std::string, shared_ptr<rtc::DataChannel>> dataChannelMap;
template <class T> weak_ptr<T> make_weak_ptr(shared_ptr<T> ptr) { return ptr; }

namespace Mattermost {

static const QMap<QString, std::function<void(CallsConnector&, const QJsonObject&, const QJsonObject&)>> eventHandlers {
	{"hello", [] (CallsConnector& conn, const QJsonObject&, const QJsonObject&) {
		std::cout << "Hello" << std::endl;

		QJsonDocument json (QJsonObject {
			{"action", "custom_com.mattermost.calls_join"},
			{"seq", (int)conn.seq},
			{"data", QJsonObject {
				{"channelID", conn.channelID}}
			},
		});

		QByteArray data = json.toJson(QJsonDocument::Compact);
		conn.sendTextMessage (data);
	}},
	{"custom_com.mattermost.calls_join", [] (CallsConnector& conn, const QJsonObject&, const QJsonObject&) {

		std::cout << "join" << std::endl;

		static QTimer connectTimer;

		QTimer::singleShot (1, [=,&conn] {

		std::string id = "id";

		auto pc = conn.createPeerConnection ();

		auto dc = pc->createDataChannel ("test");

		dc->onOpen([id, wdc = make_weak_ptr(dc)]() {
				std::cout << "DataChannel from " << id << " open" << std::endl;
				if (auto dc = wdc.lock()) {

					static rtc::binary bytes;

					for (int i = 0; i < 10000; ++i) {
						bytes.push_back ((std::byte)i);
					}
					dc->send (bytes);
				}
			});

		dc->onClosed([id] {
			std::cout << "DataChannel from " << id << " closed" << std::endl;
		});

		dc->onMessage([id, wdc = make_weak_ptr(dc)](auto data) {
			// data holds either std::string or rtc::binary
			if (std::holds_alternative<std::string>(data))
				std::cout << "Message from " << id << " received: " << std::get<std::string>(data)
				          << std::endl;
			else
				std::cout << "Binary message from " << id
				          << " received, size=" << std::get<rtc::binary>(data).size() << std::endl;
		});

		dataChannelMap.emplace(id, dc);
		});
	}},
	{"custom_com.mattermost.calls_signal", [] (CallsConnector& conn, const QJsonObject& data, const QJsonObject&) {
		QJsonObject innerObj = QJsonDocument::fromJson (data.value ("data").toString().toUtf8()).object();

//		QJsonDocument doc (innerObj);
//		QString jsonString = doc.toJson(QJsonDocument::Indented);
//		qDebug().noquote() << jsonString;

		QJsonValue typeValue = innerObj.value("type");

		if (typeValue.isUndefined()) {
			qDebug() << "No 'type' field in signal packet";
			return;
		}

		QString type = typeValue.toString();

		if (type == "candidate") {
			conn.onRemoteCandidate (innerObj.value("candidate").toObject().value ("candidate").toString());
		} else if (type == "answer") {
			conn.onRemoteAnswer (innerObj.value("sdp").toString ());
		} else {
			qDebug() << "Unknown type '" << type << "' in signal packet";
		}
	}},
};

CallsConnector::CallsConnector (QString ICEServer, const QString& urlString, const QString& token)
:ICEServer (std::move (ICEServer))
,urlString (urlString)
,token (token)
,hasReconnect (false)
{
	rtc::InitLogger (rtc::LogLevel::Debug);

	connect (&webSocket, qOverload<QAbstractSocket::SocketError>(&QWebSocket::error), [this] (QAbstractSocket::SocketError error){
		qDebug() << "WebSocket error " << error << " " << webSocket.errorString();
		doReconnect ();
	});

	connect(&webSocket, &QWebSocket::connected, [this] {
		LOG_DEBUG ("WebSocket connected");
		seq = 1;
		doHandshake ();

		if (hasReconnect) {
			emit onReconnect ();
		}

		hasReconnect = false;
		pingTimer.start (5000);
	});

	connect(&webSocket, &QWebSocket::pong, [this]{
		//LOG_DEBUG ("WebSocket pong");
		pongTimer.stop();
	});

	connect(&webSocket, &QWebSocket::disconnected, [this]{
		LOG_DEBUG ("WebSocket disconnected: " << webSocket.closeCode() << " " << webSocket.closeReason());
		doReconnect ();
	});

    connect(&webSocket, &QWebSocket::textMessageReceived, this, &CallsConnector::onNewPacket);

    connect (&pingTimer, &QTimer::timeout, [this] {
		//LOG_DEBUG ("WebSocket send ping");
		webSocket.ping ("ping");
		pongTimer.start (4000);
	});

    pongTimer.setSingleShot (true);
    connect (&pongTimer, &QTimer::timeout, [this] {
		LOG_DEBUG ("WebSocket ping timeout. Reconnecting");
		webSocket.close();
	});

	qDebug() << "CallsConnector: Use ICEServer: " << this->ICEServer;
}

CallsConnector::~CallsConnector () = default;

void packString (QByteArray& bytearr, const QString& str)
{
	if (str.size() > 255) {
		bytearr.append (0xc5);

		uint16_t size = str.size();
		size = qToBigEndian (size);

		bytearr.append (QByteArray::fromRawData ((char*)&size, sizeof (size)));
	} else {
		bytearr.append (0xa0 + str.size());
	}
	bytearr.append (str.toLatin1());
}

void packInt (QByteArray& bytearr, int num)
{
	bytearr.append ((uint8_t) num);
}

void packJsonObject (QByteArray& byteArr, const QJsonObject& obj, QStringList orderedKeys)
{
	byteArr.append (0x80 + obj.size());

	if (orderedKeys.empty()) {
		orderedKeys = obj.keys();
	}

	for (const auto& key: orderedKeys) {
		packString (byteArr, key);
		QJsonValue value = obj.value(key);

		if (value.isString()) {
			packString (byteArr, value.toString());
		} else if (value.isDouble()) {
			packInt (byteArr, value.toInt());
		} else if (value.isObject()) {
			packJsonObject (byteArr, value.toObject(), {});
		} else {
			qDebug () << "Unhandled json value " << value;
		}
	}
}

QByteArray compress(const QByteArray& data)
{
    auto compressedData = qCompress(data);
    //  Strip the first six bytes (a 4-byte length put on by qCompress and a 2-byte zlib header)
    // and the last four bytes (a zlib integrity check).
    compressedData.remove(0, 4);

    return compressedData;
}

std::shared_ptr<rtc::PeerConnection> CallsConnector::createPeerConnection ()
{
	rtc::Configuration config;
	config.iceServers.push_back(rtc::IceServer (this->ICEServer.toStdString()));
	config.enableIceUdpMux = true;
	config.enableIceTcp = true;

	std::cout << "createPeerConnection " << std::endl;

	auto pc = std::make_shared<rtc::PeerConnection>(config);

	pc->onStateChange([](rtc::PeerConnection::State state) {
		std::cout << "State: " << state << std::endl;
	});

	pc->onGatheringStateChange([](rtc::PeerConnection::GatheringState state) {
		std::cout << "Gathering State: " << state << std::endl;
	});

	pc->onSignalingStateChange([](rtc::PeerConnection::SignalingState state) {
		std::cout << "Signaling State: " << state << std::endl;
	});


	pc->onLocalDescription ([this](rtc::Description description) {

		//sdp data, obtained from wireshark
		//QString wiresharkSdp = R"Q(v=0\r\no=mozilla...THIS_IS_SDPARTA-84.0.2 3962917514102104214 0 IN IP4 0.0.0.0\r\ns=-\r\nt=0 0\r\na=sendrecv\r\na=fingerprint:sha-256 72:73:8E:45:A8:8E:7D:8D:29:79:24:E9:66:C7:3A:1F:6C:7B:09:92:44:D9:71:87:3A:87:58:B5:9D:BE:E3:90\r\na=group:BUNDLE 0\r\na=ice-options:trickle\r\na=msid-semantic:WMS *\r\nm=application 9 UDP/DTLS/SCTP webrtc-datachannel\r\nc=IN IP4 0.0.0.0\r\na=sendrecv\r\na=ice-pwd:77eb532666ec8b335d1d94a13adb4794\r\na=ice-ufrag:94ab7050\r\na=mid:0\r\na=setup:actpass\r\na=sctp-port:5000\r\na=max-message-size:1073741823\r\n)Q";

		QString innerString = "{\"type\":\"" + QString::fromStdString (description.typeString()) +"\",\"sdp\":\"" + QString::fromStdString (description.generateSdp("\\r\\n")) + "\"}";
		QByteArray compressed = compress (innerString.toLatin1());

		//std::cout << "\n\ntestSdp:" << testSdp.toStdString() << "\n";
		//std::cout << "\n\nuncompressed:" << innerString.toStdString() << "\n";
		//qDebug () << "compressed:" << compressed.toHex();

		QFile file1 ("qdata-arch");
		file1.open (QIODevice::WriteOnly);
		file1.write (compressed);
		file1.close();

		QJsonValue comprValue (QString::fromLatin1(compressed.data(), compressed.size()));

		QJsonObject json {
			{"action", "custom_com.mattermost.calls_sdp"},
			{"seq", (int) seq},
			//{"data", QJsonValue (QString::fromLatin1(compressed.data(), compressed.size()))},
			{"data",
					QJsonObject ({{"data", comprValue}}),
			}
		};

		QByteArray jsonBinary;
		packJsonObject (jsonBinary, json, {"action", "seq", "data"});
		//qDebug () << "arr:" << arr.toHex();
		QFile file ("qdata");
		file.open (QIODevice::WriteOnly);
		file.write (jsonBinary);
		file.close();

		//QJsonDocument doc (json);
		//QString jsonString = doc.toJson(QJsonDocument::Indented);
		//std::cout << jsonString.toStdString() << std::endl;
		sendBinaryMessage (jsonBinary);
//
//		if (auto ws = wws.lock())
//			ws->send(message.dump());
	});

	pc->onLocalCandidate ([this](rtc::Candidate candidate) {

		std::cout << "onLocalCandidate: " << candidate << std::endl;
		QJsonObject json;
		json.insert ("action", "custom_com.mattermost.calls_ice");
		json.insert ("seq", (int)seq);

		QJsonObject innerJson {
			{"candidate", QString::fromStdString (candidate.candidate())},
			{"sdpMLineIndex", 0},
			{"sdpMid", QString::fromStdString(candidate.mid())},
			{"usernameFragment","7c3d181f"},
		};
		QString innerString = QJsonDocument (innerJson).toJson(QJsonDocument::Compact);
		json.insert ("data", QJsonObject {{"data", innerString}});
		QJsonDocument doc (json);
		QString jsonString = doc.toJson(QJsonDocument::Indented);
#if 0
		std::cout << jsonString.toStdString() << std::endl;
#endif
		sendTextMessage (jsonString);


#if 0
#endif

//		json message = {{"id", id},
//		                {"type", "candidate"},
//		                {"candidate", std::string(candidate)},
//		                {"mid", candidate.mid()}};

		//if (auto ws = wws.lock())
		//ws->send(message.dump());
	});

	std::string id = "client";
	pc->onDataChannel([id](shared_ptr<rtc::DataChannel> dc) {
		std::cout << "Incoming dataChannel from " << id << " received with label \"" << dc->label() << "\"" << std::endl;

		dc->onOpen([wdc = make_weak_ptr(dc)] {
			std::cout << "DataChannel onOpen" << std::endl;
			if (auto dc = wdc.lock())
				dc->send("Hello");
		});

		dc->onClosed([id] {
			std::cout << "DataChannel from " << id << " closed" << std::endl;
		});

		dc->onMessage([id](auto data) {
			// data holds either std::string or rtc::binary
			if (std::holds_alternative<std::string>(data))
				std::cout << "Message from " << id << " received: " << std::get<std::string>(data)
				          << std::endl;
			else
				std::cout << "Binary message from " << id
				          << " received, size=" << std::get<rtc::binary>(data).size() << std::endl;
		});

		dataChannelMap.emplace(id, dc);
	});

	pc->onTrack([id](shared_ptr<rtc::Track> track) {
		std::cout << "onTrack" << std::endl;
	});

	peerConnectionMap.emplace(id, pc);
	return pc;
};

void CallsConnector::openWebSocket (const QString& channelID)
{
	this->channelID = channelID;
	QUrl url (urlString + "websocket");
	url.setScheme("wss");

	//qDebug() << "WebSocket open: " << url << " " << token;

	webSocket.open (url);
}

int64_t CallsConnector::sendTextMessage (const QString& message)
{
	++seq;
	return webSocket.sendTextMessage (message);
}

int64_t CallsConnector::sendBinaryMessage (const QByteArray& message)
{
	++seq;
	return webSocket.sendBinaryMessage (message);
}

void CallsConnector::doHandshake ()
{
	QJsonObject  jsonData {
		{"token",token},
	};

	QJsonDocument json (QJsonObject {
		{"seq", (int)seq},
		{"action", "authentication_challenge"},
		{"data", jsonData},
	});

	QByteArray data = json.toJson(QJsonDocument::Compact);
	sendTextMessage (data);
}

static QSet<QString> eventsToSkipPrint {
	"custom_com.mattermost.calls_signal"
};

void CallsConnector::onNewPacket (const QString& string)
{
	QJsonDocument doc = QJsonDocument::fromJson(string.toUtf8());

	const QJsonObject& jsonObject = doc.object();

	//reply of sent packet
	QJsonValue seqReply = jsonObject.value("seq_reply");

	if (!seqReply.isUndefined()) {
		std::cout << "got seqReply " << seqReply.toInt() << std::endl;
		return;
	}

	//event from server
	QJsonValue event = jsonObject.value("event");

	auto it = eventHandlers.find(event.toString());

	if (it == eventHandlers.end()) {
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString();

		LOG_DEBUG ("Unhandled WebSocket event '" << event.toString() << "'\n");
		qDebug() << "========" << '\n';
		return;
	}

	if (!eventsToSkipPrint.contains (it.key())) {
		qDebug() << "========" << '\n';
		QString jsonString = doc.toJson(QJsonDocument::Indented);
		std::cout << jsonString.toStdString();
	}

	it.value() (*this, 	jsonObject.value ("data").toObject(),
						jsonObject.value ("broadcast").toObject());
}

void CallsConnector::onRemoteCandidate (const QString& candidateString)
{
	qDebug() << "Remote Candidate: " << candidateString;

	auto& pc = *peerConnectionMap.begin();

	pc.second->addRemoteCandidate (rtc::Candidate (candidateString.toStdString(), ""));
}

void CallsConnector::onRemoteAnswer (const QString& answerSdp)
{
	qDebug() << "Remote Answer sdp: " << answerSdp;
	auto& pc = *peerConnectionMap.begin();

	pc.second->setRemoteDescription (rtc::Description (answerSdp.toStdString(), rtc::Description::Type::Answer));
}

void CallsConnector::doReconnect ()
{
	pingTimer.stop();
	pongTimer.stop();
	QTimer::singleShot (2000, [this] {

		if (token.isEmpty()) {
			return;
		}

		LOG_DEBUG ("WebSocket Reconnecting");
		hasReconnect = true;
		webSocket.open (webSocket.requestUrl());
	});
}

} /* namespace Mattermost */
