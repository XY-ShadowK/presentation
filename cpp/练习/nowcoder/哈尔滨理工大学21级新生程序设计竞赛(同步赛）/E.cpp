#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int num,jc[50];
int main()
{
	cin>>num;
	for(int i=0;i<31;i++)jc[i]=pow(2,i);
	if(num&1)cout<<-1;
	else for(int i=30;i>0;i--){
		if(!num)return 0;
		if(num>=jc[i]){
			cout<<jc[i]<<' ';
			num-=jc[i];
		}
	}
	return 0;
}
