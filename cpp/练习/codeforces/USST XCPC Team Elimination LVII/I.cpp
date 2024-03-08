#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,f[1005];
int main()
{
	cin>>n;
	for(long long i=0;i<n;i++)cin>>f[i];
	sort(f,f+n);
	cout<<f[n-1]-f[0]+1-n;
	return 0;
}
