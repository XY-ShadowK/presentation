#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long n,maxn[100005]={0},w[100005],maxn1=0,maxn2=0;
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%lld",w+i);
		maxn[i]=max(maxn[i-1],w[i]);
	}
	for(long long i=n;i>0;i--){
		maxn1=max(maxn1,w[i]);
		maxn2=max(abs(maxn1-maxn[i]),maxn2);
	}
	cout<<maxn2;
	return 0;
}
