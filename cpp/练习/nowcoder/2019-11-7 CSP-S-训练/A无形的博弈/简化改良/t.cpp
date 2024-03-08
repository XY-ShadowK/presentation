#include <iostream>
#include <fstream>
using namespace std;
ofstream fin("t20.in");
ofstream fout("t20.out");
int main()
{
	int n;
	cin>>n;
	fin<<n<<endl;
	fout<<n*2<<endl;
	return 0;
}
