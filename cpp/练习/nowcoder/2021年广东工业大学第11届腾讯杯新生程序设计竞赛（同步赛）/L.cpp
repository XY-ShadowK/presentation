#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
using namespace std;
int t,n;
double p,ip,pf[2][105];
int main()
{
	cin>>t;
	while(t--){
		scanf("%d%lf",&n,&p);
		ip=1.00-p;
		pf[0][0]=1.00;
		pf[1][0]=0.00;
		for(int i=1;i<=n;i++){
			pf[0][i]=pf[0][i-1]*ip+pf[1][i-1]*p;
			pf[1][i]=pf[1][i-1]*ip+pf[0][i-1]*p;
		}
		printf("%.6lf\n",pf[1][n]);
	}
	return 0;
}
