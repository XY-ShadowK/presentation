#include <iostream>
using namespace std;
typedef struct tSUPER{
	int a[10],gs=0;
}SUPER;
int sz[11][11],n,m,bs[11];
SUPER hh[11];
void make_b(int start,int now,int gs)
{
	bs[now]=1;
	int i;
	if(sz[start][now]==20||sz[start][now]>gs){
		sz[start][now]=gs;
		sz[now][start]=gs;
	}
	for(i=0;i<hh[now].gs;i++){
		if(bs[hh[now].a[i]]!=1){
			make_b(start,hh[now].a[i],gs+1);
		}
	}
	bs[now]=0;
	return;
}
int main()
{
	cin>>n>>m;
	int i,j,x,y;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				sz[i][j]=0;
			}
			sz[i][j]=20;
		}
	}
	for(i=0;i<m;i++){
		cin>>x>>y;
		hh[x].a[hh[x].gs]=y;
		hh[x].gs++;
		hh[y].a[hh[y].gs]=x;
		hh[y].gs++;
		sz[x][y]=1;
		sz[y][x]=1;
	}
	for(i=1;i<=n;i++){
		make_b(i,i,0);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cout<<sz[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
