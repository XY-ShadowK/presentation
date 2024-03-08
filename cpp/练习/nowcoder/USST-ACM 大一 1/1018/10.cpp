#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long a;
int main()
{
	cin>>a;
	cout<<((a+1)%7?(a+1)%7:7);
	return 0;
}
