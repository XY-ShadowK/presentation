#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
long long n,m,newm;
int main()
{
	while(cin>>n>>m){
		newm=m;
		if(n>=m){
			for(long long i=m;i<=n;i++)cout<<i<<' ';
			cout<<endl;
			continue;
		}
		while(newm>0)newm=newm-1-n;
		if(newm)cout<<newm+n+1<<endl;
		else cout<<"You are loser"<<endl;
	}
	return 0;
}
