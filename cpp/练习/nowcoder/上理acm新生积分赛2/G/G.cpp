#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <set>
using namespace std;
int y1,y2,m1,m2,d1,d2,t1,t2,ans=0;
inline bool ts(int year,int month,int dday)
{
    bool rn=false;
    int day;
    if((year%4==0&&year%100!=0)||year%400==0)rn=true;
    if(month==2){
        if(rn)day=29;
        else day=28;
    }
    else	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)day=31;
    		else day=30;
	return dday>0&&dday<=day;
}
inline bool pd(int y)
{
	int m=(y%10)*10+(y%100)/10,d=((y%1000)/100)*10+y/1000;
	int t=y*10000+m*100+d;
	return (t>=t1&&t<=t2&&m>0&&m<=12&&ts(y,m,d));
}
int main()
{
	cin>>t1>>t2;
	y1=t1/10000;
	y2=t2/10000;
	m1=(t1%10000)/100;
	m2=(t2%10000)/100;
	d1=t1%100;
	d2=t2%100;
	for(int i=y1;i<=y2;i++)if(pd(i))ans++;
	cout<<ans;
	return 0;
}
