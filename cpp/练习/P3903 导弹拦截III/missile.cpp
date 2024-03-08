#include <iostream>
#include <algorithm>
using namespace std;
int n,ans[1005][2],a[1005];
int main()
{
	cin>>n;
	int maxn=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans[i][1]=1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j])ans[i][1]=max(ans[i][1],ans[j][0]+1);
			if(a[j]>a[i])ans[i][0]=max(ans[i][0],ans[j][1]+1);
		}
		maxn=max(maxn,max(ans[i][0],ans[i][1]));
	}
	cout<<maxn<<endl;
	return 0;
}
