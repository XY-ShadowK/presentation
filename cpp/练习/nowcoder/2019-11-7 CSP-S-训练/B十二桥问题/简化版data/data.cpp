#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ofstream fin("bridge.in");
ofstream fout("bridge.out");
int n,m,k,f[1005][1005],node[30][2];
bool used[30];
long long ans,memory[30];
void floyd()
{
	for(int k=1;k<=n;k++)for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
long long dfs(int num)
{
	if(memory[num])return memory[num];
	used[num]=true;
	long long anst=99999999,t;
	for(int i=0;i<k;i++){
		if(used[i])continue;
		t=99999999;
		t=min(t,dfs(i)+f[node[num][0]][node[i][0]]);
		t=min(t,dfs(i)+f[node[num][0]][node[i][1]]);
		t=min(t,dfs(i)+f[node[num][1]][node[i][0]]);
		t=min(t,dfs(i)+f[node[num][1]][node[i][1]]);
		anst=min(anst,t);
	}
	memory[num]=anst;
	used[num]=false;
	return anst;
}
int main()
{
	cin>>n>>m>>k;
	int a,b,v;
	for(int i=0;i<m;i++){
		cin>>a>>b>>v;
		node[i][0]=a;
		node[i][1]=b;
		f[a][b]=v;
		f[b][a]=v;
	}
	floyd();
	for(int i=0;i<k;i++){
		for(int j=0;i<k;i++)memory[i]=0;
		dfs(i);
	}
	cout<<ans<<endl;
	return 0;
}
