#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
using namespace std;
long long n,c[100005],cnt=0,ans=0;
inline bool check(long long k)
{
	for(long long i=0;i<cnt;i++)if(!(k%c[i]))return false;
	return true;
}
int main()
{
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(long long i=2;i<=n;i++)if(check(i))c[cnt++]=i;
	for(long long i=0;i<cnt;i++){
		if(n==1)break;
		while(!(n%c[i]))n/=c[i],ans++;
	}
	cout<<ans;
	return 0;
}
