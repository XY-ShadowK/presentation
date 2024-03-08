#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <fstream>
using namespace std;
int n,t;
long long words[30],ans;
string ss;
bool gg1,gg2;
inline long long jc(long long num)
{
	long long a=1;
	for(long long i=2;i<=num;i++)a*=i;
	return a;
}
int main()
{
	cin>>t;
	while(t--){
		for(int i=0;i<30;i++)words[i]=0;
		gg1=false;
		gg2=true;
		cin>>n;
		cin>>ss;
		for(int i=0;i<n;i++)words[(int)ss[i]-'a']++;
		if(n%2)n--;
		for(int i=0;i<26;i++){
			if(words[i]%2==0)words[i]=jc(words[i]/2);
			else{
				if(gg1){
					cout<<0<<endl;
					gg2=false;
					break;
				}
				else{
					gg1=true;
					words[i]=jc((words[i]-1)/2);
				}
			}
		}
		ans=jc(n/2);
		if(gg2){
			for(int i=0;i<26;i++)if(words[i])ans/=words[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
