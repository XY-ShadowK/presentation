#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=200005;
struct Edge{
	int x,y,z;
}a[maxn];
int n,m,f[maxn],ans=0;
bool cmp(const Edge & x,const Edge & y)
{
	return x.z<y.z;
}
int Getfather(int x)
{
	if(f[x]==x)return x;
	return f[x]=Getfather(f[x]);
}
void kruskal()
{
	int f1,f2,k=0,i;
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++){
		f1=Getfather(a[i].x);
		f2=Getfather(a[i].y);
		if(f1!=f2){
			ans=ans+a[i].z;
			f[f1]=f2;
			k++;
			if(k==n-1)break;
		}
	}
	if(k<n-1)cout<<"orz"<<endl;
	else cout<<ans<<endl;
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+m+1,cmp);
	kruskal();
	return 0;
}
