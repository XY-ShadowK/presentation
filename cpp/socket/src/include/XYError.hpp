/*
this header depends on official headers below(此头文件依赖于以下官方头文件)
string
this header depends on custom headers below(此头文件依赖于以下自定义头文件)
XYNameSpace.h
time: 2023-07-08 12:46:08
*/

#pragma once
#ifndef _XYERROR_HPP_
#define _XYERROR_HPP_

#include <string>
#include "XYNameSpace.h"

#define _XYERROR XYerror

_XYCONVENIENCE_BEGIN
class _XYERROR{
    public:
        unsigned long errorCode;
        std::string description;
        virtual void printDescription()=0;
        _XYERROR() : errorCode(0UL),description(""){}
        _XYERROR(unsigned long ec,std::string desc) : errorCode(ec),description(desc){}
};
_XYCONVENIENCE_END

#endif