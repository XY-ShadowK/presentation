#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long n,l,t,maxn=0;
int main()
{
	cin>>n>>l;
	for(long long i=0;i<n;i++){
		scanf("%lld",&t);
		maxn=max(maxn,t);
	}
	cout<<(maxn>l?maxn-l:0);
	return 0;
}
