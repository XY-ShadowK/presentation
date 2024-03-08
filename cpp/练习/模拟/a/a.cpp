#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
int main()
{
	string x;
//	cin>>x;
	fin>>x;
	int i,temp=0;
	for(i=0;i<x.size();i++){
		temp+=(((int)(x[i]-'0'))%7)*10;
		temp=temp%7;
	}
//	cout<<temp<<endl;
	fout<<temp<<endl;
	return 0;
}
