#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD=1000000007;
long long n,t,ans;
long long power(long long num)
{
	return num<2?1:num*power(num-1);
}
long long pl(long long nn,long long mm)
{
	long long nm=nn-mm+1;
	for(long long i=nm+1;i<=nn;i++){
		nm*=i;
	}
	return nm;
} 
int main()
{
	cin>>t;
	for(long long i=0;i<t;i++){
		cin>>n;
		for(long long j=0;j<)
	}
	return 0;
}
