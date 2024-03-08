#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
double a,b,c,connection[4][4],l1,l2,l3;
int main()
{
	cin>>a>>b>>c;
	connection[3][1]=b/a;
	connection[2][3]=a/c;
	connection[1][2]=c/b;
	l1=sqrt(a*connection[1][2]);
	l2=sqrt(b*connection[2][3]);
	l3=sqrt(c*connection[3][1]);
	cout<<(long long)((l1+l2+l3)*4);
	return 0;
}
