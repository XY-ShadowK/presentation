#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
struct qtp{int x,y;}q[2][100000];
int test,ans,n,l[2],r[2],dis[2][301][301],v[2][301][301],dx[8]={1,2,2,1,-1,-2,-2,-1},dy[8]={2,1,-1,-2,-2,-1,1,2};
int expand(int k)
{
	int t,i,j,x,y,d,tx,ty;
	x=q[k][l[k]].x;
	y=q[k][l[k]].y;
	d=dis[k][x][y];
	for(i=0;i<8;i++){
		tx=x+dx[i];
		ty=y+dy[i];
		if(tx>=0&&tx<=n&&ty>=0&&ty<=n&&!v[k][tx][ty]){
			v[k][tx][ty]=1;
			r[k]++;
			q[k][r[k]].x=tx;
			q[k][r[k]].y=ty;
			dis[k][tx][ty]=d+1;
			if(v[1-k][tx][ty]){
				ans=dis[k][tx][ty]+dis[1-k][tx][ty];
				return 1;
			}
		}
	}
	return 0;
}
void bfs()
{
	if(q[0][1].x==q[1][1].x&&q[0][1].y==q[1][1].y){
		ans=0;
		return;
	}
	v[0][q[0][1].x][q[0][1].y]=1;
	v[1][q[1][1].x][q[1][1].y]=1;
	l[0]=r[0]=1;
	l[1]=r[1]=1;
	while(l[0]<=r[0]&&l[1]<=r[1]){
		if(r[0]-l[0]<r[1]-l[1]){
			if(expand(0))return;
			l[0]++;
		}
		if(r[0]-l[0]>=r[1]-l[1]){
			if(expand(1))return;
			l[1]++;
		}
	}
}
int main()
{
	cin>>test;
	for(int i=1;i<=test;i++){
		memset(v,false,sizeof(v));
		memset(q,0,sizeof(q));
		memset(dis,0,sizeof(dis));
		cin>>n;
		n=n-1;
		cin>>q[0][1].x>>q[0][1].y;
		cin>>q[1][1].x>>q[1][1].y;
		bfs();
		cout<<ans<<endl;
	}
	return 0;
}
