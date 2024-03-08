#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
using namespace std;
int s[105],u[105],n,ans=0;
string str;
inline int fd(int k)
{
	if(k>=n)return 0;
	return u[k]+fd(s[k+1]);
}
int main()
{
	cin>>n>>str;
	s[n]=104;
	for(int i=n-1;i>=0;i--){
		s[i]=s[i+1];
		u[i]=u[i+1];
		if(str[i]=='s'){s[i]=i;continue;}
		if(str[i]=='u'){u[i]++;continue;}
	}
	for(int i=0;i<n;i++)if(str[i]=='o')ans+=fd(s[i]);
	cout<<ans;
	return 0;
}
