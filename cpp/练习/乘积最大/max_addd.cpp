#include <iostream>
#include <algorithm>
#include "high_bits"
using namespace std;
int i,j,t,k,n,num[45],f[45][10];/*
string num;
Hnum N,NUM,t1,t2;*/
int main()
{
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>num[i];
	}/*
	cin>>num;
	N.x=num;*/
	for(i=1;i<=n;i++){
		for(j=1;j<=k&&j<=i;j++){
			for(t=1;t<=j;t++){
				f[i][j]=max(f[i][j],f[i-t][j-t]*num[i]);
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
