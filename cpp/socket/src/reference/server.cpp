#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <thread>
#include <vector>
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

	// У��汾
	if (2 != HIBYTE(dat.wVersion) || 2 != LOBYTE(dat.wVersion))
	{
		// �汾����
		WSACleanup();
		return 0;
	}

	//1 ����һ��socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in sin = {};
	sin.sin_family = AF_INET;
	sin.sin_port = htons(4567);
	sin.sin_addr.S_un.S_addr = inet_addr("192.168.0.188");
	
	//2 bind �����ڽ��ܿͻ������ӵ�����˿�
	if (SOCKET_ERROR == bind(sock, (sockaddr*)&sin, sizeof(sin)))
	{
		cout << "������˿�ʧ��" << endl;
	}
	else {
		cout << "������˿ڳɹ�" << endl;
	}
	//3. listen��������˿�
	if (SOCKET_ERROR == listen(sock, 5))
	{
		cout << "��������˿�ʧ��" << endl;
	}
	else {
		cout << "��������˿ڳɹ�" << endl;
	}

	//4 accept �ȴ��ͻ�������
	sockaddr_in clientAddr = {};
	int nAddrLen = sizeof(sockaddr_in);
	SOCKET cSock = INVALID_SOCKET;
	string msg = "Hello, I'm Server";
	cSock = accept(sock, (sockaddr*)&clientAddr, &nAddrLen);
	if (INVALID_SOCKET == cSock)
	{
		cout << "���󣬽��ܵ���Ч�ͻ���SOCKET..." << endl;
	}
	cout << "�¿ͻ��˼��룺" << inet_ntoa(clientAddr.sin_addr) << endl;
    unsigned long argp=1;
    ioctlsocket(cSock,FIONBIO,&argp);
	//5 send ��ͻ��˷�������
	char recvBuf[128] = {};
	while (true)
	{
		cout<<"before send"<<endl;
		cout<<send(cSock, msg.c_str(), msg.length(), 0)<<endl;
		cout<<"after send"<<endl;
		int nlen = recv(cSock, recvBuf, 128, 0);
		if (nlen <= 0)
		{
			cout << "�ͻ����˳�..." << endl;
			system("PAUSE");
			break;
		}
	}
	

	//6 �ر��׽���closesocket
	closesocket(sock);
	//���Windows socket����
	WSACleanup();
}
