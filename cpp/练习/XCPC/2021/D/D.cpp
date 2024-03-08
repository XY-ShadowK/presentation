#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
long long t,x,g,f1,f2;
inline bool prime(long long num)
{
	if(num==2)return true;
	if(!(num%2))return false;
	for(long long i=2;i<sqrt(num);i++)if(num%i==0)return false;
	return true;
}
inline long long function(long long xx)
{
	xx++;
	while(1){
		if(prime(xx))break;
		xx++;
	}
	return xx;
}
int main()
{
	cin>>t;
	while(t--){
		cin>>x;
		f1=function(x);
		f2=function(f1);
		g=(f1+f2)/2;
		if(prime(g))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
