#include <iostream>
#include <cstring>
using namespace std;
const int INF=0x7fffffff/2;
int vst[505],d[505],g[505][505],n,m,ans=0;
void Read()
{
	int i,j,x,y,w;
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)g[i][j]=INF;
	for(i=1;i<=m;i++){
		cin>>x>>y>>w;
		g[x][y]=g[y][x]=w;
	}
}
void Prim(int v0)
{
	int i,j,k,minn;
	memset(vst,0,sizeof(vst));
	for(i=1;i<=n;i++)d[i]=INF;
	d[v0]=0;
	ans=0;
	for(i=1;i<=n;i++){
		minn=INF;
		for(j=1;j<=n;j++)if(vst[j]==0&&minn>d[j]){
			minn=d[j];
			k=j;
		}
		vst[k]=1;
		ans+=d[k];
		for(j=1;j<=n;j++)if(vst[j]==0&&d[j]>g[k][j])d[j]=g[k][j];
	}
}
int main()
{
	Read();
	Prim(1);
	cout<<ans<<endl;
	return 0;
}
