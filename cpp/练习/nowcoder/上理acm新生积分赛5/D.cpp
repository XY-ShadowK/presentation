#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
using namespace std;
int t,n,temp,ans=0,num[1000005],cnt=0,maxn=0;
bitset<1000000005> bs;
int main()
{
	cin>>n;
	bs.reset();
	for(long long i=1;i<=n;i++){
		scanf("%d",num+i);
		while(bs[num[i]]){
			maxn=max(ans,maxn);
			ans--;
			bs[num[++cnt]]=0;
		}
		ans++;
		bs[num[i]]=1;
	}
	cout<<max(ans,maxn);
	return 0;
}
