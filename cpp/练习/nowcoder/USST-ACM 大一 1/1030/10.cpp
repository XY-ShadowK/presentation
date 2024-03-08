#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
double a,b,c,p;
int main()
{
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	printf("circumference=%.2lf area=%.2lf",a+b+c,sqrt(p*(p-a)*(p-b)*(p-c)));
	return 0;
}
