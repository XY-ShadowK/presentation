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
ofstream fout("运行日志.txt");
string version;
double checkpoint[10][30],checkpoint_s[10][30];
void reset()
{
	system("cls");
	cout<<"ps:要关直接X掉就可以了，原谅我不会做窗体"<<endl<<"欢迎使用明日方舟优化选择辅助，当前版本"<<version<<endl;
	return;
}
void choose_materials_class()
{
	reset();
	cout<<"请选择材料大类：";
}
int main()
{
	int temp;
	fin>>version;
	reset();
	cout<<"请选择功能："<<endl;
	cout<<"1.打材料优化关卡选择"<<endl;
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
