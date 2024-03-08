#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
string dc[4]={"east","south","west","north"},str;
long long d=3,n;
int main()
{
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>str;
		if(str=="left"){
			d--;
			continue;
		}
		if(str=="right"){
			d++;
			continue;
		}
		if(str=="back"){
			d+=2;
			continue;
		}
	}
	cout<<dc[((d%4)+4)%4];
	return 0;
}
