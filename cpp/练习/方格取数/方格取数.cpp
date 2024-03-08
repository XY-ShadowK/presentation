#include <iostream>
#include <queue>
using namespace std;
typedef struct tXY{
	int x,y;
}XY;
queue <XY>q;
int n,map[10][10],maxn[2]={-1,-1};
void bfs()
{
	
}
int main()
{
	cin>>n;
	int i,temp,x,y;
	for(i=0;i<n;i++){
		cin>>x>>y>>temp;
		map[x][y]=temp;
	}
	bfs();
	cout<<maxn[0]+maxn[1]<<endl;
	return 0;
}
