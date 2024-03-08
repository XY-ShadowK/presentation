/*
this header depends on official headers below(此头文件依赖于以下官方头文件)
Windows.h
string
atlstr.h
this header depends on custom headers below(此头文件依赖于以下自定义头文件)
XYNamespace.h
time: 2023-07-10 17:17:54
*/

#pragma once
#ifndef _XYINI_HPP_
#define _XYINI_HPP_

#include <Windows.h>
#include <string>
#include <atlstr.h>
#include "XYINIError.hpp"
#include "XYNameSpace.h"

_XYWIN_BEGIN
    extern inline CString convertCString(std::wstring);
    extern inline CString convertCString(const char*);
class ini{
    private:
        LPCTSTR lpFilePath;
        LPCTSTR lpFileName;
        LPCTSTR lpFile;
        XYINIerror error;
        void setFile();
        bool errorNullFileName();
    public:
        ini() : lpFilePath(TEXT("")),lpFileName(TEXT("")),lpFile(TEXT("")){}
        ini(LPCTSTR lpFP,LPCTSTR lpFN) : lpFilePath(lpFP),lpFileName(lpFN)
        {
            this->setFile();
        }
        void setPath(LPCTSTR);
        void setName(LPCTSTR);
        bool isNullFileName();
        XYINIerror getLastError();
        UINT getValueInt(LPCTSTR,LPCTSTR,int);
        DWORD getSection(LPCTSTR,LPTSTR,DWORD);
        DWORD getSectionNames(LPTSTR,DWORD);
        DWORD getValueString(LPCTSTR,LPCTSTR,LPCTSTR,LPTSTR,DWORD);
        BOOL getValueStruct(LPCTSTR,LPCTSTR,LPVOID,UINT);
        BOOL writeSection(LPCTSTR,LPCTSTR);
        BOOL writeValueString(LPCTSTR,LPCTSTR,LPCTSTR);
        BOOL writeValueStruct(LPCTSTR,LPCTSTR,LPVOID,UINT);
};
_XYWIN_END

#endif