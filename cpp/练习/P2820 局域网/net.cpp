#include <iostream>
#include <algorithm>
using namespace std;
typedef struct tEdge{
	int start,end,value;
	tEdge(){start=0;end=0;value=0;}
}Edge;
bool cmp(tEdge a,tEdge b){return a.value<b.value;}
int n,m,f[105],all=0;
Edge l[105];
int Getfather(int num)
{
	if(f[num]==num)return num;
	return f[num]=Getfather(f[num]);
}
void kruskal()
{
	for(int i=1;i<=n;i++)f[i]=i;
	int f1,f2,k=0,ans=0;
	for(int i=1;i<=m;i++){
		f1=Getfather(l[i].start);
		f2=Getfather(l[i].end);
		if(f1!=f2){
			k++;
			f[f1]=f2;
			ans+=l[i].value;
			if(k==n-1){
				cout<<all-ans<<endl;
				return;
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	int s,e,v;
	for(int i=1;i<=m;i++){
		cin>>l[i].start>>l[i].end>>l[i].value;
		all+=l[i].value;
	}
	sort(l+1,l+m+1,cmp);
	kruskal();
	return 0;	
}
