#include <iostream>
using namespace std;
const long long P=1000000007;
int N,M,K,a[1000005];
inline void jc()
{
	a[0]=a[1]=1;
	for(int i=2;i<=N&&i<1000001;i++)a[i]=a[i-1]*i%P;
	return;
}
long long C(int n,int m)
{
	return a[n]/a[n-m]/a[m]%P;
}
long long lucas(int n,int m)
{
	if(!m)return 1;
	return lucas(n/P,m/P)*C(n%P,m%P)%P;
}
int main()
{
	cin>>N>>M>>K;
	jc();
	cout<<lucas(N-K,M-1);
	return 0;
}
