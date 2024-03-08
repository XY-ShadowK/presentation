#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
using namespace std;
long long t,n,f[1005],ans;
int main()
{
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for(long long i=0;i<n;i++)scanf("%lld",f+i);
		sort(f,f+n);
		ans=0;
		for(long long i=n-1;i>=0;i--){
			ans++;
			if(f[i]<ans)break;
		}
		printf("%lld\n",ans-1);
	}
	return 0;
}
