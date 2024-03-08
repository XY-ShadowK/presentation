#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("apple.in");
ofstream fout("apple.out");
int a[1000000];
int main()
{
	int i,n;
//	cin>>n;
	fin>>n;
	for(i=0;i<n;i++){
//		cin>>a[i];
		fin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
//		cout<<a[i]<<' ';
		fout<<a[i]<<' ';
	}
//	cout<<endl;
	fout<<endl;
	return 0;
}
