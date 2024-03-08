#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long n,m,fa[100005],fb[100005],ans=0;
string str;
int main()
{
	cin>>n>>m>>str;
	for(long long i=0;i<100005;i++)fa[i]=-0x3f3f3f,fb[i]=-0x3f3f3f;
	fb[0]=0;
	for(long long i=0;i<n;i++)for(long long j=m+1;j>0;j--){
		if(str[i]=='a')fa[j]=max(fa[j]+1,fb[j-1]+1);
		else fb[j]=max(fb[j]+1,fa[j-1]+1);
	}
	for(long long i=0;i<=m+1;i++)ans=max(ans,max(fa[i],fb[i]));
	cout<<ans;
	return 0;
}
