#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a[55],n,len,cnt,tot,val,mn=9999999,sum;
bool dfs(int stick,int cab,int last)
{
	if(stick>cnt)return false;
	if(cab==len)return dfs(stick+1,0,val);
	for(int i=last;i>=mn;i--){
		if(a[i]&&i+cab<=len){
			a[i]--;
			if(dfs(stick,cab+i,i))return false;
			a[i]++;
			if(cab==0||cab+i==len)return false;
		}
	}
	return false;
}
int main()
{
	cin>>tot;
	for(int i=1;i<=tot;i++){
		int x;
		scanf("%d",&x);
		if(x>50)continue;
		a[x]++;
		sum+=x;
		val=max(val,x);
		mn=min(mn,x);
	}
	for(len=val;len<=sum;len++){
		if(sum%len)continue;
		cnt=sum/len;
		if(dfs(1,0,val))break;
	}
	cout<<len;
	return 0;
}
