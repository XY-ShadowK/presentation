#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
typedef struct tEdge{
	int next,to,cost;
}Edge;
Edge l[50005];
int n,m,k,s,e,head[10005],f[10005][12],tot=1;
bool used[10005];
priority_queue <pair<int,int> > q;
void add(int a,int b,int c)
{
	l[tot].to=b;
	l[tot].cost=c;
	l[tot].next=head[a];
	head[a]=tot++;
}
void dijkstra()
{
	for(int i=0;i<=k;i++)f[s][i]=0;
	for(int i=0;i<=k;i++){
		q.push(make_pair(0,s));
		while(q.size()){
			int x=q.top().second,vl=q.top().first;
			q.pop();
			if(vl>f[x][i])continue;
			for(int j=head[x];j;j=l[j].next){
				int v=l[j].to;
				bool bj=false;
				if(i)if(f[v][i]>f[x][i-1]){
					f[v][i]=f[x][i-1];
					bj=true;
				}
				if(f[v][i]>f[x][i]+l[j].cost){
					f[v][i]=f[x][i]+l[j].cost;
					bj=true;
				}
				if(bj)q.push(make_pair(v,f[v][i]));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&k,&s,&e);
	int t1,t2,t3;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		add(t1,t2,t3);
		add(t2,t1,t3);
	}
	for(int i=0;i<n;i++)for(int j=0;j<=k;j++)f[i][j]=INT_MAX;
	dijkstra();
	cout<<f[e][k]<<endl;
	return 0;
}
