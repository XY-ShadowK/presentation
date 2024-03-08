#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=20001;
int father[maxn];
int m,n,i,x,y,q;
int find(int x,int fdg)
{
	while(father[x]!=x)x=father[x];
	return x;
}
int find(int x,bool dg)
{
	if(father[x]!=x)father[x]=find(father[x],true);
	return father[x];
}
void unionn(int r1,int r2)
{
	father[r2]=r1;
}
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)father[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		int r1=find(x,true);
		int r2=find(y,true);
		if(r1!=r2)unionn(r1,r2);
	}
	cin>>q;
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(find(x,true)==find(y,true))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
