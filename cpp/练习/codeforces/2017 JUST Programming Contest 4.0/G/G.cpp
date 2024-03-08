#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int a[1000005],n,t,f[2][1000005]={0},ans;
int main()
{
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			f[0][i]=max(f[0][i-1],a[i]);
		}
		f[1][n]=a[n];
		for(int i=n-1;i>1;i--){
			f[1][i]=min(f[1][i+1],a[i]);
			if(a[i]>=f[0][i-1]&&a[i]<=f[1][i+1])ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
