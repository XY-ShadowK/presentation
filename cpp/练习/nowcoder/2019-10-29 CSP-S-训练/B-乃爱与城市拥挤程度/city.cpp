#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct tCity{
	int s,e;
};
int n,k,ct[100005],start;
long long cj[100005];
tCity l[200005];
const int M=1000000007;
bool used[100005];
bool cmp(tCity a,tCity b)
{
	return a.s<b.s;
}
int dfs(int num,int cs)
{
	if(cs>k)return 0;
	used[num]=true;
	long long ans=1;
	for(int i=ct[num-1]+1;i<=ct[num];i++){
		if(used[l[i].e])continue;
		ans+=dfs(l[i].e,cs+1);
	}
	cj[start]=(cj[start]*(ans%M))%M;
	used[num]=false;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=2*n-2;i+=2){
		scanf("%d%d",&l[i].s,&l[i].e);
		l[i+1].e=l[i].s;
		l[i+1].s=l[i].e;
		ct[l[i].s]++;
		ct[l[i].e]++;
	}
	sort(l+1,l+2*n-1,cmp);
	for(int i=2;i<=n;i++)ct[i]+=ct[i-1];
	for(int i=1;i<=n;i++){
		cj[i]=1;
		start=i;
		printf("%d ",dfs(i,0));
	}
	printf("\n");
	for(int i=1;i<=n;i++)printf("%d ",cj[i]);
	return 0;
}
