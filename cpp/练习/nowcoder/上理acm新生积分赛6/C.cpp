#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
using namespace std;
long long t,n,temp;
int main()
{
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		set<long long> s;
		for(long long i=1;i<=n;i++){
			scanf("%lld",&temp);
			s.insert(temp);
		}
		printf("%lld\n",s.size());
	}
	return 0;
}
