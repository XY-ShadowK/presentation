#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int n;
long long ai[200005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",ai+i);
	sort(ai+1,ai+n+1);
	for(int i=n;i>0;i--)printf("%lld ",ai[i]);
	return 0;
}
