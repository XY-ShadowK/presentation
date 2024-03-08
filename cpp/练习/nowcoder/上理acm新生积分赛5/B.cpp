#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long t,n,temp;
inline long long fc(long long num)
{
	long long ans=0;
	while(num){
		if(num&1)ans++;
		num=num>>1;
	}
	return ans;
}
inline long long min_n(long long num)
{
	long long ans=0;
	for(long long i=0;i<num;i++)ans=(ans+1)<<1;
	ans=ans>>1;
	return ans;
}
int main()
{
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		temp=fc(n);
		printf("%lld %lld\n",temp,min_n(temp));
	}
	return 0;
}
