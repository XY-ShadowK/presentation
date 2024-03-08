#include<bits/stdc++.h>
#define F(i,n,m) for(int i=n;i<=m;i++)
#define ll long long
#define shit_CCF freopen("apple.in","r",stdin);freopen("apple.out","w",stdout);
#define FUCK_CCF fclose(stdin);fclose(stdout);return 0;
using namespace std;
int fa[1000001],n,m,cnt,ans,z;
struct node{
	int start,to;ll v;
}a[1000001];
bool cmp1(node x,node y){return x.v<y.v;}
bool cmp2(node x,node y){return x.v>y.v;}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool kruskal(int z)
{
	if(z==1)
	sort(a+1,a+m+1,cmp1);
	else
	sort(a+1,a+1+m,cmp2);
	F(i,1,m)
	{
		int u=find(a[i].start),v=find(a[i].to);
		if(u==v) continue;
		ans+=a[i].v;
		fa[u]=v;
		if(++cnt==n-1)
		return true;
	}
	if(cnt<n-1)
	return false;
}
int main()
{
	shit_CCF
	cin>>n>>m>>z;
	F(i,1,n)
	fa[i]=i;
	F(i,1,m)
	cin>>a[i].start>>a[i].to>>a[i].v;
	if(kruskal(z))
	cout<<ans;
	else
	{
		cout<<ans<<'\n';
		cout<<"N0";
	}
	FUCK_CCF
}
