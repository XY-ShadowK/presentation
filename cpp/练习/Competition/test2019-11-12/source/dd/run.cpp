#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
typedef struct tEdge{
	int next,end,value;
}Edge;
Edge l[1000005];
int n,m,body,head[1000005],dis[1000005];
bool used[1000005];
priority_queue <pair<int,int> > q;
void dijkstra()
{
	q.push(make_pair(0,1));
	for(int i=2;i<=n;i++)dis[i]=INT_MAX;
	dis[1]=0;
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(!used[x]){
			used[x]=true;
			for(int i=head[x];i;i=l[i].next){
				int y=l[i].end,z=l[i].value;
				if(dis[y]>dis[x]+z){
					dis[y]=dis[x]+z;
					q.push(make_pair(-dis[y],y));
				}
			}
		}
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d%d",&n,&m,&body);
	int temp;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&temp,&l[i].end,&l[i].value);
		l[i].next=head[temp];
		head[temp]=i;
	}
	dijkstra();
	if(dis[n]==INT_MAX||dis[n]>body)cout<<-1<<endl;
	else cout<<body-dis[n]<<endl;
	return 0;
}
