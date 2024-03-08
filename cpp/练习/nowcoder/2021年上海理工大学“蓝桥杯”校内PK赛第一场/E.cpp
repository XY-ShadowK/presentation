#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
double xi;
int n,w[5005],v[5005],value[10005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lf%d",&xi,v+i);
		w[i]=(long long)round(xi*10000.00);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=10000;j++)if(j>=w[i])value[j]=max(value[j],value[j-w[i]]+v[i]);
	cout<<value[10000];
	return 0;
}
