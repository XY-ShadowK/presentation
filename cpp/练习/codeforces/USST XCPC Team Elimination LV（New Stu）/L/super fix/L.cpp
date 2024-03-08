#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
long long n,ans=0,temp,minn=1000000;
int main()
{
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>temp;
		if(temp%2)minn=min(minn,temp);
		ans+=temp;
	}
	if(ans%2)ans-=minn;
	cout<<ans<<endl;
	return 0;
}
