#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
long long n,aj[100005],ans=0,temp,lenj=0;
int main()
{
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>temp;
		if(temp%2)aj[lenj++]=temp;
		ans+=temp;
	}
	sort(aj,aj+lenj-1);
	if(ans%2)ans-=aj[0];
	cout<<ans<<endl;
	return 0;
}
