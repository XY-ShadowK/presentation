#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
long long ans[1000005],p[30],temp,n,aa,bb;
char s[10];
inline int cl(int k)
{
	return k/100+k/10%10+k%10;
}
inline void add(int k)
{
	for(int i=k;i<=27;i++)p[i]++;
	return;
}
int main()
{
/*	for(int i=0;i<=9;i++)for(int j=0;j<=9;j++)for(int k=0;k<=9;k++)num[i+j+k]++;
	for(int i=0;i<=27;i++)for(int j=0;j<=27;j++)p[i-j+30]+=num[i]*num[j];
	for(int i=4;i<=57;i++)ans[i]=ans[i-1]+p[i-1];*/
	for(int i=0;i<=999;i++)for(int j=0;j<=999;j++){
		temp=abs(cl(i)-cl(j));
		p[temp]++;
		add(temp+1);
		ans[i*1000+j]=p[temp-1];
	}
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%s",s);
		aa=(s[0]-'0')*100+(s[1]-'0')*10+s[2]-'0';
		bb=(s[3]-'0')*100+(s[4]-'0')*10+s[5]-'0';
		printf("%lld\n",ans[aa*1000+bb]);
	}
	return 0;
}
