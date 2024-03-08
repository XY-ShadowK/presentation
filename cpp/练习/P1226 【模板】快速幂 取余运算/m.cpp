#include <iostream>
using namespace std;
long long n,m,p;
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
	cin>>n>>m>>p;
	long long yn=n,ym=m;
	n%=p;
	if(p==1){
		cout<<yn<<'^'<<m<<" mod "<<p<<'='<<0<<endl;
		return 0;
	}
	cout<<yn<<'^'<<m<<" mod "<<p<<'='<<mi(m)<<endl;
	return 0;
}
