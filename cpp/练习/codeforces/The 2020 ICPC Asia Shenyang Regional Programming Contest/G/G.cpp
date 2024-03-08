#include <iostream>
#include <algorithm>
using namespace std;
long long n,k,a[1005],ans=0;
bool cmp(long long aa,long long bb)
{
	return aa>bb;
}
int main()
{
	cin>>n>>k;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,cmp);
	for(long long i=0;i<k;i++)ans+=a[i];
	cout<<ans<<endl;
	return 0;
}
