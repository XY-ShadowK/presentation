#include <iostream>
using namespace std;
int i,j=0,k,n,m,h[10001],x[10001],y[10001],z[10001];
int main()
{
	cin>>n>>m>>k;
	int * a[10001];
	for(i=0;i<k;i++){
		cin>>x[i]>>y[i]>>z[i];
		h[y[i]]++;
	}
	for(i=1;i<=m;i++){
		a[i]=new int [h[i]];
	}
	for(i=0;i<k;i++){
		*a[y[i]]=z[i];
		a[y[i]]++;
	}
	for(i=1;i<=m;i++){
		a[i]-=h[i];
		for(j=0;j<h[i];j++){
			cout<<*a[i]<<' ';
			a[i]++;
		}
	}
	return 0;
} 
