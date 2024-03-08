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
long long n,k,l,m,t,ans=0,cnt=0,f[105][3];
int main()
{
	cin>>n;
	if(!n)return 0;
	for(long long i=0;i<n;i++){
		cin>>f[i][0]>>f[i][1];
		f[i][2]=i;
	}
	for(long long i=0;i<n;i++)for(long long j=1;j<n;j++)if(f[i][0]==f[j][0]||f[i][1]==f[j][1]){
		f[i][2]=min(f[i][2],f[j][2]);
		f[j][2]=f[i][2];
	}
	for(long long i=0;i<n;i++)if(f[i][2]==i)ans++;
	cout<<ans-1;
	return 0;
}
