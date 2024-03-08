#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
long long two,thr,t,n;
inline long long cal(long long &k,long long num)
{
	long long aans=0;
	while(!(k%num))k/=num,aans++;
	return aans;
}
int main()
{
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		two=cal(n,2);
		thr=cal(n,3);
		if(two<=thr&&n==1)printf("%lld\n",thr*2-two);
		else printf("-1\n");
	}
	return 0;
}
