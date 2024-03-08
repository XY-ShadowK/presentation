#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
long long t,n,k,xx,yy;
int main()
{
	cin>>t;
	while(t--){
		scanf("%lld%lld%lld",&xx,&yy,&n);
		k=(n-yy)/xx;
		k*=xx;
		printf("%lld\n",k+yy);
	}
	return 0;
}
