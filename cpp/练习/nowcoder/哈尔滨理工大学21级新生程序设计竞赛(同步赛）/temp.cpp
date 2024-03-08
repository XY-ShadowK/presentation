#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>
using namespace std;
long long n,t,ans=1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&t);
		if(ans>=i)ans=max(ans,i+t);
	}
	cout<<min(ans,n);
	return 0;
}
