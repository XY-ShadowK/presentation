#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
long long a,b,tf,ans;
string ct;
int main()
{
	srand(time(NULL));
	while(1){
		a=rand()%100;
		b=rand()%100;
		tf=rand()%2;
		switch(tf){
			case 0 : {
				cout<<"�����"<<max(a,b)<<"��"<<min(a,b)<<endl;
				cin>>ans;
				if(ans==abs(a-b))cout<<"��ȫ��ȷ��"<<endl;
				else cout<<"û�����ԣ�����Ŭ����"<<endl;
				break;
			}
			case 1 : {
				cout<<"�����"<<a<<"��"<<b<<endl;
				cin>>ans;
				if(ans==(a+b))cout<<"��ȫ��ȷ��"<<endl;
				else cout<<"û�����ԣ�����Ŭ����"<<endl;
				break;
			}
		}
		cout<<"�Ƿ�������⣿������Yes��No��[Yes(��)/No(��)]"<<endl;
		cin>>ct;
		if(ct=="No"){
			system("cls");
			break;
		}
		else system("cls");
	}
	return 0;
}
