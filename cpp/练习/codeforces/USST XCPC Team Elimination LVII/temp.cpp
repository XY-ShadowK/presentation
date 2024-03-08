#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
long long l[200005],r[200005],f[200005],d[200005],n,h,temp,ans=0;
int main()
{
	cin>>n>>h;
	for(long long i=1;i<=n;i++)scanf("%lld%lld",l+i,r+i);
	f[1]=r[1]-l[1];
	d[1]=0;
	for(long long i=2;i<=n;i++){
		f[i]=f[i-1]+r[i]-l[i];
		d[i]=d[i-1]+l[i]-r[i-1];
	}
	for(long long i=1;i<=n;i++){
		temp=lower_bound(d+1,d+n+1,d[i]+h)-d;
		ans=max(ans,f[temp-1]-f[i-1]+h);
	}
	cout<<ans;
	return 0;
}
