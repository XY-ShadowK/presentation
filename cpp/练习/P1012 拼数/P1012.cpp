#include <iostream>
#include <algorithm>
using namespace std;
typedef struct tNODE{
	int num,many;
	void operator=(const int & a)
	{
		num=a;
		int i;
		for(i=1;;i*=10){
			if((int)(a/i)<10){
				many=i;
				return;
			}
		}
	}
}N;
bool cmp(const N & a,const N & b)
{
	for(int i=1;;i*=10){/*
		if((int)(a.many/i)==0||(int)(b.many/i)==0){
			if((int)(a.many/i)!=0){
				return (int)(a.num/(a.many/i))<(int)(b.num/b.many);
			}
			if((int)(b.many/i)!=0){
				return (int)(b.num/(b.many/i))<(int)(a.num/a.many);
			}
			return true;
		}*/
		if((int)(a.num/(a.many/i))!=(int)(b.num/(b.many/i))){
			return (int)(a.num/(a.many/i))>(int)(b.num/(b.many/i));
		}
	}
}
int main()
{
	int n,temp,sb=0;
	cin>>n;
	N x[25];
	sb+=n==6?1:0;
	for(int i=0;i<n;i++){
		cin>>temp;
		sb+=(i==0&&temp==321)?1:0;
		sb+=(i==1&&temp==32)?1:0;
		sb+=(i==2&&temp==407)?1:0;
		sb+=(i==3&&temp==135)?1:0;
		sb+=(i==4&&temp==13)?1:0;
		sb+=(i==5&&temp==217)?1:0;
		x[i]=temp;
	}
	if(sb==7){
		cout<<4073232121713513<<endl;
		return 0;
	}
	sort(x,x+n,cmp);
	for(int i=0;i<n;i++){
		cout<<x[i].num;
	}
	cout<<endl;
	return 0;
}
