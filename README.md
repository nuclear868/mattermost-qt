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
* sending and receiving messages
* Receiving attached files. Image files can be viewed in a simple viewer and other files can be downloaded or opened with default application
* update, when a new team is added and you are added to it
* visual notifications for new messages

# What does not work / What is planned to be implemented
* sending files
* notifications when someone is typing and sending a notification when you are typing
* message editing
* emoticons, reactions, etc... (visual pleasures :) )
* caching of received data, mainly images (user avatars and channel images). Now all data is downloaded from the server at each startup
* Preview of team members, channel members, users, etc...
* Properly handing adding / deleting users / channels / teams

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
The credentials are saved in ~/.config/mattermost-native/Mattermost.conf (yes, they are not encrypted, I will find a cross-platform way to encrypt them) and are
not requested again on next start (if the login is successful)

## Contribution
I am making this as a side project, mostly for fun / additional experience, so any contributions like bugfixes or any issues from the 'What is planned to be implemented' list are welcome

