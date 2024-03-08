#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long a,b,x,y,wmax,wmin,temp;
int main()
{
	cin>>a>>b>>x>>y;
	temp=__gcd(x,y);
	x/=temp;
	y/=temp;/*
	if(x>a||y>b){
		cout<<0;
		return 0;
	}
	temp=a/x;
	for(long long i=temp;i>0;i--)if(i*y<=b){
		wmax=i;
		break;
	}
	for(long long i=1;i<=wmax;i++)if(i*y>=1&&i*y<=b){
		wmin=i;
		break;
	}*/
	cout<<min(a/x,b/y);
	return 0;
}
