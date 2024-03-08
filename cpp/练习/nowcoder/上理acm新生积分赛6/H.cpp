#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
using namespace std;
int n,x,y;
long long ans=0,num[100005],sum[100005];
inline bool cmp(int aa,int bb)
{
	return aa>bb;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",num+i);
	cin>>x>>y;
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+num[i];
	for(int i=1;i<=x;i++)for(int j=1;j<=y;j++)ans+=sum[i*j];
	cout<<ans;
	return 0;
}
