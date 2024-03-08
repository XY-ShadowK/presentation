#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
long long a,b;
inline char pd(long long x,long long y)
{
	if(!(x-y))return '=';
	return x<y?'<':'>';
}
int main()
{
	cin>>a>>b;
	cout<<pd(a,b);
	return 0;
}
