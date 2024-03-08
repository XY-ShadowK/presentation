#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct tPoker{
	int a,b,num;
};
int n,k,q,ct[100005];
tPoker sj[200010];
bool used[100005];
bool cmp(tPoker aa,tPoker bb)
{
	if(aa.a<bb.a)return true;
	if(aa.a==bb.a)return aa.b>bb.b;
	return false;
}
bool can(int ll,int rr,int now)
{
	if(rr-ll+1>k)return false;
	if(now==rr)return true;
	bool pd=false;
	for(int i=ct[now-1]+1;i<=ct[now];i++){
		if(!used[sj[i].num]){
			used[sj[i].num]=true;
			pd=can(ll,rr,now+1);
			used[sj[i].num]=false;
			if(pd)return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&k);
	int p=1,l,r;
	for(int i=1;i<=2*k;i+=2){
		scanf("%d%d",&sj[i].a,&sj[i].b);
		sj[i+1].b=sj[i].a;
		sj[i+1].a=sj[i].b;
		sj[i].num=p;
		sj[i+1].num=p;
		ct[p]++;
		p++;
	}
	sort(sj+1,sj+2*k+1,cmp);
	for(int i=2;i<=k;i++)ct[i]+=ct[i-1];
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&l,&r);
		if(can(l,r,l))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
