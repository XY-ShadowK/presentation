#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main()
{
	// ����Windows socket2 ����
	//��ʼ���׽���
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);

	//1 ����һ��socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sock)
	{
		cout << "���󣬽���socketʧ��" << endl;
	}
	else
	{
		cout << "����socket�ɹ�.." << endl;
	}
	//2 ���ӷ�����
	sockaddr_in sin = {};
	sin.sin_family = AF_INET;
	sin.sin_port = htons(4567);
	sin.sin_addr.S_un.S_addr = inet_addr("192.168.0.188");
	if (SOCKET_ERROR == connect(sock, (sockaddr*)&sin, sizeof(sockaddr_in)))
	{
		cout << "��������ʧ��..." << endl;
	}
	else {
		cout << "�������ӳɹ�..." << endl;
	}
    unsigned long argp=1;
    ioctlsocket(sock,FIONBIO,&argp);
	//3 ���շ�������Ϣ
	char recvBuf[256] = {};
	while(true){
		cout<<"before recv"<<endl;
		int nlen = recv(sock, recvBuf, 256, 0);
		cout<<nlen<<endl;
		if (nlen > 0)
		{
			cout<<"receive!"<<endl;
			cout << "���ܵ����ݣ�" << recvBuf << endl;
			system("PAUSE");
		}
		else cout<<"receive error! "<<WSAGetLastError()<<endl;
	}
	//4 �ر��׽���closesocket
	closesocket(sock);
	getchar();
	//���Windows socket����
	WSACleanup();
}
