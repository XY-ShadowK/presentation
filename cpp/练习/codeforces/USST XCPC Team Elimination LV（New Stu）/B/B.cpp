#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
long long xr,yr,xw,yw;
void pre()
{
	long long d12=xr*xr+yr*yr,d22=xw*xw+yw*yw;
	if(d12<d22){
		cout<<"Russo"<<endl;
		return;
	}
	if(d12==d22){
		cout<<"Empate"<<endl;
		return;
	}
	if(d12>d22){
		cout<<"Wil"<<endl;
		return;
	}
}
int main()
{
	cin>>xr>>yr>>xw>>yw;
	pre();
	return 0;
}
