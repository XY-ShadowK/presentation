#include <iostream>
using namespace std;
int main()
{
	int n,a[1000];
	cin>>n;
	int * p = new int [n];
	for(int i=0;i<n;i++){
		cin>>p[i];
		a[i]=p[i];
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
