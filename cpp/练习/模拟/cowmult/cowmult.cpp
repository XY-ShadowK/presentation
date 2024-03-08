#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cowmult.in");
ofstream fout("cowmult.out");
int main()
{
	string a,b;
//	cin>>a>>b;
	fin>>a>>b;
	int temp=0,i,j,la=a.size(),lb=b.size();
	for(i=0;i<la;i++){
		for(j=0;j<lb;j++){
			temp+=((int)(a[i]-'0'))*((int)(b[j]-'0'));
		}
	}
//	cout<<temp<<endl;
	fout<<temp<<endl;
	return 0;
}
