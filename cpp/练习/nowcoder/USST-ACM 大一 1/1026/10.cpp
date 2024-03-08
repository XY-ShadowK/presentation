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
	for(int i=0;i<5;i++){
		cin>>t1;
		t2+=t1;
	}
	printf("%.1lf",t2/5);
	return 0;
}
