#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
ifstream fin("password.in");
ofstream fout("password.out");
string de_pw(string temp)
{
	int sz=temp.size(),i,pd=0,dl=-1,dr=-1,l=-1,r=-1;
	int a=1;
	string tmp,p;
	for(i=0;i<sz;i++){
		if(temp[i]=='['){
			if(pd==0){
				a=(int)temp[i+1]-'0';
				dl=i;
				l=i+2;
			}
			pd++;
			i+=2; 
		}
		if(temp[i]==']'){
			pd--;
			if(pd==0){
				dr=i;
				r=i-1;
			}
		}
		if(pd==0&&dl!=-1&&dr!=-1){
			tmp.clear();
			p.clear(); 
			tmp=temp.substr(l,r-l+1);
			tmp=de_pw(tmp);
			p=tmp;
			for(int j=1;j<a;j++){
				p+=tmp;
			}
			temp.replace(dl,dr-dl+1,p);
			i=i-dr+dl-1+p.size();
			sz=sz-dr+dl-1+p.size();
			dl=-1;
			dr=-1;
			l=-1;
			r=-1;
			pd=0;
		}
	}
	return temp;
}/*
string de_pw(string temp)
{
	int i,dr=-1,dl=-1,r,l,sz=temp.size(),pd=0;
	int a;
	string tmp,t;
	for(i=0;i<sz;i++){
		if(pd==0&&dr!=-1&&dl!=-1){
			tmp=temp.substr(l,r-l+1);
			tmp=de_pw(tmp);
			t=tmp;
			for(int j=1;j<a;j++){
				tmp=tmp+t;
			}
			temp.replace(dl,dr-dl+1,tmp);
			i=i-(dr-dl+1)+tmp.size();
			sz=sz-(dr-dl+1)+tmp.size();
			dl=-1;
			dr=-1;
			l=-1;
			r=-1;
		}
		if(temp[i]=='['){
			if(pd==0){
				dl=i;
				a=(int)temp[i+1]-'0';
				l=i+2;
			}
			pd++;
			i+=2;
		}
		if(temp[i]==']'){
			pd--;
			if(pd==0){
				dr=i;
				r=i-1;
			}
		}
	}
	return temp;
}*/
int main()
{
	string U;
	cin>>U;
	cout<<de_pw(U);
	return 0;
}
