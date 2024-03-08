#include <iostream>
using namespace std;
int a[1001];
void _1i()
{
	int i;
	cin>>i;
	cout<<a[i-1]<<endl;
}
void _2iv(int n)
{
	int i,j,v;
	cin>>i>>v;
	for(j=n;j>i-2;j--){
		a[j]=a[j-1];
	}
	a[i-1]=v;
}
void _3i(int n)
{
	int i,j;
	cin>>i;
	for(j=i-1;j<n-1;j++){
		a[j]=a[j+1];
	}
}
void _4ij(int n)
{
	int i,j,m;
	cin>>i>>j;
	m=a[i];
	a[i]=a[j];
	a[j]=m;
}
int main()
{
	int n,m,cz,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>cz;
		switch(cz){
			case 1 : {_1i();break;}
			case 2 : {_2iv(n);n++;break;}
			case 3 : {_3i(n);n--;break;}
			case 4 : {_4ij(n);break;}
		}
	}
	return 0;
}
