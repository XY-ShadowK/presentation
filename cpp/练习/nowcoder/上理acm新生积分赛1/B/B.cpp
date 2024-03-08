#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <set>
using namespace std;
long long n,k,l,m,ans=0,cnt=0;
char ch;
bool f=true,e=true;
inline bool pd(long long a,long long b)
{
	if(b%10*10+b/10==a)return true;
	return false;
}
int main()
{
	cin>>n>>ch>>m;
	for(long long j=m-1;j>=0;j--)if(pd(n,j)){
		cout<<n<<ch<<j<<endl;
		f=false;
		break;
	}
	if(f)for(long long i=n-1;i>=0;i--)for(long long j=59;j>=0;j--)if(pd(i,j)){
		cout<<i<<ch<<j<<endl;
		goto A;
	}
	A:
	for(long long j=m+1;j<60;j++)if(pd(n,j)){
		cout<<n<<ch<<j<<endl;
		e=false;
		break;
	}
	if(e)for(long long i=n+1;i<24;i++)for(long long j=0;j<60;j++)if(pd(i,j)){
		cout<<i<<ch<<j<<endl;
		e=false;
		goto B;
	}
	B:
	if(e)cout<<"0:0"<<endl;
	return 0;
}
