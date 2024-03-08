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
//��������������*(pi-1)/pi 
		while(n%i==0)n/=i;
//ÿ��������ֻ����һ�Σ�������ĸ����������� 
	}
	if(n>1)res=res/n*(n-1);
//���ʣ�µ�Ҳ��ԭn�������� 
	return res;
}
//��ŷ����������
/*ŷ������
����1����pΪ������eula(p^n)=p^(n-1)*(p-1)
����2����m=m1m2��m1��m2�й�ͬ����������eula(m)=eula(m1)*m2 (m2<=m1)
����3����gcd(a,b)=1����eula(ab)=eula(a)*eula(b) 
��eula(x)����x��ʽ�ֽ��x=p1^k1+p2^k2+...+pn^kn
eula(x)=eula(p1^k1)*eula(p2^k2)*...*eula(pn^kn)
=(p1-1)*p1^(k1-1)*(p2-1)*p2^(k2-1)*...*(pn-1)*pn^(kn-1)
=p1^k1*p2^k2*...*pn^kn*(p1-1)/p1*(p2-1)/p2*...*(pn-1)/pn
=x*(p1-1)/p1*(p2-1)/p2*...*(pn-1)/pn
*/ 
LL quickpow(LL a,LL p,LL mod)
{
	LL t=1,tt=a%mod;
//��ʼ��t=a^0=1,tt=����=a^1 
	while(p){
		if(p&1)t=t*tt%mod;
//t*=a^p[i]
		tt=tt*tt%mod;
//tt=a^(2^(i+1)) 
		p>>=1;
//p��������ʾ��ԭp[i+1]����p[0] 
	}
	return t;
}
//����������
/*������
��a^p���a^p=a^p[0]*a^p[1]*...*a^p[n]���� 
*/ 
LL fermat_getinv(LL a,LL mod)
{
	return quickpow(a,mod-2,mod);
}
//����С��������Ԫ����
/*����С����
��ͬ�෽��ab��1(modp),��pΪ��������a^(p-1)��1(modp),a^(p-2)*a��1(modp)
������a��modp����Ԫb=a^(p-2) 
*/ 
LL eula_getinv(LL a,LL mod)
{
	return quickpow(a,phi(mod)-1,mod);
}
//ŷ����������Ԫ����
/*ŷ������
��gcd(a,p)=1,��a^eula(p)��1(modp),��a^(eula(p)-1)��1(modp)
��ͬ�෽��ab��1(modp),����a��modp����Ԫb=a^(eula(p)-1) 
*/ 
int main()
{
	LL a,mod;
	cin>>a>>mod;
	cout<<"fermat: "<<fermat_getinv(a,mod)<<endl<<"eula: "<<eula_getinv(a,mod)<<endl;
	return 0;
}
