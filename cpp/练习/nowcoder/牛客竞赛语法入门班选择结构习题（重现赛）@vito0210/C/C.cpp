#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;
long long a,x=0,y=0,ans;
char ch;
inline bool ryy(long long year)
{
	return (((!(year%4))&&year%100)||!(year%400));
}
inline bool rym(long long month)
{
	return (month==1||month==3||month==5||month==7||month==8||month==10||month==12);
}
inline void pd(long long year,long long month,long long day)
{
	cout<<setfill('0');
	if(day>2){
		cout<<year<<'-'<<setw(2)<<month<<'-'<<setw(2)<<day-2;
		return;
	}
	if(month==1){
		cout<<year-1<<"-12-"<<(day%2?30:31);
		return;
	}
	if(month==5){
		if(ryy(year))cout<<year<<"-04-"<<(day%2?28:29);
		else cout<<year<<"-04-"<<(day%2?27:28);
		return;
	}
	if(rym(month-1)){
		cout<<year<<'-'<<setw(2)<<month-1<<'-'<<(day%2?30:31);
		return;
	}
	else{
		cout<<year<<'-'<<setw(2)<<month-1<<'-'<<(day%2?29:30);
		return;
	}
}
int main()
{
	cin>>a>>ch>>x>>ch>>y;
	pd(a,x,y);
	return 0;
}
