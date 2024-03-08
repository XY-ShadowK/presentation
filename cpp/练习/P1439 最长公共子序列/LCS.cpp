#include <iostream>
#include <algorithm>
using namespace std;
int f[100005],n,a[100005],b[100005],map[100005];
int main()
{
	cin>>n;
	int maxn=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		map[a[i]]=i;
	}
	for(int i=1;i<=n;i++)cin>>b[i];
	f[1]=map[b[1]];
	for(int i=2;i<=n;i++){
		if(f[maxn]<map[b[i]])f[++maxn]=map[b[i]];
		else f[upper_bound(f+1,f+maxn+1,map[b[i]])-f]=map[b[i]];
	}
	cout<<maxn<<endl;
	return 0;
}
