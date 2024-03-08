/*
this header depends on official headers below(此头文件依赖于以下官方头文件)
none
this header depends on custom headers below(此头文件依赖于以下自定义头文件)
none
time: 2023-07-08 12:33:34
*/

#pragma once
#ifndef _XYNAMESPACE_H_
#define _XYNAMESPACE_H_

/*
the namespace XYConvenience declare in(命名空间XYConvenience内容声明于):
XYError.hpp
date: 2023-07-07 21:47:15
*/
#define _XYCONVENIENCE_BEGIN namespace XYConvenience{
#define _XYCONVENIENCE_END }
#define _XYCONVENIENCE ::XYConvenience::

/*
the namespace XYSocket declare in(命名空间XYSocket内容声明于):
XYSocket.hpp
XYSocketError.hpp
date: 2023-07-07 21:41:41
*/
#define _XYSOCKET_BEGIN namespace XYSocket{
#define _XYSOCKET_END }
#define _XYSOCKET ::XYSocket::

/*
the namespace XYSocket declare in(命名空间XYWin内容声明于):
XYSocket.hpp
XYSocketError.hpp
XYINI.hpp
date: 2023-07-08 12:39:15
*/
#define _XYWIN_BEGIN namespace XYWin{
#define _XYWIN_END }
#define _XYWIN ::XYWin::

#endif