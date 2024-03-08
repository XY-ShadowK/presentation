#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int n,m;
double dis[101][101];
int main()
{
	int i,x,y,s,t;
	double direction[101][2];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>direction[i][0]>>direction[i][1];
	}
	memset(dis,0x7f,sizeof(dis));
	cin>>m;
	for(i=0;i<m;i++){
		cin>>x>>y;
		dis[x][y]=dis[y][x]=sqrt(pow((double)direction[x][0]-direction[y][0],2)+pow((double)direction[x][1]-direction[y][1],2));
	}
	cin>>s>>t;
	for(int k=1;k<n;k++){
		for(int v=1;v<n;v++){
			if(dis[0][k]+dis[k][v]<dis[0][v]){
				dis[0][v]=dis[0][k]+dis[k][v];
			}
		}
	}
	cout<<dis[s][t]<<endl;
	return 0;
}
