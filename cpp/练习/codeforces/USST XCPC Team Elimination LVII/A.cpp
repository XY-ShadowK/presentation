#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<long long,int> plli;
long long drt[200005],n,m,d,temp,cnt=1;
plli a[200005],t;
priority_queue<plli,vector<plli>,greater<plli> > q;
int main()
{
	cin>>n>>m>>d;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&temp);
		a[i].first=temp;
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	q.push(a[1]);
	drt[a[1].second]=1;
	for(long long i=2;i<=n;i++){
		t=q.top();
		if(a[i].first>t.first+d){
			q.pop();
			drt[a[i].second]=drt[t.second];
			q.push(a[i]);
		}
		else{
			drt[a[i].second]=++cnt;
			q.push(a[i]);
		}
	}
	printf("%lld\n",cnt);
	for(long long i=1;i<=n;i++)printf("%lld ",drt[i]);
	return 0;
}
