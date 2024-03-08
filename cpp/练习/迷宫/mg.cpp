#include <iostream>
using namespace std;
int m,n,t,sx,sy,fx,fy,sum,maze[7][7],zax,zay;
void Maze(int a,int b)
{
	if(a==fx&&b==fy){
		sum++;
		return;
	}
	maze[a][b]=1;
	if(maze[a][b+1]==0){
		Maze(a,b+1);
	}
	if(maze[a+1][b]==0){
		Maze(a+1,b);
	}
	if(maze[a][b-1]==0){
		Maze(a,b-1);
	}
	if(maze[a-1][b]==0){
		Maze(a-1,b);
	}
	maze[a][b]=0;
	return;
} 
int main()
{
	int i;
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	for(i=0;i<t;i++){
		cin>>zax>>zay;
		maze[zax][zay]=1;
	}
	for(i=0;i<n+2;i++){
		maze[0][i]=1;
		maze[n+1][i]=1;
	}
	for(i=0;i<m+2;i++){
		maze[i][0]=1;
		maze[i][m+1]=1;
	}
	maze[sx][sy]=1;
	Maze(sx,sy);
	cout<<sum;
	return 0;
} 
