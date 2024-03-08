#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long t,x,n,temp,js1[4]={0,1,0,-1},js2[4]={0,0,-1,-1},os1[4]={0,-1,0,1},os2[4]={0,0,1,1};
string s,str;
int main(){
	cin>>t;
	while(t--){
		scanf("%lld%lld",&x,&n);
		temp=n%4;
		if(x%2)cout<<x+n*js1[temp]+js2[temp]<<endl;
		else cout<<x+n*os1[temp]+os2[temp]<<endl;
	}
    return 0;
}
