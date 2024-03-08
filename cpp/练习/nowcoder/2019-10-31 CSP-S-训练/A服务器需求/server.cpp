#include <bits/stdc++.h>
using namespace std;
int a[400005],ans,gd=1;
long long all;
int main()
{
	int n,m,q,i,wz,t,k=0;
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)
	{	cin>>a[i];
		all+=a[i];
		if(all/m)	{k+=all/m;all=all%m;}
		if(a[i]>a[gd])	gd=i;
	}
	if(all%m)	k++;
	if(a[gd]>ans)	ans=a[gd];
	if(k>ans)	ans=k;
	cout<<ans<<endl;
	for(i=1;i<=q;i++)
	{	ans=0;
		cin>>wz>>t;
		all-=a[wz];
		a[wz]=t;
		all+=t;
		if(wz==gd)
			for(int j=1;j<=n;j++)
				if(a[j]>a[gd])	gd=j;
				else;
		else if(t>a[gd])	gd=wz;
		k--;
		while(all<=0)	{k--;all+=m;}
		if(all/m)	{k+=all/m;all=all%m;}
		if(all%m)	k++;
		if(k>ans)	ans=k;
		if(a[gd]>ans)	ans=a[gd];
		cout<<ans<<endl;
	}
	return 0;
}
