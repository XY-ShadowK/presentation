#include <iostream>
using namespace std;
const long long n=2,p=998244353; 
long long m;
long long mi(long long mm)
{
	long long ans=1,nn=n;
	while(mm){
		if(mm&1)ans=ans*nn%p;
		nn=nn*nn%p;
		mm>>=1;
	}
	return ans;
}
int main()
{
	cin>>m;
	cout<<mi(m)<<endl;
	return 0;
}
