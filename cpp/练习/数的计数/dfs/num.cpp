#include <iostream>
using namespace std;
int dfs(int num)
{
	int ans=num/2;
	for(int i=2;i<=num/2;i++){
		ans+=dfs(i);
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<dfs(n)+1;
	return 0;
}
