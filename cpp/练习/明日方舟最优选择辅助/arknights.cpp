#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream fin("data.dat");
ofstream fout("运行日志.txt",ios::app);
string version,data[100],chosen[100],ans,DOW[8]={"0","星期一","星期二","星期三","星期四","星期五","星期六","星期日"};
double checkpoint[10][30],checkpoint_s[10][30];
int num,choice,addition[10][30],addition_s[10][30];
SYSTEMTIME sys;
template <class Type>
Type stringTotype(const string& str)
{
	istringstream iss(str);
	Type n;
	iss>>n;
	return n;
}
string intTostring(const int& nt)
{
	ostringstream stream;
	stream<<nt;
	return stream.str();
}
void reset()
{
	system("cls");
	cout<<"ps:要关直接X掉就可以了，原谅我不会做窗体"<<endl<<"欢迎使用明日方舟优化选择辅助，当前版本"<<version<<endl;
	return;
}
void OutTime()
{
	GetLocalTime(&sys);
	fout<<'['<<sys.wYear<<'/'<<sys.wMonth<<'/'<<sys.wDay<<'|'<<DOW[sys.wDayOfWeek]<<']'<<sys.wHour<<':'<<sys.wMinute<<':'<<sys.wSecond<<endl;
	return;
}
void addweight(string t_str,double w,bool s)
{
	string chapter,cp;
	int mid=t_str.find('-');
	chapter=t_str.substr(0,mid);
	cp=t_str.substr(mid+1,t_str.size()-mid-1);
	checkpoint_s[stringTotype<int>(chapter)][stringTotype<int>(cp)]+=w;
	addition_s[stringTotype<int>(chapter)][stringTotype<int>(cp)]++;
	return;
}
void addweight(string t_str,double w)
{
	string chapter,cp;
	int mid=t_str.find('-');
	chapter=t_str.substr(0,mid);
	cp=t_str.substr(mid+1,t_str.size()-mid-1);
	checkpoint[stringTotype<int>(chapter)][stringTotype<int>(cp)]+=w;
	addition[stringTotype<int>(chapter)][stringTotype<int>(cp)]++;
	return;
}
void getans()
{
	double minn=999999;
	for(int i=0;i<10;i++){
		for(int j=0;j<30;j++){
			if(minn>checkpoint[i][j]&&checkpoint[i][j]&&addition[i][j]==choice){
				minn=checkpoint[i][j];
				ans=intTostring(i)+'-'+intTostring(j);
			}
			if(minn>checkpoint_s[i][j]&&checkpoint_s[i][j]&&addition_s[i][j]==choice){
				minn=checkpoint_s[i][j];
				ans='S'+intTostring(i)+'-'+intTostring(j);
			}
		}
	}
	return;
}
void choose_materials_class()
{
	reset();
	int i,t,direction[20],tt,mt;
	string::size_type position=0;
	double weight,tw;
	string st,sw;
	cout<<"请选择材料大类："<<endl;
	for(i=1;i<=num;i++)cout<<i<<data[i].substr(0,data[i].find('#'))<<endl;
	cin>>t;
	i=0;
	while((position=data[t].find('#',position))!=string::npos){
		direction[++i]=++position;
		cout<<i<<'.'<<data[t].substr(position,data[t].find('^',position)-position)<<endl;
	}
	direction[++i]=1000;
	cin>>tt;
	chosen[choice++]=data[t].substr(direction[tt],data[t].find('^',direction[tt])-direction[tt]);
	cout<<"您已选择 "<<chosen[choice-1]<<" ,请加权"<<endl<<"(0~1内小数,0为不加权,1为不考虑该材料)"<<endl;
	cin>>weight;
	position=direction[tt];
	while((position=data[t].find('^',position))!=string::npos&&position<direction[tt+1]){
		mt=data[t].find('$',++position);
		st=data[t].substr(position,mt-position);
		sw=data[t].substr(mt+1,data[t].find('@',mt)-mt-1);
		tw=(1.00-weight)*stringTotype<double>(sw);
		if(st.find('*')!=string::npos)st=st.substr(0,st.find('*'));
		if(st[0]=='S')addweight(st.substr(1,st.size()-1),tw,true);
		else addweight(st,tw);
	}
	return;
}
int main()
{
	int temp;
	char yn;
	OutTime();
	fout<<"正在打开辅助,读取数据"<<endl;
	fin>>version;
	while(fin>>data[++num]);
	OutTime();
	fout<<"读取数据成功，正在进入主菜单"<<endl;
	num--;
	reset();
	OutTime();
	fout<<"进入主菜单成功"<<endl;
	cout<<"请选择功能："<<endl;
	cout<<"1.打材料优化关卡选择"<<endl;
	cin>>temp;
	switch(temp){
		case 1 : {
			OutTime();
			fout<<"进入功能 打材料优化关卡选择"<<endl;
			do{
				system("PAUSE");
				choose_materials_class();
				OutTime();
				fout<<"选择了材料 "<<chosen[choice-1]<<endl;
				cout<<"是否继续选择材料？(Y/N)"<<endl;
				cin>>yn;
			}
			while(yn=='Y');
			OutTime();
			fout<<"正在进行计算"<<endl;
			getans();
			OutTime();
			fout<<"计算完成"<<endl;
			cout<<"您选择了 ";
			for(int i=0;i<choice;i++)cout<<chosen[i]<<' ';
			cout<<"根据您对材料的加权，最佳方案是 ";
			if(ans.empty())cout<<"不存在同时刷取的方案，您可以尝试欧皇特殊掉落。"<<endl;
			else cout<<ans<<endl;
			OutTime();
			fout<<"程序结束"<<endl;
			break;
		}
	}
	system("PAUSE");
	return 0;
}
