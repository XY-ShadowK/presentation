#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#include <atlstr.h>
#include "../../include/XYINI.hpp"

using std::cout;
using std::endl;
using std::wstring;

inline CString XYWin::convertCString(wstring wstr)
{
    CString cstr=wstr.c_str();
    return cstr;
}
inline CString XYWin::convertCString(const char* pcc)
{
    CString cstr=pcc;
    return cstr;
}
void XYWin::ini::setFile()
{
    CString path=this->lpFilePath,name=this->lpFileName,file;
    int offset=path.GetLength();
    path=(path[offset-1]=='/'||path[offset-1]=='\\')?path:(path+L"/");
    this->lpFilePath=path;
    file=path+name;
    this->lpFile=file;
    return;
}
bool XYWin::ini::errorNullFileName()
{
    if(this->isNullFileName()){
        this->error=XYINIerror(XYINI_NULL_FILENAME,"ERROR: File name is null.");
//        this->error=XYINIerror(XYINI_NOTFOUND_KEY,"错误: 文件全名为空。");
        return true;
    }
    return false;
}
void XYWin::ini::setPath(LPCTSTR lpFP)
{
    this->lpFilePath=lpFP;
}
void XYWin::ini::setName(LPCTSTR lpFN)
{
    this->lpFileName=lpFN;
}
bool XYWin::ini::isNullFileName()
{
    CString lpF=this->lpFile;
    return lpF.IsEmpty();
}
XYWin::XYINIerror XYWin::ini::getLastError()
{
    return this->error;
}
UINT XYWin::ini::getValueInt(LPCTSTR lpSectionName,LPCTSTR lpKeyName,int nDefault)
{
    if(this->errorNullFileName())return nDefault;
    UINT res=GetPrivateProfileInt(lpSectionName,lpKeyName,nDefault,this->lpFile);
    if(res==nDefault){
        this->error=XYINIerror(XYINI_NOTFOUND_KEY,"ERROR: KEY NOT FOUND");
//        this->error=XYINIerror(XYINI_NOTFOUND_KEY,"错误: 找不到指定键");
    }
    return res;
}
DWORD XYWin::ini::getSection(LPCTSTR lpSectionName,LPTSTR lpReturnedString,DWORD size)
{
    if(size==0){
        this->error=XYINIerror(XYINI_ZEROORNULL_SIZE,"ERROR: Size is zero.");
//        this->error=XYINIerror(XYINI_NOTFOUND_KEY,"错误: 大小为零。");
    }
    DWORD res=GetPrivateProfileSection(lpSectionName,lpReturnedString,size,this->lpFile);
    if(res==size-2){
        this->error=XYINIerror(XYINI_LACKSPACE_RETURN,"ERROR: Lack of space to return.");
//        this->error=XYINIerror(XYINI_NOTFOUND_KEY,"错误: 缺少空间以返回。");
    }
    return res; 
}
DWORD XYWin::ini::getSectionNames(LPTSTR lpszReturnBuffer,DWORD size)
{
    return GetPrivateProfileSectionNames(lpszReturnBuffer,size,this->lpFile);
}
DWORD XYWin::ini::getValueString(LPCTSTR lpSectionName,LPCTSTR lpKeyName,LPCTSTR lpDefault,LPTSTR lpReturnedString,DWORD size)
{
    return GetPrivateProfileString(lpSectionName,lpKeyName,lpDefault,lpReturnedString,size,this->lpFile);
}
BOOL XYWin::ini::getValueStruct(LPCTSTR lpszSection,LPCTSTR lpszKey,LPVOID lpStruct,UINT size)
{
    return GetPrivateProfileStruct(lpszSection,lpszKey,lpStruct,size,this->lpFile);
}
BOOL XYWin::ini::writeSection(LPCTSTR lpSectionName,LPCTSTR lpString)
{
    return WritePrivateProfileSection(lpSectionName,lpString,this->lpFile);
}
BOOL XYWin::ini::writeValueString(LPCTSTR lpSectionName,LPCTSTR lpKeyName,LPCTSTR lpString)
{
    return WritePrivateProfileString(lpSectionName,lpKeyName,lpString,this->lpFile);
}
BOOL XYWin::ini::writeValueStruct(LPCTSTR lpszSection,LPCTSTR lpszKey,LPVOID lpStruct,UINT size)
{
    return WritePrivateProfileStruct(lpszSection,lpszKey,lpStruct,size,this->lpFile);
}