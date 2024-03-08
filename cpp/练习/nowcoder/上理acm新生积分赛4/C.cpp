#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long n,ans=0;
string str;
int main()
{
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>str;
		if(str.find("zailaiyihe")!=string::npos)ans++;
	}
	cout<<ans;
	return 0;
}
