#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
double infected,dead,percent;
int main()
{
	cin>>infected>>dead;
	percent=dead/infected*100.00;
	printf("%.3lf%%",percent);
	return 0;
}
