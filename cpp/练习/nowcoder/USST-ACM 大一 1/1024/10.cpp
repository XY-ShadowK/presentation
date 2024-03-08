#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
string num;
int main()
{
	cin>>num;
	for(long long i=num.size()-1;i>=0;i--)cout<<num[i];
	return 0;
}
