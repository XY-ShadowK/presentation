#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
using namespace std;
int t,n;
long long p,num[100005],maxn,l,r;
int main()
{
	cin>>t;
	while(t--){
		cin>>n>>p;
		for(int i=1;i<=n;i++){
			scanf("%d",num+i);
			num[i]=num[i]%p;
		}
		sort(num+1,num+n+1);
		maxn=(num[n]+num[n-1])%p;
		l=1;
		r=n;
		while(l<r){
			while(r>0&&num[l]+num[r]>=p)r--;
			if(l<r)maxn=max(maxn,num[l]+num[r]);
			l++;
		}
		cout<<maxn<<endl;
	}
	return 0;
}
