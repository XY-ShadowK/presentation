#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
long long temp,n,k,t,ans,x,ai[200005];
queue<int> q;
int main()
{
	cin>>t;
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(long long i=0;i<n;i++){
			scanf("%lld",ai+i);
			ai[i]=ai[i]%k;
		}
		sort(ai,ai+n);
		ans=0;
		x=0;
		for(int i=n-1;i>=0;i--)if(ai[i])q.push(ai[i]);
		while(!q.empty()){
			cout<<q.front()<<' '<<ans<<' '<<x<<endl;
			system("PAUSE");
			if((q.front()+x)%k){
				if(q.front()+x>k){
					q.push(q.front());
					q.pop();
				}
				else{
					ans+=k-q.front()-x+1;
					x=(k-q.front()+1)%k;
					q.pop();
				}
			}
			else{
				ans++;
				x=(x+1)%k;
				q.pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
