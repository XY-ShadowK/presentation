#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long sec;
int main()
{
	cin>>sec;
	cout<<sec/3600<<' '<<sec%3600/60<<' '<<sec%3600%60;
	return 0;
}
