#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define F(xx) xx*xx+xx+41
using namespace std;
typedef struct tFT{
	int l,r,len;
	long long cost;
}ft;
ft lp[200005],rp[200005];
int n,x;
long long ans=2.1e9,minn[200005];
bool cmp1(ft aa,ft bb){return aa.l<bb.l;}
bool cmp2(ft aa,ft bb){return aa.r<bb.r;}
int main()
{
	cin>>n>>x;
	for(int i=0;i<n;i++){
		scanf("%d%d%lld",&lp[i].l,&lp[i].r,&lp[i].cost);
		lp[i].len=lp[i].r-lp[i].l+1;
		rp[i].len=lp[i].len;
		rp[i].l=lp[i].l;
		rp[i].r=lp[i].r;
		rp[i].cost=lp[i].cost;
	}
	sort(lp,lp+n,cmp1);
	sort(rp,rp+n,cmp2);
	fill(minn,minn+200005,ans);
	for(int i=0,j=0;i<n;i++)if(x>lp[i].len){
		for(;j<n;j++){
			if(lp[i].l>rp[j].r)minn[rp[j].len]=min(minn[rp[j].len],rp[j].cost);
			else break;
		}
		ans=min((unsigned)ans,(unsigned)(minn[x-lp[i].len]+lp[i].cost));
	}
/*	for(int i=0;i<n;i++)if(x>lp[i].len)for(int j=0;j<n;j++){
		if(lp[i].l<=rp[j].r)break;
		if(lp[i].len+rp[j].len==x)ans=min(ans,lp[i].cost+rp[j].cost);
	}*/
	cout<<(ans<2.1e9?ans:-1);
	return 0;
}
