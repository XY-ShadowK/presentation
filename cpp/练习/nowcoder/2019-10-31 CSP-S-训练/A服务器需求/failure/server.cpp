#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,q;
long long a[400005],ans[400005],addition[400005],now[400005];
queue <long long> am,end;
void dp(int day)
{
	for(int i=min(m,day-1);i>0;i--){
		if(addition[day-i]){
			am.push(addition[day-i]);
			end.push(day+m);
		} 
	}
	for(int i=day;i<=n;i++){
		now[i]=now[i-1];
		while(end.front()==i){
			addition[i]+=am.front();
			am.pop();
			end.pop();
		}
		if(now[i]<a[i]){
			addition[i]+=a[i]-now[i];
			now[i]=a[i];
		}
		if(now[i]>a[i]){
			if(addition[i]){
				long long temp=now[i]-a[i];
				now[i]-=min(temp,addition[i]);
				addition[i]-=min(temp,addition[i]);
			}
		}
		ans[i]=ans[i-1]+addition[i];
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int p;
	long long c;
	dp(1);
	printf("%lld\n",ans[n]);
	for(int i=0;i<q;i++){
		scanf("%d%lld",&p,&c);
		a[p]=c;
		dp(p);
		printf("%lld\n",ans[n]);
	}
	return 0;
}
