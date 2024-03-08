#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[105],used[105],n,len,m,minn=0,sum=0,bj;
bool cmp(const int & x,const int & y)
{
	return x>y;
}
void read()
{
	int i;
	cin>>n;
	if(n>65)n=65;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>50){
			i--;
			n--;
			continue;
		}
		minn=max(minn,a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1,cmp);
}
void dfs(int k,int last,int rest)
{
	int i,j;
	if(k==m){bj=1;return;}
	if(rest==0){
		for(i=1;i<=n;i++)
			if(!used[i]){used[i]=1;break;}
		dfs(k+1,i,len-a[i]);
	}
	for(i=last+1;i<=n;i++)
		if(!used[i]&&rest>=a[i]){
			used[i]=1;
			dfs(k,i,rest-a[i]);
			used[i]=0;
			j=i;
			while(i<n&&a[i]==a[j])i++;
			if(i==n)return;
		} 
}
void solve()
{
	int i,j;
	for(i=minn;i<=sum;i++)
		if(sum%i==0){
			memset(used,0,sizeof(used));
			len=i;
			used[1]=1;
			bj=0;
			m=sum/i;
			dfs(1,1,len-a[1]);
			if(bj){cout<<len<<endl;break;}
		}
}
int main()
{
	read();
	solve();
	return 0;
}
