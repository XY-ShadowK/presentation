#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
typedef class tPlate{
	public :
		int x,y,r;
		bool exist;
		tPlate()
		{
			x=0,y=0,r=0;
			exist=false;
		}
}plate;
int t,xx,yy,rr,siz=0;
char type;
plate p[5005],temp;
bool pd;
bool canp(plate a)
{
	for(int i=0;i<siz;i++)if(p[i].exist){
		if(a.x<0||a.x>1000||a.y<0||a.y>1000||(p[i].r+a.r)*(p[i].r+a.r)>(p[i].x-a.x)*(p[i].x-a.x)+(p[i].y-a.y)*(p[i].y-a.y))return false;
	}
	return true;
}
int main()
{
	cin>>t;
	while(t--){
		cin>>type>>xx>>yy>>rr;
		temp.x=xx,temp.y=yy,temp.r=rr;
		if(type=='A'){
			if(siz==0||canp(temp)){
				p[siz++]=temp;
				p[siz-1].exist=true;
				cout<<"Ok"<<endl;
//				cout<<"Ok"<<' '<<p[siz].x<<' '<<p[siz].y<<' '<<p[siz].r<<endl;
			}
			else cout<<"No"<<endl;
		}
		else{
			pd=true;
			for(int i=0;i<siz;i++)if(p[i].exist&&p[i].x==xx&&p[i].y==yy&&p[i].r==rr){
				p[i].exist=false;
				cout<<"Ok"<<endl;
				pd=false;
				break;
			}
			if(pd)cout<<"No"<<endl;
		}
	}
	return 0;
}
