#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long t1,t2,t3;
int main()
{
	cin>>t1>>t2>>t3;
	cout<<t1*t2*2+t2*t3*2+t3*t1*2<<endl<<t1*t2*t3;
	return 0;
}
