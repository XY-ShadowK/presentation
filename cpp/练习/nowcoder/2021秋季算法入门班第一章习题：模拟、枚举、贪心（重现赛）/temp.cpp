#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int p1,p2,p3,l;
string str,voc[4]={"abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ","0123456789","******************************"};
void prt(int s,int t,int d)
{
	if(p1==2)d=1;
	else if(p1==3)d=3;
	if(p3==1)for(int i=s+1;i<t;i++)for(int j=0;j<p2;j++)cout<<voc[d][i];
	else for(int i=t-1;i>s;i--)for(int j=0;j<p2;j++)cout<<voc[d][i];
}
void print(char h,char e)
{
	if(h>='0'&&h<='9'&&e>='0'&&e<='9')prt(h-'0',e-'0',2);
	if(h>='a'&&h<='z'&&h>='a'&&h<='z')prt(h-'a',e-'a',0);
	return;
}
int main()
{
	cin>>p1>>p2>>p3>>str;
	l=str.size();
	for(int i=0;i<l;i++){
		if(str[i]=='-'&&str[i+1]>str[i-1])print(str[i-1],str[i+1]);
		else cout<<str[i];
	}
	return 0;
}
