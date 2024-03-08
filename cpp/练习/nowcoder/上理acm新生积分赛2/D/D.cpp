#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
int m,n,h,e,f[235][235];
inline void floyd()
{
	for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)for(int k=0;k<=m;k++)f[j][k]=min(f[j][i]+f[i][k],f[j][k]);
	return;
}
int main()
{
	memset(f,INF,sizeof(f));
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>h>>e;
		f[h][e]=1;
	}
	for(int i=0;i<=m;i++){
		f[i][i+1]=1;
		f[i][i]=0;
	}
	floyd();
	cout<<f[0][m];
	return 0;
}
