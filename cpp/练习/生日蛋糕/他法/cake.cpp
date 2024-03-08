#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,ans=99999999,maxd[21],mins[21],minv[21];
void dfs(int now,int s,int v,int r,int h)
{
	if(s+mins[now]>=ans)return;
	if(v+minv[now]>n)return;
	if((2*(n-v)/r+s)>=ans)return;
	if(now==0){
		if(v==n&&s<ans)ans=s;
		return;
	}
	for(register int i=min(r-1,(int)sqrt(n-v));i>=now;i--){
		if(now==m)s=i*i;
		for(register int j=min(h-1,(n-v)/i/i);j>=now;j--){
			int ts=s+i*j*2;
			dfs(now-1,ts,v+i*i*j,i,j);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(register int i=1;i<=21;i++){
		mins[i]=mins[i-1]+i*i*2;
		minv[i]=minv[i-1]+i*i*i;
	}
	dfs(m,0,0,sqrt(n),n);
	if(ans==99999999)ans=0;
	cout<<ans<<endl;
	return 0;
}
