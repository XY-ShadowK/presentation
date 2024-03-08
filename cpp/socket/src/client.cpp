#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include "./include/XYSocket.hpp"
#pragma comment(lib,"./src/lib/XYSocket.lib")
using XYWin::XYSocket::XYSerror;
using XYWin::XYSocket::openNetLib;
using XYWin::XYSocket::XYSGetLastError;
using XYWin::XYSocket::buildSocket;
using XYWin::XYSocket::unblockSocket;
using XYWin::XYSocket::connectServer;
using XYWin::XYSocket::receive;
using std::cout;
using std::cin;
using std::endl;
int main()
{
    openNetLib(2,2);
    SOCKET sock=buildSocket(AF_INET,SOCK_STREAM,0);
    connectServer(sock,AF_INET,4567,"192.168.0.188");
    unblockSocket(sock);
    char receiveSpace[256]={};
    int i;
    char ch;
    while(true){
        for(i=0;i<10;i++)
            if(receive(sock,receiveSpace,256,0)>0)
                cout<<"Received Data: "<<receiveSpace<<endl;
        if(i==10){
            cout<<"Server offline, try again? (Y/N)"<<endl;
            cin>>ch;
            if(ch=='N')break;
        }
    }
    closesocket(sock);
    WSACleanup();
    return 0;
}
