#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0){
		x=1,y=0;
//��Լ��Ϊ0ʱ���趨��ԭŷ������㷨ax+by=gcd(a,b)����תΪgcd*x+0*y=gcd�Ľ�x0=1��y0=0
//��ʱ����a=gcd(a,b)��b=0 
//ע1��������Ԫ��gcd(a,b)=1������ax+by=1תΪ1*x+0*y=1 
		return a;
//����a��gcd(a,b)
//ע2��������Ԫ�����ҽ���a=gcd(a,b)=1ʱ��Ԫ���� 
	}
	LL ret=exgcd(b,a%b,y,x);
//����a��gcd(b,a%b)=gcd(a,b)
	y-=a/b*x;
//��ŷ����ŷ�õ���ʽx[i]=y[i-1]��y[i]=x[i-1]-y[i-1]*����ȡ��(a/b) 
	return ret;
}
//��ŷ���� 
LL getinv(LL a,LL mod)
{
	LL x,y;
	LL d=exgcd(a,mod,x,y);
//����gcd(a,mod)
//ע3��������Ԫ��gcd(a,mod)=1����a��b����������Ԫ�����ڼ�gcd(a,mod)��Ϊ1����ע2 
	return d==1?(x%mod+mod)%mod:-1;
//��������Ԫ���߲����� 
}
//��ŷ����Ԫ���� 
/*��ŷ����ԪֻҪ��Ԫ���ڼ��������mod���������� 
��ͬ�෽��a*b��1(modp)ת��Ϊa*b+k*p=1����չŷ������㷨���
���Է���ax+by=gcd(a,b),��a=a,b=p,��gcd(a,b)=1,x��Ϊ������Ԫb 
*/
int main()
{
	LL a,mod;
	cin>>a>>mod;
	cout<<"exgcd: "<<getinv(a,mod)<<endl;
	return 0;
}
