#include <iostream>
#include <algorithm>
using namespace std;
typedef struct tQueue
{
	long long a;
	int direction;
}tqueue;
bool cmp(tqueue x,tqueue y)
{
	return x.a<y.a;
}
int n,ans=0,maxn=-1;
tqueue ai[1000005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai[i].a;
		ai[i].direction=i;
	}
	sort(ai+1,ai+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(ai[i].direction>i)maxn=maxn>ai[i].direction?maxn:ai[i].direction;
		else if(i>=maxn)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
