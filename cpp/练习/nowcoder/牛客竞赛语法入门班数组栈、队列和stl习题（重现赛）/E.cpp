#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
string num[30];
int n;
inline bool cmp(string aa,string bb)
{
	return aa+bb<bb+aa;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>num[i];
	sort(num,num+n,cmp);
	for(int i=n-1;i>=0;i--)cout<<num[i];
	return 0;
}
