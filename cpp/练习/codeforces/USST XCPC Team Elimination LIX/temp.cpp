#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
long long l,r,n,k,a[100005],mid;
vector<long long> ans;
inline bool check(long long num)
{
	long long last=-1e18-1,cnt=0;
	ans.clear();
	for(long long i=0;i<n;i++)if(a[i]-last>=num){
		ans.push_back(a[i]);
		last=a[i];
		cnt++;
		if(cnt>=k)return true;
	}
	return cnt>=k;
}
int main()
{
	cin>>n>>k;
	for(long long i=0;i<n;i++)scanf("%lld",a+i);
	sort(a,a+n);
	l=0;
	r=1e18;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	check(l);
	for(long long i=0;i<k;i++)printf("%lld ",ans[i]);
	return 0;
}
