#include <iostream>
using namespace std;
int n,m,map[101][101];/*
int * Max()
{
	int i,j,maxn[11]={0};
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(map[i][j]>maxn[i]){
				maxn[i]=map[i][j];
			}
		}
	}
	return maxn;
}
int Min(int * maxn)
{
	int i,minn;
	for(i=0;i<n;i++){
		if(minn>maxn[i]){
			minn=maxn[i];
		}
	}
	return minn;
}*/
void Floyd()
{
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(map[i][k]+map[k][j]<map[i][j]){
					map[i][j]=map[i][k]+map[k][j];
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	int i,j,x,y,maxn[11]={0},minn=99999999,hh;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			map[i][j]=99999999;
		}
	}
	for(i=0;i<m;i++){
		cin>>x>>y;
		cin>>map[x][y];
		map[y][x]=map[x][y];
	}
	Floyd();
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(map[i][j]>maxn[i]){
				maxn[i]=map[i][j];
			}
		}
	}
	for(i=0;i<n;i++){
		if(minn>maxn[i]){
			minn=maxn[i];
			hh=i;
		}
	}
	cout<<hh;
	return 0;
} 
