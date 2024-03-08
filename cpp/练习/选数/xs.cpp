#include <iostream>
#include <cmath>
using namespace std;
int n,k,zs[30],sum=0;
void pd(int a)
{
	int i;
	for(i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return;
		}
	}
	sum++;
}
void xsj(int a,int gs,int h)
{
	int i;
	if(gs==k){
		pd(a);
		return;
	}
	for(i=h;i<n;i++){
		xsj(zs[i]+a,gs+1,i+1);
	}
}
int main()
{
	int i;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>zs[i];
	}
	xsj(0,0,0);
	cout<<sum;
	return 0;
}
