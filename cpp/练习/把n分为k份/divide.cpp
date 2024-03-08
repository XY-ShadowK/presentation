#include <iostream>
using namespace std;
int n,k,divide[8],ans=0;
void dfs(int m,int num,int order)
{
	if(order==k){
		divide[k]=m;
		ans++;
		return;
	}
	int i;
	for(i=num;i<=(m/(k-order+1));i++){
		divide[order]=i;
		dfs(m-i,i,order+1);
	}
}
int main()
{
	cin>>n>>k;
	dfs(n,1,1);
	cout<<ans<<endl;
	return 0;
}
