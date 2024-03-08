#include <iostream>
#include <cstring>
#define MAXN 10
#define MAXM 10
using namespace std;
int map[12][12];//存放地图，外边界为-1 
int qx[200],qy[200];
void bfs(int x,int y)	//循环实现广搜
{	const int zx[4]={0,0,1,-1},zy[4]={1,-1,0,0};//右左下上四个方向 
	int tail=1,head=0,tx,ty;
	map[x][y]=-1;	//本点搜索过视为外边界-1 
	qx[tail]=x,qy[tail]=y;
	while(head!=tail)	//非空队列，头尾指针指向同一个地方为空队列 
	{	head++,tx=qx[head],ty=qy[head];
		for (int i=0;i<4;i++)
		{	x=tx+zx[i],y=ty+zy[i];
			if (map[x][y]==-1) continue;//边界和搜素过的跳过 
			map[x][y]=-1;	//本次搜到的点视为外边界-1 
			tail++,qx[tail]=x,qy[tail]=y;//增加队列新元素，为后续发起搜素的位置
		}
	}	
}
int main()
{	int i,j,ans=0;
	memset(map,255,sizeof(map));	//外边界设为-1
	for(i=1;i<=MAXN;i++)
	{	for (j=1;j<=MAXM;j++)
		{	cin>>map[i][j];
			map[i][j]=-map[i][j];//将1转换为-1,0还是0，将内边界也设为-1
		}
	}
	for(i=1;i<=MAXN;i++)
	{	if (!map[i][1]) bfs(i,1);//第1列为0的广搜 
		if (!map[i][MAXM]) bfs(i,MAXM);//第MAXM列为0的广搜
		if (!map[1][i]) bfs(1,i);//第1行为0的广搜
		if (!map[MAXM][i]) bfs(MAXM,i);//第MAXN行为0的广搜
	}
	for(i=1;i<=MAXN;i++)
		for(j=1;j<=MAXM;j++)
			if (!map[i][j]) ans++;
	cout<<ans<<endl;
	return 0;
}
/*
【输入样例】
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 1 0 0 1 0 0
0 0 0 0 0 1 0 0 1 0
0 0 1 0 0 0 1 0 1 0
0 1 0 1 0 1 0 0 1 0
0 1 0 0 1 1 0 1 1 0
0 0 1 0 0 0 0 1 0 0
0 0 0 1 1 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0
【输出样例】
15
*/
