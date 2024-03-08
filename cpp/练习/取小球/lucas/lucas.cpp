#include <iostream>
using namespace std;
int n,m,p,a[1000005];
void jc()
{
	a[0]=1;
	for(int i=1;i<=n&&i<=1000005;i++)a[i]=a[i-1]*i%p;
}
long long C(int n,int m)
{
	if(m>n)return 0;
	return a[n]/a[n-m]/a[m]%p;
}
long long lucas(int n,int m)
{
	if(!m)return 1;
	return lucas(n/p,m/p)*C(n%p,m%p)%p;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>p;
		n+=m;
		jc();
		cout<<lucas(n,m)<<endl;
	}
	return 0;
}
