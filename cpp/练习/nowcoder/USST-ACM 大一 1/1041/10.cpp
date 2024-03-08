#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long n;
int main()
{
	cin>>n;
	cout<<(n%2?n/2+1:n/2);
	return 0;
}
