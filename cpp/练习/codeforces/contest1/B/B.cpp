#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
int cs(int x)
{
	if(x==1)return 1;
	return cs((int)(x/2))+1;
}
int main()
{
	int n,t,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>t;
	ans=cs(n);
	cout<<ans<<endl;
	return 0;
}
