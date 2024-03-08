#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
typedef long long LL;
LL fac[1000005]={0},inv[1000005]={0};
LL comp(LL n,LL m,LL p)
{
	cout<<fac[n]<<' '<<inv[m]<<' '<<inv[n-m]<<endl;
	cout<<"comp( "<<n<<" , "<<m<<" )="<<fac[n]*inv[m]%p*inv[n-m]%p<<endl;
	return fac[n]*inv[m]%p*inv[n-m]%p;
}
//组合数网板 
/*组合数
C[n][m]=n!/(m!*(n-m)!)=fac[n]*inv[m!]*inv[(n-m)!]
*/ 
LL lucas(LL n,LL m,LL p)
{
	LL ans=1,nn=n,mm=m;
	while(n&&m&&ans){
		ans=(ans*comp(n%p,m%p,p))%p;
		n/=p;
		m/=p;
	}
	cout<<"lucas( "<<nn<<" , "<<mm<<" )="<<ans<<endl;
	return ans;
}
//卢卡斯定理网板
/*卢卡斯定理
lucas(n,m,p)=lucas(n/p,m/p,p)*C[n%p][m%p] 
*/
int main()
{
	fac[0]=1;
	inv[0]=1;
	inv[1]=1;
	LL n,m,p;
	cin>>n>>m>>p;
	for(LL i=1;i<=n;i++)fac[i]=fac[i-1]*i%p;
//预处理阶乘数组fac[i]=i! 
	for(LL i=2;i<=n;i++)inv[i]=(p-p/i)*inv[p%i]%p;
//预处理逆元数组inv[i]=inv[i]
	for(LL i=1;i<=n;i++)inv[i]=inv[i-1]*inv[i]%p;
//预处理阶乘逆元数组inv[i]=inv[i!]
	cout<<"lucas: "<<lucas(n,m,p)<<endl; 
	return 0;
}
