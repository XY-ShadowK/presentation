#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int n,days[100005],t1,t2,cpy[100005],ans=0;
inline bool cmp(int aa,int bb)
{
	return aa>bb;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",days+i);
		cpy[i]=days[i];
	}
	sort(days+1,days+n+1);
	sort(cpy+1,cpy+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<days[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++){
		t2=lower_bound(cpy+n-i,cpy+n-days[i],i)-cpy;
		t2=n-t2+1;
		t1=lower_bound(days+1,days+i,i)-days;
		ans+=t2-t1;
		cout<<t2<<' '<<t1<<' '<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
