#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <set>
using namespace std;
int n,a,b,sum=0;
int main()
{
	cin>>n>>a;
	sum=a;
	for(int i=1;i<n;i++){
		cin>>b;
		if(b>a)sum+=b-a;
		a=b;
	}
	cout<<sum;
	return 0;
}
