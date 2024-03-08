#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef struct tEdge{
	int start,end,value;
	bool operator<(const tEdge & t)
	{
		return value<t.value;
	}
}Edge;
Edge a[200005];
int n,m,f[200005];
int Getfather(int num)
{
	if(f[num]==num)return num;
	return f[num]=Getfather(f[num]);
}
void kruskal()
{
	int f1,f2,k=0;
	long long ans=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		f1=Getfather(a[i].start);
		f2=Getfather(a[i].end);
		if(f1!=f2){
			ans+=a[i].value;
			k++;
			f[f1]=f2;
			if(k==n-1)break;
		}
	}
	if(k<n-1)cout<<"orz"<<endl;
	else cout<<ans<<endl;
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].start,&a[i].end,&a[i].value);
	sort(a+1,a+m+1);
	kruskal();
	return 0;
}
