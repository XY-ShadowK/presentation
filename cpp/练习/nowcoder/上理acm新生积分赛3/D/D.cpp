#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int n,a[105],s,ans=0;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	s=a[0]+a[1];
	ans+=a[0]*a[1];
	for(int i=2;i<n;i++){
		ans+=s*a[i];
		s+=a[i];
	}
	cout<<ans;
	return 0;
}
