#include <iostream>
using namespace std;
int a[11000],l,r,m;
int main()
{
	int i,n,x,n2;
	a[i]=-1;
	cin>>n>>n2;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=0;i<n2;i++){
		cin>>x;
		l=1;
		r=n;
		while(l<=r){
			m=(l+r)/2;
			if(a[m]<=x){
				l=m+1;
			}
			else{
				r=m-1;
			}
		}
		cout<<a[r]<<endl;
	}
	return 0;
}
