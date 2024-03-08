#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,m,mg[1002][1002],jg[1000000];
int zd_zmg(int x,int y,int cs)
{
	int temp=mg[x][y],maxn=cs,hh;
	mg[x][y]=2;
	if(mg[x][y]!=mg[x][y+1]){
		hh=zd_zmg(x,y+1,cs+1);
		if(hh>maxn){
			maxn=hh;
		}
	}
	if(mg[x][y]!=mg[x+1][y]){
		hh=zd_zmg(x+1,y,cs+1);
		if(hh>maxn){
			maxn=hh;
		}
	}
	if(mg[x][y]!=mg[x][y-1]){
		hh=zd_zmg(x,y-1,cs+1);
		if(hh>maxn){
			maxn=hh;
		}
	}
	if(mg[x][y]!=mg[x-1][y]){
		hh=zd_zmg(x-1,y,cs+1);
		if(hh>maxn){
			maxn=hh;
		}
	}
	mg[x][y]=temp;
	return maxn;
}
int main()
{
	freopen("maze01.in","r",stdin);
	freopen("maze01.out","w",stdout);
	cin>>n>>m;
	int i,j,x,y;
	char temp;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>temp;
			mg[i][j]=(int)temp-'0';
		}
	}
	for(i=0;i<n+2;i++){
		mg[0][i]=2;
		mg[n+1][i]=2;
		mg[i][0]=2;
		mg[i][n+1]=2;
	}
	for(i=0;i<m;i++){
		cin>>x>>y;
		jg[i]=zd_zmg(x,y,1);
	}
	for(i=0;i<m;i++){
		cout<<jg[i]<<endl;
	}
	return 0;
}
