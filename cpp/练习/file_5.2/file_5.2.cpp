#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("5.2.in");
	ofstream fout("5.2.out");
	int sum=0,x;
	while(fin>>x){
		sum+=x;
	}
	fout<<sum;
	fin.close();
	fout.close();
	return 0;
}
