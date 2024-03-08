#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int f[420005],n,m,l,r,t1,t2,pd=true;
inline bool cmp(int aa,int bb)
{
	return aa>bb;
}
inline void fc(int t)
{
	switch(t)
	{
		case 1 : {
			scanf("%d",&t2);
			if(pd)f[--l]=t2;
			else f[++r]=t2;
			break;
		}
		case 2 : {
			if(pd)l++;
			else r--;
			break;
		}
		case 3 : {
			scanf("%d",&t2);
			if(pd)f[++r]=t2;
			else f[--l]=t2;
			break;
		}
		case 4 : {
			if(pd)r--;
			else l++;
			break;
		}
		case 5 : {
			pd=!pd;
			break;
		}
		case 6 : {
			cout<<r-l+1<<endl;
			if(r-l+1){
				if(pd){
					for(int i=l;i<r;i++)printf("%d ",f[i]);
					cout<<f[r]<<endl;
				}
				else{
					for(int i=r;i>l;i--)printf("%d ",f[i]);
					cout<<f[l]<<endl;
				}
			}
			break;
		}
		case 7 : {
			if(pd)sort(f+l,f+r+1);
			else sort(f+l,f+r+1,cmp);
			break;
		}
	}
}
int main()
{
	cin>>n>>m;
	l=210003;
	r=210002;
	while(m--){
		scanf("%d",&t1);
		fc(t1);
	}
	return 0;
}
