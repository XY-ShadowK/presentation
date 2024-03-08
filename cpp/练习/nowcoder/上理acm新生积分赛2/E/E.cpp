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
int n,k;
double t,sum,f[100005][205],p[100005];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lf",p+i);
		sum+=p[i];
	}
	printf("%.4lf\n",sum);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=f[i-1][0]*(1.00-p[i]);
		for(int j=1;j<=k;j++)f[i][j]+=f[i-1][j]*(1.00-p[i])+f[i-1][j-1]*p[i];
	}
	printf("%.4lf",f[n][k]);
	return 0;
}
