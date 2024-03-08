#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int zmc[102][102],h=0,xy[2][102],n,m;
char fhz[102][102];
void read(char &p){
	int k=0;
	char c;
	c=getchar();
	while( c < 'A' || c > 'Z' )
	  c=getchar();
	p=c;
}
int biggest()
{
	int i,max,temp=0;
	max=zmc[xy[0][0]][xy[1][0]];
	for(i=1;i<h;i++){
		if(zmc[xy[0][i]][xy[1][i]]>max){
			max=zmc[xy[0][i]][xy[1][i]];
			temp=i;
		}
	}
	return temp;
}
void ss(int x,int y,int temp)
{
	int i,j;
	for(i=x-temp;i<=x+temp;i++){
		if(i<1){
			continue;
		}
		if(i>m){
			break;
		}
		for(j=y-temp;j<=y+temp;j++){
			if(j<1){
				continue;
			}
			if(j>n){
				break;
			}
			if(fhz[i][j]=='X'){
				zmc[i][j]++;
			}
		}
	}
}
void pd(int x,int y)
{
	switch(fhz[x][y]){
		case 'X' : {
			xy[0][h]=x;
			xy[1][h]=y;
			h++;
			return;
		}
		case 'Z' : {
			ss(x,y,1);
			return;
		}
		case 'C' : {
			ss(x,y,2);
			return;
		}
		case 'N' : {
			ss(x,y,3);
			return;
		}
	}
}
int main()
{
	freopen("kadun.in","r",stdin);
	freopen("kadun.out","w",stdout);
	int i,j,a;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			read(fhz[i][j]);
		}
	}/*
	for(i=0;i<n+2;i++){
		fhz[0][i]='0';
		fhz[m+1][i]='0';
	}
	for(i=0;i<m+2;i++){
		fhz[i][0]='0';
		fhz[i][n+1]='0';
	}*/
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			pd(i,j);
		}
	}
	a=biggest();
	cout<<xy[0][a]<<' '<<xy[1][a]<<endl;
	return 0;
}
