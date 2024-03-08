#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("5.5.in");
	ofstream fout("5.5.out");
	int a[100001],n;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	for(int i=n;i>=0;i--){
		fout<<a[i];
	}
	return 0;
}
