#include<bits/stdc++.h>
#define F(i,n,m) for(int i=n;i<=m;i++)
#define shit_CCF freopen("run.in","r",stdin);freopen("run.out","w",stdout);
#define FUCK_CCF fclose(stdin);fclose(stdout);return 0;
using namespace std;
int head[1000001],vis[1000001],tot=1,dist[1000001];
struct node{
	int next,to,bq;
}ma[1000001];
void add(int a,int b,int c)
{
	ma[tot].to=b;
	ma[tot].bq=c;
	ma[tot].next=head[a];
	head[a]=tot++;
}

int main()
{
	shit_CCF
	priority_queue<pair<int,int> >q;
	
	int n,m,st,t1,t2,t3;
	cin>>n>>m>>st;
	for(int i=1;i<=m;i++)
	{
		
		cin>>t1>>t2>>t3;
		add(t1,t2,t3);
	}
	q.push(make_pair(0,1));
	for(int i=1;i<=n;i++)
	dist[i]=INT_MAX;
	dist[1]=0;
	while(q.size())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]==1)
		continue;
		vis[x]=1;
		for(int i=head[x];i;i=ma[i].next)
		{
			int y=ma[i].to,z=ma[i].bq;
			if(dist[y]>dist[x]+z)
			{
				dist[y]=dist[x]+z;
				q.push(make_pair(-dist[y],y));
			}
		}
	}
	if(dist[n]==INT_MAX||dist[n]>st)
	cout<<-1;
	else
	cout<<st-dist[n];
	FUCK_CCF
}
