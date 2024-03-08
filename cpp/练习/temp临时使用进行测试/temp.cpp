#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream> 
using namespace std;
ifstream fin("data.txt");
double cost,off,num;
int main()
{
	fin>>cost>>off;
	cin>>num;
	printf("%.2lf",num*cost*off);
	return 0;
}
