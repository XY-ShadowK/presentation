/*
this header depends on official headers below(此头文件依赖于以下官方头文件)
WinSock2.h
this header depends on custom headers below(此头文件依赖于以下自定义头文件)
XYSocketError.h
XYNameSpace.h
time: 2023-07-10 17:36:44
*/

#pragma once
#ifndef _XYSOCKET_HPP_
#define _XYSOCKET_HPP_

#include <WinSock2.h>
#include "XYSocketError.hpp"
#include "XYNamespace.h"

_XYWIN_BEGIN
_XYSOCKET_BEGIN
    extern WSADATA wsaData;
    extern XYSerror XYSGetLastError();
    extern bool openNetLib(byte,byte);
    extern SOCKET buildSocket(int,int,int);
    extern bool blockSocket(SOCKET);
    extern bool unblockSocket(SOCKET);
    extern bool bindSocket(SOCKET,const sockaddr*);
    extern bool bindSocket(SOCKET,signed int,u_short,const char*);
    extern bool listenSocket(SOCKET,int);
    extern SOCKET acceptClientSocket(SOCKET,sockaddr*,int*);
    extern SOCKET acceptClientSocket(SOCKET);
    extern bool connectServer(SOCKET,const sockaddr*);
    extern bool connectServer(SOCKET,signed int,u_short,const char*);
    extern int receive(SOCKET,char*,int,int);
    extern int sendData(SOCKET,char*,int,int);
_XYSOCKET_END
_XYWIN_END

#endif