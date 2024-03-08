#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
typedef struct tChocolate
{
	long long morning,night,mdn;
}ccl;
int n,k;
long long ans=0;
ccl tc[100005];
inline bool cmp(ccl aa,ccl bb)
{
	return aa.mdn>bb.mdn;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%lld",&tc[i].morning);
	for(int i=1;i<=n;i++){
		scanf("%lld",&tc[i].night);
		tc[i].mdn=tc[i].morning-tc[i].night;
	}
	sort(tc+1,tc+n+1,cmp);
	for(int i=1;i<=k;i++)ans+=tc[i].morning;
	for(int i=k+1;i<=n;i++)ans+=tc[i].night;
	cout<<ans;
	return 0;
}
