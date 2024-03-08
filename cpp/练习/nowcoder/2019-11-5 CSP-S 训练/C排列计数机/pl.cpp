#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int M=1000000007;
int n,m,a[100005],maxn=0,f[100005];
long long ans=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[1]=a[1];
	for(int i=1;i<=n;i++){
		if(f[maxn]<a[i])f[++maxn]=a[i];
		else f[upper_bound(f+1,f+n+1,a[i])-f]=a[i];
	}
	for(int i=maxn;i>0;i--){
		ans=(ans%M+(n+(maxn-i)*(n-m)%M)%M*(long long)pow(i,m)%M)%M;
	}
	cout<<ans<<endl;
	return 0;
}
