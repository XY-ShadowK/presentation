#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
double t1,t2=0;
int main()
{
	cin>>t1;
	t2+=t1;
	cin>>t1;
	t2+=t1;
	cin>>t1;
	t2*=t1;
	t2/=2;
	printf("%.3lf",t2);
	return 0;
}
