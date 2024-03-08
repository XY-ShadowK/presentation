#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=100005;
int a[maxn];
int f[maxn];
int main()
{
	int n=0,l,r,mid;
	while(scanf("%d",&a[++n]))continue;
	n--;
	f[0]=999999;
	int i,ans1=0;
	for(i=1;i<=n;i++){
		if(f[ans1]>=a[i]){
			f[ans1+1]=a[i];
			ans1++;
		}
		else{
			l=0;r=ans1;
			while(l<r){
				mid=(l+r)/2;
				if(f[mid]>=a[i])l=mid+1;
				else{
					r=mid;
				}
			}
			if(l!=0)f[l]=a[i];
		}
	}
	cout<<ans1<<endl;
	memset(f,-1,sizeof(f));
	int ans2=0;
	for(i=1;i<=n;i++){
		if(f[ans2]<a[i]){
			f[ans2+1]=a[i];
			ans2++;
		}
		else{
			l=0;r=ans2;
			while(l<r){
				mid=(l+r)/2;
				if(f[mid]>=a[i])r=mid;
				else{
					l=mid+1;
				}
			}
			f[l]=a[i];
		}
	}
	cout<<ans2<<endl;
	return 0;
}
