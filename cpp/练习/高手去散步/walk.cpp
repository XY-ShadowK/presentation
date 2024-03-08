#include <iostream>
#include <algorithm>
using namespace std;
int n,m,length[25][25],used[25];
int dfs(int point)
{
	used[point]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(length[point][i]!=0&&(!used[i]))ans=max(ans,dfs(i)+length[point][i]);
	}
	used[point]=0;
	return ans;
}
int main()
{
	cin>>n>>m;
	int tl,tr,ans=0;
	for(int i=0;i<m;i++){
		cin>>tl>>tr;
		cin>>length[tl][tr];
		length[tr][tl]=length[tl][tr];
	}
	for(int i=1;i<=n;i++)ans=max(ans,dfs(i));
	cout<<ans<<endl;
	return 0;
}
