#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;
ifstream fin("data.dat");
ofstream fout("������־.txt");
string version;
double checkpoint[10][30],checkpoint_s[10][30];
void reset()
{
	system("cls");
	cout<<"ps:Ҫ��ֱ��X���Ϳ����ˣ�ԭ���Ҳ���������"<<endl<<"��ӭʹ�����շ����Ż�ѡ��������ǰ�汾"<<version<<endl;
	return;
}
void choose_materials_class()
{
	reset();
	cout<<"��ѡ����ϴ��ࣺ";
}
int main()
{
	int temp;
	fin>>version;
	reset();
	cout<<"��ѡ���ܣ�"<<endl;
	cout<<"1.������Ż��ؿ�ѡ��"<<endl;
	cin>>temp;
	switch(temp){
		case 1 : {
			system("PAUSE");
			choose_materials_class();
			break;
		}
	}
	return 0;
}
