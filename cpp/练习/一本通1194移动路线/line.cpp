#include <iostream>
using namespace std;
int m,n,map[22][22];
int dfs(int x,int y)
{
	if(x>m||y>n)return 0;
	if(x==m&&y==n)return 1;
	int ans=0;
	if(map[x+1][y]==0){
		map[x+1][y]=1;
		ans+=dfs(x+1,y);
		map[x+1][y]=0;
	}
	if(map[x][y+1]==0){
		map[x][y+1]=1;
		ans+=dfs(x,y+1);
		map[x][y+1]=0;
	}
	return ans;
}
int main()
{
	cin>>m>>n;
	cout<<dfs(1,1);
	return 0;
}
