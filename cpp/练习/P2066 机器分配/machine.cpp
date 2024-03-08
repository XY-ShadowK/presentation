#include <iostream>
using namespace std;
int n,m,f[15][20],p[15][20][15],value[15][20];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>value[i][j];
	for(int i=1;i<=n;i++)for(int j=0;j<=m;j++)for(int k=0;k<=j;k++)if(f[i][j]<f[i-1][k]+value[i][j-k]){
		f[i][j]=f[i-1][k]+value[i][j-k];
		for(int t=1;t<i;t++)p[i][j][t]=p[i-1][k][t];
		p[i][j][i]=j-k;
	}
	cout<<f[n][m]<<endl;
	for(int i=1;i<=n;i++)cout<<i<<' '<<p[n][m][i]<<endl;
	return 0;
}
