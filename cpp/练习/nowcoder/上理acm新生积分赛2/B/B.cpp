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
typedef struct tT{
	int drt,d;
}tt;
long long a[1000005],n,m,t=0,ans=0,l,va[30],cnt=0;
string str;
inline bool cmp1(tt aa,tt bb)
{
	return aa.drt<bb.drt;
}
int main()
{
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<n;i++){
		l=(int)(str[i]-'a');
		a[i]=++va[l];
	}
	for(int i=0;i<m;i++){
		scanf("%d",&t);
		printf("%d\n",a[t-1]);
	}
	return 0;
}
