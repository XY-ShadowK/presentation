#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int bz[10]={6,2,5,5,4,5,6,3,7,6};
int bbb(int a)
{
	if(a<10){
		return bz[a];
	}
	if(a>=10&&a<100){
		return bz[a%10]+bz[a/10];
	}
	return bz[a%10]+bz[(a%100)/10]+bz[a/100];
}
int main()
{
	freopen("matches.in","r",stdin);
	freopen("matches.out","w",stdout);
	int i,j,n,sum=0;
	cin>>n;
	for(i=0;i<1000;i++){
		for(j=0;j<1000;j++){
			if(bbb(i)+bbb(j)+bbb(i+j)==n-4){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
