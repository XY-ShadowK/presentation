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
//当约数为0时，设定由原欧几里得算法ax+by=gcd(a,b)最终转为gcd*x+0*y=gcd的解x0=1，y0=0
//此时变量a=gcd(a,b)，b=0 
//注1：对求逆元，gcd(a,b)=1，方程ax+by=1转为1*x+0*y=1 
		return a;
//返回a即gcd(a,b)
//注2：对求逆元，当且仅当a=gcd(a,b)=1时逆元存在 
	}
	LL ret=exgcd(b,a%b,y,x);
//接受a即gcd(b,a%b)=gcd(a,b)
	y-=a/b*x;
//由欧推扩欧得递推式x[i]=y[i-1]，y[i]=x[i-1]-y[i-1]*向下取整(a/b) 
	return ret;
}
//扩欧网板 
LL getinv(LL a,LL mod)
{
	LL x,y;
	LL d=exgcd(a,mod,x,y);
//接受gcd(a,mod)
//注3：对求逆元，gcd(a,mod)=1，若a与b不互素则逆元不存在即gcd(a,mod)不为1，即注2 
	return d==1?(x%mod+mod)%mod:-1;
//返回正逆元或者不存在 
}
//扩欧求逆元网板 
/*扩欧求逆元只要逆元存在即可求出，mod无需是素数 
将同余方程a*b≡1(modp)转化为a*b+k*p=1以扩展欧几里得算法求解
即对方程ax+by=gcd(a,b),令a=a,b=p,则gcd(a,b)=1,x即为所求逆元b 
*/
int main()
{
	LL a,mod;
	cin>>a>>mod;
	cout<<"exgcd: "<<getinv(a,mod)<<endl;
	return 0;
}
