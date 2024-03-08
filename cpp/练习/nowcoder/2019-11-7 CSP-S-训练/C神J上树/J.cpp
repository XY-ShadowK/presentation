#include<bits/stdc++.h>
using namespace std;
const int maxx=300001;
long long int minn1,minn2;
int n,m,w;
int father[maxx],head[maxx],d[maxx],num=0,a[maxx];
struct node
{
	int next,to,w;
}edge[maxx*2];
void add(int u,int v,int w)
{
	edge[++num].next=head[u],edge[num].to=v,edge[num].w=w,head[u]=num;
}
void dfs(int r,int fa)
{
	int i,x;
	d[r]=d[fa]+1;
	for(i=head[r];i;i=edge[i].next)
	{
		x=edge[i].to;
		if(x==fa) continue;
		father[x]=r,a[x]=edge[i].w;
		dfs(x,r);
	}
}
long long int query(int s,int ds,int f,int df,long long int sum)
{
	if(s<minn1) minn1=s,minn2=sum;
	if((ds==df||ds<df)&&s!=f) return -1;
	if(s==f) return (sum-minn2)*f+minn1*minn2;
	return query(father[s],ds-1,f,df,sum+a[s]);
}
int main()
{
	register int i;int u,v;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dfs(1,0);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		minn1=u;
		if(u==v) printf("0\n");
		else if(d[u]>=d[v]) printf("-1\n");
		else printf("%lld\n",query(v,d[v],u,d[u],0));
	}
	return 0;
}
