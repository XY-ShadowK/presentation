#include <iostream>
#include <algorithm>
using namespace std;
int n,height[105],maxn[105],minn[105],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>height[i];
    height[0]=0;
    
    for(int i=1;i<=n;i++)
	for(int j=0;j<i;j++)
	if(height[i]>height[j])
	maxn[i]=max(maxn[i],maxn[j]+1);
	
    height[n+1]=0;
    
    for(int i=n;i>0;i--)
	for(int j=n+1;j>i;j--)
	if(height[i]>height[j])
	minn[i]=max(minn[i],minn[j]+1);
	
    for(int i=1;i<=n;i++)
	{
		ans=max(maxn[i]+minn[i]-1,ans);
	}
    cout<<n-ans<<endl;
    return 0;
}
