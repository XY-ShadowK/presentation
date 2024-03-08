/*
this header depends on official headers below(此头文件依赖于以下官方头文件)
iostream
string
this header depends on custom headers below(此头文件依赖于以下自定义头文件)
XYError.hpp
XYNameSpace.h
time: 2023-08-03 15:52:01
*/

#pragma once
#ifndef _XYSOCKETERROR_HPP_
#define _XYSOCKETERROR_HPP_

#include <iostream>
#include <string>
#include "XYNamespace.h"
#include "XYError.hpp"

#define XYS_FAIL_OPENNETLIB 10001UL
#define XYS_INCORRECT_NETLIBVERSION 10002UL
#define XYS_FAIL_BUILDSOCKET 10003UL
#define XYS_FAIL_BLOCKSOCKET 10004UL
#define XYS_FAIL_UNBLOCKSOCKET 10005UL
#define XYS_FAIL_BINDSOCKET 10006UL
#define XYS_FAIL_LISTENSOCKET 10007UL
#define XYS_FAIL_ACCEPTSOCKET 10008UL
#define XYS_FAIL_CONNECTSOCKADDR 10009UL
#define XYS_FAIL_RECEIVE 10010UL
#define XYS_FAIL_SEND 10011UL

_XYWIN_BEGIN
_XYSOCKET_BEGIN
/*
name: XYWin::XYSocket::XYSerror
usage: 传递错误信息
member: unsigned long XYSec,int WSAec,string desc XYSec表示XYS错误码，WSAec表示WSA错误码，desc为错误描述文本
date: 2023-07-10 17:25:01
*/
    class XYSerror : _XYCONVENIENCE _XYERROR {
        public:
            int WSA_errorCode;
            XYSerror() : XYerror(),WSA_errorCode(0){}
            XYSerror(unsigned long ec,int WSAec,std::string desc) : XYerror(ec,desc),WSA_errorCode(WSAec){}
/*
name: XYWin::XYSocket::XYerror::printDescription
function: 以c++标准输出流打印错误描述
parameter: none
return: void
date: 2023-08-03 15:51:56
*/
            void printDescription()
            {
                std::cout<<this->description<<std::endl;
            }
    };
_XYSOCKET_END
_XYWIN_END

#endif