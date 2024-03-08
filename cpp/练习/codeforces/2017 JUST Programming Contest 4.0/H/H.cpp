#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdio>
using namespace std;
int n,m,t,num,ans;
bool temp;
string mm;
int main()
{
	cin>>t;
	while(t--){
		cin>>n>>m;
		num=0;
		ans=2*n+2*m-4;
		for(int i=1;i<=n;i++){
			cin>>mm;
			for(int j=1;j<=m;j++){
				temp=(bool)(mm[j-1]-'0');
				if(temp){
					num++;
					if(i==1||i==n||j==1||j==m)ans--;
				}
			}
		}
		if(num<2*n+2*m-4)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
