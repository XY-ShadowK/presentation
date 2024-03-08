#include <iostream>
#include <algorithm>
using namespace std;
int n,l[100005],r[100005];
int main()
{
	cin>>n;
	int t1,t2=n,maxn=0;
	for(int i=1;i<=n;i++){
		cin>>t1;
		t2=t2+t1*2-1;
		if(!l[t2]&&t2!=n)l[t2]=i;
		else r[t2]=i;
	}
	for(int i=0;i<=2*n;i++)maxn=max(maxn,r[i]-l[i]);
	cout<<maxn<<endl;
	return 0;
}
