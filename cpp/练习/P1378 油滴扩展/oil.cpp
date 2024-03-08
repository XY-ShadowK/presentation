#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,point[10][2],xmax,ymax,xmin,ymin;
double r[10],mr[10],maxn,s;
bool used[10];
const double pi=3.1415926535;
void getS(int num)
{
	used[num]=true;
	double tr=mr[num],temp;
	for(int i=0;i<n;i++){
		if(!used[i]||i==num)continue;
		temp=sqrt(pow(point[num][0]-point[i][0],2)+pow(point[num][1]-point[i][1],2))-r[i];
		if(tr<0||temp<0){
			tr=0;
			break;
		}
		tr=min(tr,temp);
	}
	s+=pi*tr*tr;
	r[num]=tr;
	int cs=0;
	for(int i=0;i<n;i++){
		if(used[i]){
			cs++;
			continue;
		}
		getS(i);
	}
	if(cs==n)maxn=max(maxn,s);
	s-=pi*tr*tr;
	r[num]=0;
	used[num]=false;
	return;
}
int main()
{
	cin>>n;
	int t1,t2,t3,t4;
	cin>>t1>>t2>>t3>>t4;
	xmax=max(t1,t3);
	ymax=max(t2,t4);
	xmin=min(t1,t3);
	ymin=min(t2,t4);
	int all=(xmax-xmin)*(ymax-ymin);
	for(int i=0;i<n;i++){
		cin>>t1>>t2;
		point[i][0]=t1;
		point[i][1]=t2;
		mr[i]=min(point[i][0]-xmin,point[i][1]-ymin);
		mr[i]=min(mr[i],(double)min(xmax-point[i][0],ymax-point[i][1]));
	}
	for(int i=0;i<n;i++){
		getS(i);
	}
	cout<<(int)(all-maxn+0.5)<<endl;
	return 0;
}
