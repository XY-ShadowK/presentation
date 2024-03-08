#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct tEdge{
	int start,end,peal;
}Edge;
bool cmp_up(const Edge & a,const Edge & b){return a.peal<b.peal;}
bool cmp_down(const Edge & a,const Edge & b){return a.peal>b.peal;}
Edge l[200005];
int n,m,b,f[100005];
int Getfather(int num)
{
	if(f[num]==num)return num;
	return f[num]=Getfather(f[num]);
}
void kruskal()
{
	for(int i=1;i<=n;i++)f[i]=i;
	int eat=0,f1,f2,k=0;
	for(int i=1;i<=m;i++){
		f1=Getfather(l[i].start);
		f2=Getfather(l[i].end);
		if(f1!=f2){
			eat+=l[i].peal;
			k++;
			f[f1]=f2;
			if(k==n-1){
				cout<<eat<<endl;
			}
		}
	}
	if(k<n-1)cout<<eat<<endl<<"N0"<<endl;
	return;
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d%d%d",&n,&m,&b);
	b--;
	int xi,yi,zi;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&l[i].start,&l[i].end,&l[i].peal);
	if(b)sort(l+1,l+m+1,cmp_down);
	else sort(l+1,l+m+1,cmp_up);
	kruskal();
	return 0;
}
