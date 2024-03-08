#include <iostream>
#include <algorithm>
using namespace std;
int minn[105],maxn[105],height[105],n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>height[i];
	}
	for(int i=0;i<n;i++){
		maxn[i]=1;
		for(int j=0;j<i;j++){
			if(height[j]>=height[i])continue;
			maxn[i]=max(maxn[i],maxn[j]+1);
		}
	}
	for(int i=n-1;i>=0;i--){
		minn[i]=1;
		for(int j=n-1;j>i;j--){
			if(height[j]>=height[i])continue;
			minn[i]=max(minn[i],minn[j]+1);
		}
	}
	int ans=999999;
	for(int i=0;i<n;i++){
		ans=min(ans,n-maxn[i]-minn[i]+1);
	}
	cout<<ans<<endl;
	return 0;
}
