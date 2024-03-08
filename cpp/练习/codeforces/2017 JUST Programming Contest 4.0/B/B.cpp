#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
long long temp,m,ans;
int n,t;
bool pd;
int main()
{
	cin>>t;
	while(t--){
		cin>>n>>m;
		pd=true;
		for(int i=0;i<n;i++){
			cin>>temp;
			if(temp!=-1&&pd){
				if(i-temp>=0){
					ans=(i-temp)%m;
					if(ans!=0)ans=m-ans;
					pd=false;
					continue;
				}
				else{
					ans=temp-i;
					pd=false;
					continue;
				}
			}
		}
		for(int i=0;i<n;i++){
			cout<<ans<<' ';
			ans=(ans+1)%m;
		}
		cout<<endl;
	}
	return 0;
}
