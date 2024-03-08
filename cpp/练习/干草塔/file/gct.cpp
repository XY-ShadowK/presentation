#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int maxn=0,ck[2][20],n;
void chs(int zb,int cs)
{
	int i;
	for(i=0;i<n;i++){
		if(ck[0][zb]>ck[0][i]&&ck[1][zb]>ck[1][i]){
			chs(i,cs+1);
		}
	}
	if(cs>maxn){
		maxn=cs;
	}
}
int main()
{
	freopen("btwr.in","r",stdin);
	freopen("btwr.out","w",stdout);
	cin>>n;
	int i,j;
	for(i=0;i<n;i++){
		cin>>ck[0][i];
		cin>>ck[1][i];
	}
	for(i=0;i<n;i++){
		chs(i,1);
	}
	cout<<maxn;
	return 0;
}
