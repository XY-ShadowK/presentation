#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long n,x,y;
int main()
{
	cin>>n>>x>>y;
	cout<<min(x,y)<<' '<<(x+y>n?x+y-n:0);
	return 0;
}
