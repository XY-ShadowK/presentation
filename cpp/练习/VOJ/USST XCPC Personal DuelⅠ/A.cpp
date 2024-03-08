#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long jc[15],aa,bb;
int main()
{
	jc[0]=1;
	for(int i=1;i<=12;i++)jc[i]=jc[i-1]*i;
	cin>>aa>>bb;
	cout<<jc[min(aa,bb)];
	return 0;
}
