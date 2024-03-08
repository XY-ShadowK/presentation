#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include "./include/XYSocket.hpp"
#include "./include/XYINI.hpp"
#pragma comment(lib,"./src/lib/XYSocket.lib")
#pragma comment(lib,"./src/lib/XYINI.lib")

using XYWin::XYSocket::XYSerror;
using XYWin::XYSocket::openNetLib;
using XYWin::XYSocket::XYSGetLastError;
using XYWin::XYSocket::buildSocket;
using XYWin::XYSocket::unblockSocket;
using XYWin::XYSocket::bindSocket;
using XYWin::XYSocket::listenSocket;
using XYWin::XYSocket::acceptClientSocket;
using XYWin::XYSocket::receive;
using XYWin::XYSocket::sendData;

using XYWin::ini;
using XYWin::convertCString;

using std::cout;
using std::cin;
using std::endl;

int main()
{
    ini iniServer(convertCString("./settings"),convertCString("server.ini"));
    cout<<iniServer.getValueInt(convertCString("server"),convertCString("port"),0)<<endl;
    openNetLib(2,2);
    SOCKET sock=buildSocket(AF_INET,SOCK_STREAM,IPPROTO_TCP),clientSock;
    bindSocket(sock,AF_INET,4567,"192.168.0.188");
    listenSocket(sock,5);
    clientSock=acceptClientSocket(sock);
    char receiveSpace[128]={},msg[]="Hello!";
    unblockSocket(clientSock);
    while(true){
        sendData(clientSock,msg,7,0);
        if(receive(clientSock,receiveSpace,128,0)<=0){
            cout<<"Client offline!"<<endl;
            Sleep(100);
        }
        cout<<"receive: "<<receiveSpace<<endl;
    }
    closesocket(sock);
    WSACleanup();
    return 0;
}
