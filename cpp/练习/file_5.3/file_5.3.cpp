#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout;
int main()
{
	int n,i,a,b;
	string fname;
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"Please Enter File Name !"<<endl;
		cin>>fname;
		cout<<"Please Enter A and B !"<<endl;
		cin>>a>>b;
		fout.open((fname+".in").c_str());
		fout<<a<<' '<<b<<endl;
		fout.close();
		fout.open((fname+".in").c_str());
		fout<<a+b<<endl;
		fout.close();
	}
	return 0;
} 
