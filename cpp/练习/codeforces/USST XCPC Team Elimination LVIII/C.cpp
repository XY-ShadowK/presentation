#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
string str;
long long l=0,p=0,len;
int main()
{
	cin>>str;
	len=str.size();
	for(int i=0;i<len;i++)if(str[i]=='L'&&str[i+1]=='S'&&str[i+2]=='C'){
		l++;
		i+=2;
	}
	for(int i=0;i<len;i++)if(str[i]=='P'&&str[i+1]=='C'&&str[i+2]=='M'&&str[i+3]=='S'){
		p++;
		i+=3;
	}
	if(l>p)cout<<"LSC";
	if(l<p)cout<<"PCMS";
	if(l==p)cout<<"Tie";
	return 0;
}
