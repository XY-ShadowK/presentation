#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long n,t,a,b,f[10000005];
inline void hj(long long num)
{
	if(num<0){
		cout<<-1<<endl;
		return;
	}
	long long k=sqrt(num);
	for(long long i=k+1;i>0;i--)if(!(b%f[i])){
		a*=i,b/=f[i];
		break;
	}
	cout<<a<<' '<<b<<endl;
	return;
}
int main()
{
	cin>>t;
	long long k=sqrt(10000005);
	for(long long i=1;i<=k+1;i++)f[i]=i*i;
	while(t--){
		cin>>n;
		a=1;
		b=n;
		hj(n);
	}
	return 0;
}
