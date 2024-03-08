#include <iostream>
#include <algorithm>
using namespace std;
typedef struct tProduction{
	int a,b,m,n;
}PDT;
bool cmp(PDT x,PDT y)
{
	return x.m<y.m;
}
PDT I[1001];
int t=0,at=0,bt=0,n,sx[1001],head,tail;
int imin(int ax,int bx)
{
	return ax<bx?ax:bx;
}
int main()
{
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		cin>>I[i].a;
		t+=I[i].a;
	}
	for(i=0;i<n;i++){
		cin>>I[i].b;
	}
	for(i=0;i<n;i++){
		I[i].m=imin(I[i].a,I[i].b);
		I[i].n=i+1;
	}
	sort(I,I+n,cmp);
	head=0;
	tail=n-1;
	for(i=0;i<n;i++){
		if(I[i].m==I[i].a){
			sx[head]=i;
			head++;
		}
		else{
			sx[tail]=i;
			tail--;
		}
	}
	for(i=1;i<n;i++){
		at=I[sx[i]].a;
		bt+=I[sx[i-1]].b;
		if(bt>at){
			bt-=at;
		}
		else{
			bt=0;
		}
	}
	bt+=I[sx[n-1]].b;
	t+=bt;
	cout<<t<<endl;
	for(i=0;i<n;i++){
		cout<<I[sx[i]].n<<' ';
	}
	cout<<endl;
	return 0;
}
