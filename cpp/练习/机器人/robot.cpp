#include <bits/stdc++.h>
using namespace std;
int n,m1,m2,cnt,now,pre,minv,ans=INT_MAX;
int dp[2][1005],p[50005],t[1005],level[1000005];

bool vis[1000005];

inline int getdp()
{
    now=1;
    for (int i=1;i<=cnt;i++)
	{
        if (i>p[1])dp[now][i]=m1;
        else if (i<p[1])dp[now][i]=m2;
        else dp[now][i]=0;
    }
    for (int i=2;i<=n;i++)
	{
        now=1-now;pre=1-now;
        minv=dp[now][1]=dp[pre][1];
        for (int j=2;j<=cnt;j++)
		{
            minv=min(minv,dp[pre][j]);
            dp[now][j]=minv;
        }
        for (int j=1;j<p[i];j++)dp[now][j]+=m2;
        for (int j=p[i]+1;j<=cnt;j++)dp[now][j]+=m1;
    }
    int res=INT_MAX;
    for (int i=1;i<=cnt;i++)res=min(res,dp[now][i]);
    return res;
}

int main(){
    freopen ("robot.in","r",stdin);
    freopen ("robot.out","w",stdout);
    cin>>n>>m1>>m2;
    for (int i=1;i<=n;i++)
	{
        cin>>p[i];
        if (!vis[p[i]])
		t[++cnt]=p[i];
        vis[p[i]]=true;
    }
    
    sort(t+1,t+cnt+1);
    for (int i=1;i<=cnt;i++)
	level[t[i]]=i;
    for (int i=1;i<=n;i++)
	p[i]=level[p[i]];
	
    ans=getdp();
    reverse(p+1,p+n+1);
    ans=min(ans,getdp());
    cout<<ans<<'\n';
    return 0;
}
