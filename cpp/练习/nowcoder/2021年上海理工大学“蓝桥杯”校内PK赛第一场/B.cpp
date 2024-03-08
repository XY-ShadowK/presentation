#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
long long t,ai,bi,li,ri,temp;
inline long long check(long long k)
{
	for(long long i=li/k;;i++){
		if(k*i>ri)return -1;
		if(k*i>=li)return k*i;
	}
}
int main()
{
	cin>>t;
	while(t--){
		scanf("%lld%lld%lld%lld",&ai,&bi,&li,&ri);
		temp=ai*bi/__gcd(ai,bi);
		printf("%lld\n",check(temp));
	}
	return 0;
}
