#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
long long sum=0,temp,ans=0,n;
int main()
{
	cin>>n;
	cin>>sum;
	for(long long i=1;i<n;i++){
		cin>>temp;
		ans+=sum*temp;
		sum+=temp;
	}
	cout<<ans<<endl;
	return 0;
}
