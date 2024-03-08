#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
int main()
{
	long long n,a,b,ancestor;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		ancestor=__gcd(a,b);
		if(ancestor!=1)cout<<"Sim"<<endl;
		else cout<<"Nao"<<endl;
	}
	return 0;
}
