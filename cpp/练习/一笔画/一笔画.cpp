#include <iostream>
#include <cstring>
using namespace std;
const int maxn=101;
int g[maxn][maxn],du[maxn],circuit[maxn],n,e,circuitpos,x,y,start;
void find_circuit(int i)
{
	int j;
	for(j=1;j<=n;j++){
		if(g[i][j]==1){
			g[i][j]=g[j][i]=0;
			find_circuit(j);
		}
	}
	circuit[++circuitpos]=i;
}
int main()
{
	memset(g,0,sizeof(g));
	cin>>n>>e;
	int i;
	for(i=1;i<=e;i++){
		cin>>x>>y;
		g[x][y]=g[y][x]=1;
		du[x]++;
		du[y]++;
	}
	start=1;
	for(i=1;i<=n;i++)if(du[i]%2==1)start=i;
	circuitpos=0;
	find_circuit(start);
	for(i=1;i<=circuitpos;i++)cout<<circuit[i]<<' ';
	cout<<endl;
	return 0;
}
