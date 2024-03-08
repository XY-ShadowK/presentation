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
typedef struct tTT{
	long long sco,cn,sg;
}tt;
long long n,t,l,m,cnt=0,ans=0,sum=0,f[1005][1005]={0};
string str[5005];
char tp;
tt dd[5005],dlc[1005];
set<long long> sq;
inline bool pd(long long num)
{
	long long end=sqrt(num);
	for(long long i=2;i<=end;i++)if(!(num%i))return false;
	return true;
}
inline bool cmp(tt aa,tt bb)
{
	if(aa.sco==bb.sco){
		if(aa.cn==bb.cn)return aa.sg<bb.sg;
		return aa.cn>bb.cn;
	}
	return aa.sco>bb.sco;
}
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>dd[i].cn>>t>>l;
		dd[i].sco=dd[i].cn+t+l;
		dd[i].sg=i;
	}
	sort(dd+1,dd+n+1,cmp);
	for(long long i=1;i<=5;i++)cout<<dd[i].sg<<' '<<dd[i].sco<<endl;
	return 0;
}
