#include<bits/stdc++.h>
#define cin std::cin
#define cout std::cout
#define F(i,n,m) for(int i=n;i<=m;i++)
#define FF(i,n,m) for(int i=n;i*i<=m;i++)
bool find(int x)
{
	if(x==1) return false;
	if(x==2) return true;
	FF(i,2,x) if(x%i==0) return false;
	return true;
}
int main()
{
	int n,m;
	cin>>n>>m; 
	F(i,1,m)
	{
		cin>>n;
		if(find(n)) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
