#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
long long t,a,b,c,x0,x1,y0,y1,y2,mid,temp;
bool pd;
inline long long function(long long x,long long an,long long bn,long long cn)
{
	return an*x*x+bn*x+cn;
}
inline long long function(long long x)
{
	return a*x*x+b*x+c;
}
int main()
{
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>x0>>x1>>y0>>y1>>y2;
		mid=-b/(2*a);
		mid=(x1-mid)*2;
		pd=true;
		if(function(x0)>y0){
			temp=function(x1);
			if(temp<y0){
				printf("Yes\n");
				pd=false;
			}
			if(temp>y0&&temp<=y2&&function(x0,a,b-2*a*mid,a*mid*mid-b*mid+c)<y0){
				printf("Yes\n");
				pd=false;
			}
		}
		if(pd)printf("No\n");
	}
	return 0;
}
