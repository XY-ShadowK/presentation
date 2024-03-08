#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long a,b,c,d,e,f;
int main()
{
	cin>>a>>b>>c>>d>>e>>f;
	cout<<min(a,e)+min(b,f)+min(c,d);
	return 0;
}
