#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long a,b,c,xx;
int main()
{
	cin>>a>>b>>c;
	xx=a*b/__gcd(a,b);
	xx=xx*c/__gcd(xx,c);
	cout<<xx;
	return 0;
}
