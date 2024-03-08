#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
long long a,n,ans;
int main()
{
	cin>>n>>a;
	ans=a/5;
	if(ans>n)cout<<n<<' '<<(a-5*n);
	else cout<<ans<<' '<<(a-5*ans);
	return 0;
}
