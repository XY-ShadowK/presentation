#include <iostream>
#include <algorithm>
using namespace std;
int a[210],f[210][210],i,n,j,k,t;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}/*
	for(t=1;t<n;t++)
		for(i=1;i<=2*n-t;i++){
			j=i+t;
			for(k=i;k<j;k++){
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		}*/
	for(i=1;i<2*n;i++){
		for(j=i;j<i+n&&j<=2*n;j++)
			for(k=i;k<j;k++){
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
	}
	int maxnn=0;
	for(i=1;i<=n+1;i++){
		for(j=i;j<n+i;j++){
			maxnn=max(maxnn,f[i][j]);
		}
	}
	cout<<maxnn<<endl;
	return 0;
}
