#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef struct tQTP{
	int x,y;
}ZB;
queue <ZB> q1,q2;
int l[2],r[2],ans,map[305][305],n,Length,first[2],last[2],dx[8]={1,2,2,1,-1,-2,-2,-1},dy[8]={2,1,-1,-2,-2,-1,1,2};
bool within(int x,int y)
{
	return x>=0&&x<Length&&y>=0&&y<Length;
}
int kz(int a){
	return a>0?a:-a;
}
void up(int x,int y,int steps)
{
	if(steps*map[x][y]>0)
}
void bfs(int x,int y,int steps)
{
	if(map[x][y]!=0){
		up(x,y,steps);
	}
	int i,nx,ny;
	for(i=0;i<8;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(within(nx,ny))bfs(nx,ny,steps>=0?steps+1:steps-1); 
	}
}
void bfs()
{
	bfs(first[0],first[1],0);
	return;
}
int main()
{
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		memset(map,0,93025);
		cin>>Length>>first[0]>>first[1]>>last[0]>>last[1];
		bfs();
	}
	return 0;
}
