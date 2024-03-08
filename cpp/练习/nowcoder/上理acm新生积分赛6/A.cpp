#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
using namespace std;
long long n,a[100005],ans=0;
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)scanf("%lld",a+i);
	for(long long i=n;i>0;i--)ans=max(ans+1,a[i]);
	cout<<ans;
	return 0;
}
