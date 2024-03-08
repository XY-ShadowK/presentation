#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
const long long MO=1000000007,M=1000005;
long long n,m,t,ans,jci[M],inv[M];
inline long long q_pow(long long a,long long b,long long p)
{
	long long res=1;
	while(b){
		if(b&1)res=(res*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return res;
}
inline long long inverse(long long a,long long p)
{
	return q_pow(a,p-2,p);
}
int main()
{
	scanf("%ld",&t);
	jci[0]=1;
	for(register long long i=1;i<=M;i++){
		jci[i]=(jci[i-1]*i)%MO;
		inv[i]=(inverse(jci[i],MO)%MO+inv[i-1])%MO;
	}
	while(t--){
		scanf("%ld%ld",&n,&m);
		ans=((((jci[m]*jci[n-m])%MO)*n)%MO-(jci[m]*inv[m-1])%MO+MO)%MO;
		printf("%ld\n",ans);
	}
	return 0;
}
