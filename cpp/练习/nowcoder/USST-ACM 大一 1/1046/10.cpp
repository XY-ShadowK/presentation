#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
double h,s,v,l,k,n,t1,t2,d1,d2;
const double ss=0.00001;
long long _sta,_end;
int main()
{
	cin>>h>>s>>v>>l>>k>>n;
	t1=sqrt((h-k)/5);
	t2=sqrt(h/5);
	d1=min(s-v*t1+l,n);
	d2=max(s-v*t2,0.00);
	cout<<(long long)d1-(long long)d2;
	return 0;
}
