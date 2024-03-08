#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long t,n,temp,ans=0;
inline long long fc(long long num)
{
	long long tans=0;
	while(num){
		if(num&1)return tans;
		num=num>>1;
		tans++;
	}
	return tans;
}
int main()
{
	cin>>n;
	for(long long i=0;i<n;i++){
		scanf("%lld",&t);
		ans+=fc(t);
	}
	cout<<ans;
	return 0;
}
