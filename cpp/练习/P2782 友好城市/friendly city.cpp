#include <iostream>
#include <algorithm>
using namespace std;
struct tFriend{
	int south,north;
};
bool cmp(tFriend a,tFriend b)
{
	return a.south<b.south;
}
int n,f[200005];
tFriend a[200005];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].south>>a[i].north;
	sort(a,a+n-1,cmp);
	int maxn=0;
	for(int i=0;i<n;i++){
		int j=lower_bound(f,f+n,a[i].north)-f;
		if(maxn<j+1)maxn=j+1;
		f[j]=a[i].north;
	}
	cout<<maxn<<endl;
	return 0;
}
