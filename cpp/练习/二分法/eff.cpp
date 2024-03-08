#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;
double head[2],tail[2],jg=0;
double f(double x)
{
	return x*x-4*x-4;
}
void start(double num,bool big,bool small,int fh)
{
	double y=f(num);
	if(y==0){
		cout<<'('<<num-0.05<<','<<num+0.05<<')';
		jg=1;
		return;
	}
	if(big==true&&small==true){
		return;
	}
	if(y>0){
		if(big==false){
			big=true;
			head[0]=num;
			head[1]=y;
		}
		else{
			if(fh==0){
				if(y-f(num+1)<0){
					fh=1;
				}
			}
		}
	}
	if(y<0){
		if(small==false){
			small=true;
			tail[0]=num;
			tail[1]=y;
		}
		else{
			if(fh==1){
				if(y-f(num+1)>0){
					fh=0;
				}
			}
		}
	}
	fh==0?start(num+1,big,small,fh):start(num-1,big,small,fh);
	return;
}
void cut(double mid)
{
	if(head[0]-tail[0]<=0.1){
		return;
	}
	double y=f(mid);
	if(y==0){
		cout<<'('<<mid-0.05<<','<<mid+0.05<<')';
		return;
	}
	if(y>0&&y<head[1]){
		head[0]=mid;
		head[1]=y;
	}
	if(y<0&&y>tail[1]){
		tail[0]=mid;
		tail[1]=y;
	}
	cut((head[0]+tail[0])/2);
	return;
}
int main()
{
	double i;
	start(0,false,false,0);
	if(jg==1){
		return 0;
	}
	cut((head[0]+tail[0])/2);
	cout<<'('<<head[0]<<','<<tail[0]<<')';
	return 0;
}
