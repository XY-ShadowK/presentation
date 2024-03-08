#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int m,n,mg[1005][1005],ans[1005][1005];
typedef struct tSuperQueue{
	queue <int> qx;
	queue <int> qy;
	void push(int x,int y)
	{
		qx.push(x);
		qy.push(y);
	}
	void pop()
	{
		qx.pop();
		qy.pop();
	}
	bool empty()
	{
		return qx.empty()||qy.empty();
	}
	bool front(int & x,int & y)
	{
		if(empty()){
			return false;
		}
		else{
			x=qx.front();
			y=qx.front();
			return true;
		}
	}
	bool back(int & x,int & y)
	{
		if(empty()){
			return false;
		}
		else{
			x=qx.back();
			y=qx.back();
			return true;
		}
	}
}SQ;
int bfs(int x,int y,int cs)
{
	if(mg[x][y]!=mg[x-1][y]&&mg[x-1][y]!=2){
		
	}
}
int main()
{
	cin>>n>>m;
	int i,j,x,y;
	char temp;
	memset(mg,2,1010025);
	memset(ans,-1,1010025);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>temp;
			mg[i][j]=(int)temp-'0';
		}
	}
	for(i=0;i<m;i++){
		cin>>x>>y;
		if(ans[x][y]!=-1){
			cout<<ans[x][y];
		}
		else{
			bfs(x,y,1);
		}
	}
	return 0;
}
