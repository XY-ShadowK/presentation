#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <map>
using namespace std;
int color[200005],step[200005],jump[200005],t,n;
int main()
{
	cin>>t;
	while(t--){
		cin>>n;
		map<int,int>ma;
		for(int i=1;i<=n;i++)cin>>color[i];
		for(int i=1;i<=n;i++){
			jump[i]=-1;
			if(ma[color[i]])jump[i]=ma[color[i]];
			ma[color[i]]=i;
		}
		step[0]=-1;
		for(int i=1;i<=n;i++){
			step[i]=step[i-1]+1;
			if(jump[i]!=-1)step[i]=min(step[i],step[jump[i]]+1);
		}
		cout<<step[n]<<endl;
	}
	return 0;
}
