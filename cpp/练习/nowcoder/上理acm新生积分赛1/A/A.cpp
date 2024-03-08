#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <set>
using namespace std;
long long a,b,c,k,l,m;
int main()
{
	cin>>a>>b>>c;
	k=sqrt(1.0*a*c/b);
	l=sqrt(1.0*a*b/c);
	m=sqrt(1.0*b*c/a);
	cout<<(4*(k+l+m))<<endl;
	return 0;
}
