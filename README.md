# mattermost-qt
Mattermost native desktop client, using the QT framework

# Motivation
* I was waiting too long for an open-source chat system, where you can develop a custom client application
* I want to get familiar with QT Desktop application development
* The official Mattermost desktop client is actually a javascript / typescript web application, running inside a dedicated web browser. This makes it veeery slow, it creates at least 10 processes and consumes a lot of RAM
* Also, such 'modern' web-based applications have some drawbacks:
    * No file transfer over LAN (yes, it makes transferring large files easier and sometimes people need to transfer large files)
    * They do not allow to quickly open an attached image in a new window - so that you can see the chat window and one or multiple (full-size) images at the same time. All 'fancy' messengers that I am using (Skype, FB messenger, official Mattermost) alway open attached images in the same window, over the chat area, so that you cannot see the chat and the image at the same time. The only way is to download the image and open it. And later, remove it if you don't want your home directory to be filled with unneeded image files.

# What does work
* viewing all available channels
* Sending and receiving messages
* visual notifications for new messages
* message editing and deleting
* Receiving attached files. Image files can be viewed in a simple viewer and other files can be downloaded or opened with default application
* Sending messages with attachments is supported too
* If a reconnect occurs, the chat history is synchronized with the server, so that no messages are lost.
* Cache is used for faster image loading.
* update, when a new team is added and you are added to it
* Preview of team members, channel members, users, etc. There are more items to be added, but the basic functionality is supported
* Properly handing adding / deleting users / channels / teams. However, it has to be tested more

# What does not work / What is planned to be implemented
* notifications when someone is typing and sending a notification when you are typing
* pinning posts to a channel and displaying pinned posts
* loading channel history when scrolling to the beginning of a channel
* emoticons, reactions, etc... (visual pleasures :) )
* settings - image preview sizes, download locations, etc... I want this application to be fully customizable

# What is planned in a perfect world (when I have a time to do it)
* LAN file transfer between 2 QT Mattermost clients
* Auto-detect if you are working from home and setting it as a status. This can be achieved by looking for an active VPN connection. It will be fully configurable from the settings

# Installation
the application is developed and tested on Ubuntu linux. I think it can be easisy built on Windows (and even for Android ?), as it uses entirely the QT framework, which is cross-platform. I just need to find some time to test it on Windows

## Required packages
* QT5 libraries (qtbase5-dev)
* QT5 websockets library (libqt5websockets5-dev)

## Build instructions
It is recommended to build in a separate directory:

    mkdir build
    cd build
    cmake ..
    make -j8
    
## Running
from the build directory just start ./qmattermost
A login form will appear and after a successful login all teams and channels should appear
The credentials are saved in ~/.config/mattermost-native/Mattermost.conf (yes, they are not encrypted, I will find a cross-platform way to encrypt them. At least, since release 0.1 a login token is used instead of the password) and are
not requested again on next start (if the login is successful)

## Contribution
I am making this as a side project, mostly for fun / additional experience, so any contributions like bugfixes or any issues from the 'What is planned to be implemented' list are welcome

