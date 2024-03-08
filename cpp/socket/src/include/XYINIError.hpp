/*
this header depends on official headers below(此头文件依赖于以下官方头文件)
iostream
string
this header depends on custom headers below(此头文件依赖于以下自定义头文件)
XYError.hpp
XYNameSpace.h
time: 2023-07-10 17:37:07
*/

#pragma once
#ifndef _XYINIERROR_HPP_
#define _XYINIERROR_HPP_

#include <iostream>
#include <string>
#include "XYNamespace.h"
#include "XYError.hpp"

#define XYINI_NULL_FILENAME 10001UL
#define XYINI_NOTFOUND_KEY 10002UL
#define XYINI_ZEROORNULL_SIZE 10003UL
#define XYINI_LACKSPACE_RETURN 10004UL


_XYWIN_BEGIN
/*
name: XYWin::XYINIerror
usage: 传递错误信息
member: unsigned long XYINIec,string desc XYINIec表示XYINI错误码，desc为错误描述文本
date: 2023-07-10 17:37:04
*/
    class XYINIerror : _XYCONVENIENCE _XYERROR {
        public:
            XYINIerror() : XYerror(){}
            XYINIerror(unsigned long ec,std::string desc) : XYerror(ec,desc){}
            void printDescription()
            {
                std::cout<<this->description<<std::endl;
            }
    };
_XYWIN_END

#endif