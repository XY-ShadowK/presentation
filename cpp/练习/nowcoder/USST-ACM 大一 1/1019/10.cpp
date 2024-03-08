#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long a,n;
int main()
{
	cin>>a>>n;
	cout<<((a+n)%7?(a+n)%7:7);
	return 0;
}
