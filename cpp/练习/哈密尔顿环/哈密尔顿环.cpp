#include <iostream>
#include <cstring>
using namespace std;
int start,length,x,n,ans[101],num[101],g[101][101];
bool visited[101],v1[101];
void print()
{
	int i;
	for(i=1;i<length;i++)cout<<ans[i]<<' ';
	cout<<ans[length]<<endl;
}
void dfs(int last,int i)
{
	visited[i]=true;
	v1[i]=true;
	ans[++length]=i;
	for(int j=1;j<=num[i];j++){
		if(g[i][j]==x&&g[i][j]!=last){
			ans[++length]=g[i][j];
			print();
			length--;
			break;
		}
		if(!visited[g[i][j]])dfs(i,g[i][j]);
	}
	length--;
	visited[i]=false;
}
int main()
{
	memset(visited,false,sizeof(visited));
	memset(v1,false,sizeof(v1));
	cin>>n;
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x][++num[x]]=y;
		g[y][++num[y]]=x;
	}
	for(x=1;x<=n;x++)if(!v1[x]){length=0;dfs(0,x);}
	return 0;
}
