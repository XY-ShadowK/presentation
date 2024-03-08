#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <WinSock2.h>
#include "../../include/XYSocket.hpp"
#pragma comment(lib,"ws2_32.lib")

using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace XYWin{
    namespace XYSocket{
        static unsigned long UNSIGNED_LONG_ONE=1;
        static unsigned long UNSIGNED_LONG_ZERO=0;
//常量定义
        static WSADATA wsaData;
        static XYSerror error;
//全局变量声明
        XYSerror XYSGetLastError();
        bool openNetLib(byte,byte);
        SOCKET buildSocket(int,int,int);
        bool blockSocket(SOCKET);
        bool unblockSocket(SOCKET);
        bool bindSocket(SOCKET,const sockaddr*);
        bool bindSocket(SOCKET,signed int,u_short,const char*);
        bool listenSocket(SOCKET,int);
        SOCKET acceptClientSocket(SOCKET,sockaddr*,int*);
        SOCKET acceptClientSocket(SOCKET);
        bool connectServer(SOCKET,const sockaddr*);
        bool connectServer(SOCKET,signed int,u_short,const char*);
        int receive(SOCKET,char*,int,int);
        int sendData(SOCKET,char*,int,int);
//全局函数声明
}}
/*
name: XYWin::XYSocket::XYSGetLastError
function: 返回上次XYSocket内的错误信息
parameter: none
return: XYWin::XYSocket::XYSerror 返回一个错误信息类对象，表示上次XYSocket发生的错误
date: 2023-07-08 10:54:36
*/
XYWin::XYSocket::XYSerror XYWin::XYSocket::XYSGetLastError()
{
    return error;
}
/*
name: XYWin::XYSocket::openNetLib
function: 打开指定版本网络库
parameter: byte vH,byte vL vH表示高优先级版本，vL表示低优先级版本
return: bool 成功打开网络库返回true，反之返回false
date: 2023-07-08 11:47:14
*/
bool XYWin::XYSocket::openNetLib(byte majorVersion,byte minorVersion){
    WORD version=MAKEWORD(majorVersion,minorVersion);
    int res=WSAStartup(version,&wsaData);
    //打开网络库成功返回0，失败返回错误码
    if(res){
//        cout<<"ERROR: Failed to open network library.(error code: "<<res<<')'<<endl;
//        cout<<"错误: 打开网络库失败。(错误码: "<<res<<')'<<endl;
        error=XYSerror(XYS_FAIL_OPENNETLIB,res,"ERROR: Failed to open network library.");
//        error=XYSerror(XYS_FAIL_OPENNETLIB,res,"错误: 打开网络库失败。");
        return false;
    }
    //若打开失败，输出错误信息并返回false
    if(majorVersion!=HIBYTE(wsaData.wVersion)||minorVersion!=LOBYTE(wsaData.wVersion)){
        error=XYSerror(XYS_INCORRECT_NETLIBVERSION,res,"ERROR: Incorrect network library version.");
//        error=XYSerror(XYS_INCORRECT_NETLIBVERSION,res,"错误: 打开网络库版本错误。");
        WSACleanup();
        return false;
    }
    //若打开网络库版本不对，则关闭网络库并返回false
    return true;
}
/*
name: XYWin::XYSocket::buildSocket
function: 构建socket
parameter: int af,int t,int p af表示地址族规范，表示socket类型，p表示使用的协议
return: SOCKET 成功构建返回构建好的socket，失败则返回INVALID_SOCKET
date: 2023-07-08 11:36:38
*/
SOCKET XYWin::XYSocket::buildSocket(int af,int type,int protocol)
{
    SOCKET sock=socket(af,type,protocol);
    if(sock==INVALID_SOCKET){
//        cout<<"ERROR: Failed to build socket.(error code: "<<WSAGetLastError()<<')'<<endl;
//        cout<<"错误: 构建套接字失败。(错误码: "<<WSAGetLastError()<<endl;
        error=XYSerror(XYS_FAIL_BUILDSOCKET,WSAGetLastError(),"ERROR: Failed to build socket.");
//        error=XYSerror(XYS_FAIL_BUILDSOCKET,WSAGetLastError(),"错误: 构建套接字失败。");
    }
    //构建失败输出错误信息并返回false
    return sock;
}
/*
name: XYWin::XYSocket::blockSocket
function: 设置socket阻塞
parameter: SOCKET s s表示待设置的socket
return: bool 成功返回true，失败返回false
date: 2023-07-08 11:37:13
*/
bool XYWin::XYSocket::blockSocket(SOCKET sock)
{
    if(ioctlsocket(sock,FIONBIO,&UNSIGNED_LONG_ZERO)==SOCKET_ERROR){
//        cout<<"ERROR: Failed to block socket.(error code: "<<WSAGetLastError()<<')'<<endl;
//        cout<<"错误: 设置套接字阻塞失败。(错误码: "<<WSAGetLastError()<<')'<<endl;
        error=XYSerror(XYS_FAIL_BLOCKSOCKET,WSAGetLastError(),"ERROR: Failed to block socket.");
//        error=XYSerror(XYS_FAIL_BLOCKSOCKET,WSAGetLastError(),"错误: 设置套接字阻塞失败。");
        return false;
    }
    return true;
}
/*
name: XYWin::XYSocket::unblockSocket
function: 设置socket非阻塞
parameter: SOCKET s s表示待设置的socket
return: bool 成功返回true，失败返回false
date: 2023-07-08 11:37:57
*/
bool XYWin::XYSocket::unblockSocket(SOCKET sock)
{
    if(ioctlsocket(sock,FIONBIO,&UNSIGNED_LONG_ONE)==SOCKET_ERROR){
//        cout<<"ERROR: Failed to unblock socket.(error code: "<<WSAGetLastError()<<')'<<endl;
//        cout<<"错误: 设置套接字非阻塞失败。(错误码: "<<WSAGetLastError()<<')'<<endl;
        error=XYSerror(XYS_FAIL_UNBLOCKSOCKET,WSAGetLastError(),"ERROR: Failed to unblock socket.");
//        error=XYSerror(XYS_FAIL_UNBLOCKSOCKET,WSAGetLastError(),"错误: 设置套接字非阻塞失败。");
        return false;
    }
    return true;
}
/*
name: XYWin::XYSocket::bindSocket
function: 将地址与端口绑定至socket
parameter: SOCKET s,const sockaddr* n s表示未绑定的socket，n表示指向需绑定的地址端口的地址端口结构体指针
return: bool 成功绑定socket返回true，反之返回false
date: 2023-07-08 11:38:44
*/
bool XYWin::XYSocket::bindSocket(SOCKET sock,const sockaddr* nam)
{
    if(bind(sock,nam,sizeof(sockaddr))==SOCKET_ERROR){
//        cout<<"ERROR: Failed to bind network port.(error code: "<<WSAGetLastError()<<')'<<endl;
//        cout<<"错误: 绑定地址与端口至套接字失败。(错误码: "<<WSAGetLastError()<<')'<<endl;
        error=XYSerror(XYS_FAIL_BINDSOCKET,WSAGetLastError(),"ERROR: Failed to bind network port.");
//        error=XYSerror(XYS_FAIL_BINDSOCKET,WSAGetLastError(),"错误: 绑定地址与端口至套接字失败。");
        return false;
    }
    //绑定失败输出错误信息并返回false
    return true;
}
/*
name: XYWin::XYSocket::bindSocket
function: 将地址与端口绑定至socket
parameter: SOCKET s,signed int af,u_short p,const char* ip s表示未绑定的socket，af表示socket协议簇，p表示端口，ip即地址
return: bool 成功绑定socket返回true，反之返回false
date: 2023-07-08 10:55:37
*/
bool XYWin::XYSocket::bindSocket(SOCKET sock,signed int af,u_short port,const char* ipAddress)
{
    sockaddr_in sin={};
    sin.sin_family=af;
    sin.sin_port=htons(port);
    sin.sin_addr.S_un.S_addr=inet_addr(ipAddress);
    //构建指向监听的地址和端口的sockaddr结构体
    return bindSocket(sock,(sockaddr*)&sin);
}
/*
name: XYWin::XYSocket::listenSocket
function: 监听已绑定未连接的socket
parameter: SOCKET s,int l s表示已绑定未连接的socket，l表示挂起等待队列的最大长度
return: bool 成功监听返回true，反之返回false
date: 2023-07-08 11:39:51
*/
bool XYWin::XYSocket::listenSocket(SOCKET sock,int maxPendingQueueLength)
{
    if(listen(sock,maxPendingQueueLength)==SOCKET_ERROR){
//如果设置为SOMAXCONN，则负责套接字的基础服务提供商会将积压工作设置为最大合理值。如果设置为SOMAXCONN_HINT(N) (其中 N 为数字)，积压工作值将为N，调整为(介于200、65535)范围内。SOMAXCONN_HINT可用于将积压工作设置为大于SOMAXCONN的值。
//        cout<<"ERROR: Failed to listen socket.(error code: "<<WSAGetLastError()<<')'<<endl;
//        cout<<"错误: 监听套接字失败。(错误码: "<<WSAGetLastError()<<')'<<endl;
        error=XYSerror(XYS_FAIL_LISTENSOCKET,WSAGetLastError(),"ERROR: Failed to listen socket.");
//        error=XYSerror(XYS_FAIL_LISTENSOCKET,WSAGetLastError(),"错误: 监听套接字失败。");
        return false;
    }
    //监听失败输出错误信息并返回false
    return true;
}
/*
name: XYWin::XYSocket::acceptClientSocket
function: 接受已监听的socket处连接
parameter: SOCKET s,sockaddr* addr,int* l s表示已监听的socket，addr表示接收连接地址端口的指针，l指向整数表示addr指向的结构长度
return: SOCKET 接受成功返回连接socket，失败返回INVALID_SOCKET
date: 2023-07-08 11:41:00
*/
SOCKET XYWin::XYSocket::acceptClientSocket(SOCKET sock,sockaddr* addr,int* addrLen)
{
    SOCKET clientSock=INVALID_SOCKET;
    clientSock=accept(sock,addr,addrLen);
    //将客户端信息绑定至clientSock
    if(clientSock==INVALID_SOCKET){
//        cout<<"ERROR: Failed to accept connection.(error code: "<<WSAGetLastError()<<')'<<endl;
//        cout<<"错误: 接受连接失败。(错误码: "<<WSAGetLastError()<<')'<<endl;
        error=XYSerror(XYS_FAIL_ACCEPTSOCKET,WSAGetLastError(),"ERROR: Failed to accept connection.");
//        error=XYSerror(XYS_FAIL_ACCEPTSOCKET,WSAGetLastError(),"错误: 接受连接失败。");
    }
    return clientSock;
}
/*
name: XYWin::XYSocket::acceptClientSocket
function: 接受已监听的socket处连接
parameter: SOCKET s s表示已监听的socket
return: SOCKET 接受成功返回连接socket，失败返回INVALID_SOCKET
date: 2023-07-08 10:55:57
*/
SOCKET XYWin::XYSocket::acceptClientSocket(SOCKET sock)
{
    sockaddr_in clientAddr={};
    int addrLen=sizeof(clientAddr);
    return acceptClientSocket(sock,(sockaddr*)&clientAddr,&addrLen);
}
/*
name: XYWin::XYSocket::connectServer
function: 连接至指定地址端口并将socket绑定至该连接
parameter: SOCKET s,const sockaddr* nam s表示无连接的socket，nam表示需连接的地址和端口的地址端口结构体指针
return: bool 连接成功返回true，反之返回false
date: 2023-07-08 11:41:59
*/
bool XYWin::XYSocket::connectServer(SOCKET sock,const sockaddr* nam)
{
    if(connect(sock,nam,sizeof(sockaddr))==SOCKET_ERROR){
//        cout<<"ERROR: Failed to connect to server.(error code: "<<WSAGetLastError()<<')'<<endl;
//        cout<<"错误: 连接到服务器失败。(错误码: "<<WSAGetLastError()<<')'<<endl;
        error=XYSerror(XYS_FAIL_CONNECTSOCKADDR,WSAGetLastError(),"ERROR: Failed to connect to server.");
//        error=XYSerror(XYS_FAIL_CONNECTSOCKADDR,WSAGetLastError(),"错误: 连接到服务器失败。");
        return false;
    }
    //建立连接失败则输出失败信息并返回false
    return true;
}
/*
name: XYWin::XYSocket::connectServer
function: 连接至指定地址端口并将socket绑定至该连接
parameter: SOCKET s,signed int af,u_short p,const char* ip s表示无连接的socket，af表示socket协议簇，p表示端口，ip表示地址
return: bool 连接成功返回true，反之返回false
date: 2023-07-08 10:56:13
*/
bool XYWin::XYSocket::connectServer(SOCKET sock,signed int af,u_short port,const char* ipAddress)
{
    sockaddr_in sin={};
    sin.sin_family=af;
    sin.sin_port=htons(port);
    sin.sin_addr.S_un.S_addr=inet_addr(ipAddress);
    //构建指向服务器的地址和端口的sockaddr结构体
    return connectServer(sock,(sockaddr*)&sin);
}
/*
name: XYWin::XYSocket::receive
function: 从有连接的socket接收数据
parameter: SOCKET s,char* buf,int l,int f s表示有连接的socket，buf指向可接收数据的空间，l表示意向接收长度(byte)，f表示接收模式
return: int 接收成功返回接收到的字节数，连接正常关闭返回0，否则返回SOCKET_ERROR
date: 2023-07-08 11:42:50
*/
int XYWin::XYSocket::receive(SOCKET sock,char* storageSpace,int length,int flags)
{
    int res=recv(sock,storageSpace,length,flags);
    if(res==SOCKET_ERROR){
//        cout<<"ERROR: Failed to receive Data.(error code: "<<WSAGetLastError()<<')'<<endl;
//        cout<<"错误: 接收数据失败。(错误码: "<<WSAGetLastError()<<')'<<endl;
        error=XYSerror(XYS_FAIL_RECEIVE,WSAGetLastError(),"ERROR: Failed to receive Data.");
//        error=XYSerror(XYS_FAIL_RECEIVE,WSAGetLastError(),"错误: 接收数据失败。");
    }
    return res;
    //参数四：0表示数据复制进空间后即从缓冲区删除 MSG_PPEK表示只复制不删除 MSG_OOB表示传输一段数据并外带一个额外的特殊数据 MSG_WAITALL表示直到缓冲区字节数满足length才开始读取
}
/*
name: XYWin::XYSocket::sendData
function: 向有连接的socket发送数据
parameter: SOCKET s,char* buf,int l,int f s表示有连接的socket，buf指向存储待发送数据的空间，l表示意向发送长度(byte)，f表示发送模式
return: int 发送成功返回发送了的字节数，否则返回SOCKET_ERROR
date: 2023-07-08 11:43:31
*/
int XYWin::XYSocket::sendData(SOCKET sock,char* storageSpace,int length,int flags)
{
    int res=send(sock,storageSpace,length,flags);
    if(res==SOCKET_ERROR){
//        cout<<"ERROR: Failed to send Data.(error code: "<<WSAGetLastError()<<')'<<endl;
//        cout<<"错误: 发送数据失败。(error code: "<<WSAGetLastError()<<')'<<endl;
        error=XYSerror(XYS_FAIL_SEND,WSAGetLastError(),"ERROR: Failed to send Data.");
//        error=XYSerror(XYS_FAIL_SEND,WSAGetLastError(),"错误: 发送数据失败。");
    }
    return res;
    //参数四：0表示正常发送 MSG_OOB表示传输一段数据并外带一个额外的特殊数据 MSG_DONTROUTE表示指定数据不受路由限制
}