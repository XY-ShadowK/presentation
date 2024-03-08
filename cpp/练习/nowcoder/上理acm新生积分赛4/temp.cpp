#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long n,ancestor[1000005],sum[1000005]={0},t1,t2,ans=0;
long long find(long long num)
{
	return (num==ancestor[num]?num:ancestor[num]=find(ancestor[num]));
}
inline void treebuild(long long t1,long long t2)
{
	ancestor[find(t1)]=find(t2);
	return;
}
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)ancestor[i]=i;
	for(long long i=1;i<n;i++){
		scanf("%lld%lld",&t1,&t2);
		if(t1!=1&&t2!=1)treebuild(t1,t2);
	}
	for(long long i=1;i<=n;i++)sum[find(i)]++;
	sort(sum+1,sum+n+1);
	cout<<sum[n];
	return 0;
}
