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
	cout<<"欢迎使用明日方舟优化选择辅助专属数据生成器"<<endl;
	cout<<"请输入辅助版本：";
	cin>>t1;
	fout<<t1<<endl;
	while(1){
		system("cls");
		cout<<"添加材料系列：";
		cin>>t2;
		material_series="."+t2;
		while(1){
			cout<<"添加系列内材料：(输入back返回上级菜单)";
			cin>>t2;
			if(t2=="back")break;
			material_series+="#"+t2;
			while(1){
				cout<<"添加材料 "<<t2<<" 获取关卡及平均获取理智(以一个空格隔开)"<<endl;
				cin>>t3;
				material_series+="^"+t3;
				cin>>t3;
				material_series+="$"+t3+"@";
				cout<<"1.继续添加关卡"<<endl<<"2.返回添加材料列表"<<endl;
				cin>>t;
				system("cls");
				if(t==2)break;
			}
		}
		fout<<material_series<<endl;
		cout<<"材料系列添加成功，是否继续？(Y/N)"<<endl;
		cin>>t3;
		if(t3=="N")break;
	}
	return 0;
} 
