#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
typedef struct tEdge{
	int next,end,value;
}Edge;
Edge l[1000005];
int n,m,s,head[1000005],dis[1000005];
bool used[1000005];
priority_queue <pair<int,int> > q;
void dijkstra()
{
	q.push(make_pair(0,s));
	for(int i=1;i<=n;i++)dis[i]=INT_MAX;
	dis[s]=0;
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
	scanf("%d%d%d",&n,&m,&s);
	int temp;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&temp,&l[i].end,&l[i].value);
		l[i].next=head[temp];
		head[temp]=i;
	}
	dijkstra();
	for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
	cout<<endl;
	return 0;
}
