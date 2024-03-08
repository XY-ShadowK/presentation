#include <iostream>
using namespace std;
typedef struct tSCHOOL{
	int lx[101]={0};
	bool zj=false;
	int nz[101]={0};
	int jg=0;
	int maxn=-1;
	int end=-1;
}SCHOOL;
int n,m,school=-1;
SCHOOL sch[101];
void low()
{
	int low_max=sch[0].maxn,i;
	school=0;
	for(i=0;i<n;i++){
		if(low_max>sch[i].maxn){
			low_max=sch[i].maxn;
			school=i;
		}
	}
}
void far_road(int x,int start,int cd)
{
	sch[x].zj=true;
	int i;/* 
	if(cd<sch[start].lx[x]||sch[start].lx[x]==0){
		sch[start].lx[x]=cd;
	}*/ 
	if(cd>sch[start].maxn&&x!=sch[start].end){
		sch[start].end=x;
		sch[start].maxn=cd;
	}
	for(i=0;i<sch[x].jg;i++){
		if(sch[sch[x].nz[i]].zj==false){
			far_road(sch[x].nz[i],start,cd+sch[x].lx[sch[x].nz[i]]);
		}
	}
	sch[x].zj=false;
	return;
}
int main()
{
	cin>>n>>m;
	int i,j,x,y;
	for(i=0;i<m;i++){
		cin>>x>>y;
		sch[x].nz[sch[x].jg]=y;
		sch[y].nz[sch[y].jg]=x;
		cin>>sch[x].lx[y];
		sch[y].lx[x]=sch[x].lx[y];
		sch[x].jg++;
		sch[y].jg++;
	}
	for(i=0;i<n;i++){
		far_road(i,i,0);
	}
	low();/*
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<sch[i].lx[j]<<' ';
		}
		cout<<endl;
	}
	int min1=0,ans;
	for(i=0;i<n;i++)
	  {
	  	int max1=9999999;
	  	for(j=0;j<n;j++)
	  	  if( i == j )
	  	    continue;
	  	  else if(sch[i].lx[j] > max1)
		    max1=sch[i].lx[j];
		if(max1<min1)
		  min1=max1,ans=i;
	  }
	  */
	cout<<school<<endl;
	return 0;
}
