#include <iostream>
using namespace std;
int memory[1001];
int dfs(int num)
{
	if(memory[num]!=0)return memory[num];
	int ans=1;
	for(int i=1;i<=num/2;i++){
		ans+=dfs(i);
	}
	memory[num]=ans;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	dfs(n);
	cout<<memory[n];
	return 0;
}
