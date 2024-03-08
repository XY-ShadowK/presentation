#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long a[200005],t,n,last,ms;
int main(){
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for(int i=0;i<n;i++)scanf("%lld",a+i);
		if(n==1){
			printf("%lld\n",a[0]);
			continue;
		}
		sort(a,a+n);
		ms=0;
		last=a[0]+ms;
		ms-=a[0]+ms;
		for(int i=1;i<n;i++){
			if(last>=a[n-1]+ms)break;
			while(a[i-1]==a[i])i++;
			last=a[i]+ms;
			ms-=a[i]+ms;
		}
		printf("%lld\n",last);
	}
    return 0;
}
