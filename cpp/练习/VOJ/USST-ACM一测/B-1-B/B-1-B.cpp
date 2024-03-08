#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n,ans=0,temp;
	string s;
	bool f[30];
	cin>>n>>s;
	for(int j=0;j<26;j++)f[j]=false;
	for(int i=1;i<n;i++){
		temp=0;
		for(int j=0;j<i;j++)f[s[j]-'a']=true;
		for(int j=i;j<n;j++)if(f[s[j]-'a'])temp++,f[s[j]-'a']=false;
		if(ans<temp)ans=temp;
	}
	cout<<ans<<endl;
	return 0;
}
