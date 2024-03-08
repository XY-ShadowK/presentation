#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
string a="0";
int n,m,f,lastans=0,opt,l,r,x,y,ni[100005],nj[100005];
int mm(int t1,int t2)
{
	if(a.find((char)t1)==-1||a.find((char)t2)==-1)return -1;
	int temp=1,i,minn=-1;
	for(i=0;;i++){
		temp=a.find((char)t1,temp+1);
		if(temp==-1)break;
		ni[i]=temp;
	}
	int a1=i;
	temp=1;
	for(i=0;;i++){
		temp=a.find((char)t2,temp+1);
		if(temp==-1)break;
		nj[i]=temp;
	}
	int a2=i;
	for(i=0;i<a1;i++){
		for(int j=0;j<a2;j++){
			temp=ni[i]-nj[j];
			temp=temp>0?temp:(-temp);
			minn=min(temp,minn);
		}
	}
	return minn;
}
int main()
{
	scanf("%d%d%d",&n,&m,&f);
	int temp;
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		a=a+(char)temp;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&opt);
		opt--;
		if(opt){
			scanf("%d%d%d",&l,&r,&x);
			if(f){
				l=l^(lastans==-1?0:lastans);
				r=r^(lastans==-1?0:lastans);
				x=x^(lastans==-1?0:lastans);
			}
			string t(r-l+1,(char)x); 
			a=a.substr(0,l)+t+a.substr(r+1,a.size()-r);
		}
		else{
			scanf("%d%d",&x,&y);
			if(f){
				x=x^(lastans==-1?0:lastans);
				y=y^(lastans==-1?0:lastans);
			}
			printf("%d",mm(x,y));
		}
	}
	return 0;
}
