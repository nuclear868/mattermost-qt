/**
 * @file log.h
 * @brief
 * @author Lyubomir Filipov
 * @date Dec 29, 2021
 */

#pragma once

#include <QTime>
#include <QDebug>

namespace Mattermost {

#define LOG_DEBUG(x) qDebug().noquote().nospace() << QTime::currentTime().toString("HH:mm:ss:zzz ") << x

} /* namespace Mattermost */

