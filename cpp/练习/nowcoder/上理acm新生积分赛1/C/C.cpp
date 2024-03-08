#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <set>
using namespace std;
long long n,k,l,m,t,ans=0,cnt=0,big=0,small=0,step[10][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
char map[505][505],f[505][505];
bool gg,th[505][505];
set<long long> sq;
inline bool okk(long long xb,long long yb,long long stp)
{
	xb+=step[stp][0];
	yb+=step[stp][1];
	return (th[xb][yb]&&map[xb][yb]=='.'&&xb>=1&&xb<=n&&yb>=1&&yb<=m);
}
inline bool upw(long long xa,long long ya)
{
	map[xa][ya]=(f[xa][ya]=='.'?'0':f[xa][ya]);
	th[xa][ya]=false;
	if(f[xa][ya]=='.')for(long long i=0;i<8;i++)if(okk(xa,ya,i))upw(xa+step[i][0],ya+step[i][1]);
	return false;
}
int main()
{
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		gg=true;
		for(long long i=1;i<=n;i++)for(long long j=1;j<=m;j++){
			cin>>f[i][j];
			map[i][j]='.';
			th[i][j]=true;
		}
		for(long long i=0;i<k;i++){
			long long xx,yy;
			cin>>xx>>yy;
			if(f[xx][yy]=='*'){
				cout<<"Game over in step "<<i+1<<endl;
				gg=false;
				break;
			}
			upw(xx,yy);
		}
		if(gg)for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++)cout<<map[i][j];
			cout<<endl;
		}
	}
	return 0;
}
