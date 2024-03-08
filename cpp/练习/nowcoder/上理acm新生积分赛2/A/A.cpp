#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <set>
using namespace std;
long long a,n,t=0,ans=0,l;
int main()
{
	cin>>n;
	if(!n)return 0;
	cin>>a;
	l=a;
	for(long long i=1;i<n;i++){
		scanf("%ld",&a);
		if(a>l)t=1;
		else if(a<l&&t){
			t=0;
			ans++;
		}
		l=a;
	}
	cout<<ans;
	return 0;
}
