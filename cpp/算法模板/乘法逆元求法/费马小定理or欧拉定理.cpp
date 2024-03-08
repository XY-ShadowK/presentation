#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
typedef long long LL;
LL phi(LL n)
{
	LL res=n;
	for(LL i=2;i*i<=n;i++){
		if(n%i==0)res=res/i*(i-1);
//发现质因数计算*(pi-1)/pi 
		while(n%i==0)n/=i;
//每个质因数只处理一次，将多余的该质因数除净 
	}
	if(n>1)res=res/n*(n-1);
//最后剩下的也是原n的质因数 
	return res;
}
//求欧拉函数网板
/*欧拉函数
性质1：若p为素数则eula(p^n)=p^(n-1)*(p-1)
性质2：若m=m1m2，m1与m2有共同质因数，则eula(m)=eula(m1)*m2 (m2<=m1)
性质3：若gcd(a,b)=1，则eula(ab)=eula(a)*eula(b) 
对eula(x)，将x因式分解得x=p1^k1+p2^k2+...+pn^kn
eula(x)=eula(p1^k1)*eula(p2^k2)*...*eula(pn^kn)
=(p1-1)*p1^(k1-1)*(p2-1)*p2^(k2-1)*...*(pn-1)*pn^(kn-1)
=p1^k1*p2^k2*...*pn^kn*(p1-1)/p1*(p2-1)/p2*...*(pn-1)/pn
=x*(p1-1)/p1*(p2-1)/p2*...*(pn-1)/pn
*/ 
LL quickpow(LL a,LL p,LL mod)
{
	LL t=1,tt=a%mod;
//初始化t=a^0=1,tt=乘数=a^1 
	while(p){
		if(p&1)t=t*tt%mod;
//t*=a^p[i]
		tt=tt*tt%mod;
//tt=a^(2^(i+1)) 
		p>>=1;
//p右移以显示出原p[i+1]至现p[0] 
	}
	return t;
}
//快速幂网板
/*快速幂
将a^p拆成a^p=a^p[0]*a^p[1]*...*a^p[n]计算 
*/ 
LL fermat_getinv(LL a,LL mod)
{
	return quickpow(a,mod-2,mod);
}
//费马小定理求逆元网板
/*费马小定理
对同余方程ab≡1(modp),若p为素数，则a^(p-1)≡1(modp),a^(p-2)*a≡1(modp)
即所求a在modp下逆元b=a^(p-2) 
*/ 
LL eula_getinv(LL a,LL mod)
{
	return quickpow(a,phi(mod)-1,mod);
}
//欧拉定理求逆元网板
/*欧拉定理
若gcd(a,p)=1,则a^eula(p)≡1(modp),则a^(eula(p)-1)≡1(modp)
对同余方程ab≡1(modp),所求a在modp下逆元b=a^(eula(p)-1) 
*/ 
int main()
{
	LL a,mod;
	cin>>a>>mod;
	cout<<"fermat: "<<fermat_getinv(a,mod)<<endl<<"eula: "<<eula_getinv(a,mod)<<endl;
	return 0;
}
