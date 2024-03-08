#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int ak,aak,bc[4],t,temp,cnt=0;
int main()
{
	cin>>t;
	while(t--){
		cnt++;
		for(int i=0;i<4;i++){
			cin>>temp;
			if(temp)ak=temp;
		}
		for(int i=0;i<4;i++)cin>>bc[i];
		for(int i=0;i<4;i++){
			cin>>temp;
			if(temp)aak=temp;
		}
		if(ak==aak&&bc[0]==bc[2]&&bc[1]==bc[3])cout<<"Yes!"<<endl;
		else cout<<"No!"<<endl;
		if(cnt%50==0)cout<<endl;
	}
	return 0;
}
