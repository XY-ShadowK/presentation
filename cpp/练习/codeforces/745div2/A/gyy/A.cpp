#include <iostream>
using namespace std;
long long t,n,ans,mod=1e9+7;
int main()
{
	cin>>t;
	for(long long j=0;j<t;j++){
		cin>>n;
		ans=1; 
		for(long long i=2*n;i>=3;i--)ans=(ans*i)%mod;
		ans=ans%mod;
		cout<<ans<<endl;
	}
	return 0;
}
