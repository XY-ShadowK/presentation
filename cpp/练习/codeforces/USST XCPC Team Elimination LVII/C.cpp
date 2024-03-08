#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,ans=0,a[200005],b[50],temp=0;
inline bool check(long long k)
{
	for(long long i=0;i<=30;i++)if(k==b[i])return true;
	return false;
}
inline void gcd()
{
	long long k=__gcd(a[1],a[2]);
	for(long long i=3;i<=n;i++)k=__gcd(k,a[i]);
	if(k-1)for(long long i=1;i<=n;i++)a[i]/=k;
	return;
}
int main()
{
	b[0]=1;
	for(long long i=1;i<=30;i++)b[i]=b[i-1]<<1;
	cin>>n;
	for(long long i=1;i<=n;i++)scanf("%lld",a+i);
	gcd();
	for(long long i=1;i<=n;i++){
			if(!check(a[i])){
			cout<<-1;
			return 0;
		}
		temp+=a[i];
	}
	if(check(temp)){
		cout<<0;
		return 0;
	}
	while(temp){
		if(temp&1)break;
		temp=temp>>1;
	}
	while(temp){
		if(!(temp&1))ans++;
		temp=temp>>1;
	}
	cout<<ans+1;
	return 0;
}
