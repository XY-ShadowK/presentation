#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <string>
using namespace std;
ofstream fout("data.dat");
string material_series,t2,t3;
int main()
{
	double t1;
	int t;
	cout<<"��ӭʹ�����շ����Ż�ѡ����ר������������"<<endl;
	cout<<"�����븨���汾��";
	cin>>t1;
	fout<<t1<<endl;
	while(1){
		system("cls");
		cout<<"��Ӳ���ϵ�У�";
		cin>>t2;
		material_series="."+t2;
		while(1){
			cout<<"���ϵ���ڲ��ϣ�(����back�����ϼ��˵�)";
			cin>>t2;
			if(t2=="back")break;
			material_series+="#"+t2;
			while(1){
				cout<<"��Ӳ��� "<<t2<<" ��ȡ�ؿ���ƽ����ȡ����(��һ���ո����)"<<endl;
				cin>>t3;
				material_series+="^"+t3;
				cin>>t3;
				material_series+="$"+t3+"@";
				cout<<"1.������ӹؿ�"<<endl<<"2.������Ӳ����б�"<<endl;
				cin>>t;
				system("cls");
				if(t==2)break;
			}
		}
		fout<<material_series<<endl;
		cout<<"����ϵ����ӳɹ����Ƿ������(Y/N)"<<endl;
		cin>>t3;
		if(t3=="N")break;
	}
	return 0;
} 
