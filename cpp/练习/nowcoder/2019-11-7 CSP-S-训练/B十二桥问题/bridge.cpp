#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z;
long long int ans1=0,ans;
int main()
{
	int i;
	int u,v,f=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
        if(x==1||y==1) f++;
		ans1+=z;
	}
    ans=ans1;
	for(i=k+1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		ans+=z;
	}
    if(f>ceil(f*1.0/3)) printf("%lld",ans1);
    else printf("%lld",min(ans,ans1*2));
	return 0;
}
