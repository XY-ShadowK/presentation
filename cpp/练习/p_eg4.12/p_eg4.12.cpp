#include <iostream>
using namespace std;
void t1(){cout<<"SOVIET LAND Y P A !"<<endl;}
void t2(){cout<<"STALIN Y P A !"<<endl;}
void t3(){cout<<"YURI.A Y P A !"<<endl;}
void t4(){cout<<"SOCIALISM AND COMMUNITISM Y P A !"<<endl;}
typedef void (*SUPER_SOVIET)();
int main()
{
	SUPER_SOVIET soviet[]={t1,t2,t3,t4};
	int n;
	cin>>n;
	soviet[n]();
	return 0;
} 
