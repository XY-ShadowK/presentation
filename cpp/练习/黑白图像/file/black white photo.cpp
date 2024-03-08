#include<cstdio>
#include<cstdlib>
#include <iostream>
//#include <fstream>
using namespace std;
//ifstream fin("common.in");
//ofstream fout("common.out");
int maze[710][710];
bool Maze(int a,int b)
{
	int h=0;
	if(maze[a][b]==1){
		h=1;
	}
	maze[a][b]=0;
	if(maze[a][b+1]==1){
		Maze(a,b+1);
		h=1;
	}
	if(maze[a+1][b]==1){
		Maze(a+1,b);
		h=1;
	}
	if(maze[a][b-1]==1){
		Maze(a,b-1);
		h=1;
	}
	if(maze[a-1][b]==1){
		Maze(a-1,b);
		h=1;
	}
	if(maze[a+1][b+1]==1){
		Maze(a+1,b+1);
		h=1;
	}
	if(maze[a-1][b+1]==1){
		Maze(a-1,b+1);
		h=1;
	}
	if(maze[a+1][b-1]==1){
		Maze(a+1,b-1);
		h=1;
	}
	if(maze[a-1][b-1]==1){
		Maze(a-1,b-1);
		h=1;
	}
	return h==1?true:false;
} 
int main()
{
//	freopen("common.in","r",stdin);
//	freopen("common.out","w",stdout);
	int i,j,n,sum;
	char cmaze;
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>cmaze;
			maze[i][j]=(int)cmaze-'0';
		}
	}
	for(i=0;i<n+2;i++){
		maze[0][i]=0;
		maze[n][i]=0;
		maze[i][0]=0;
		maze[i][n]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(Maze(i,j)==true){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
