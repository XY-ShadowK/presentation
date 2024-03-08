#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int t,ans,length,keyboard[26];
string s,str;
int main(){
	cin>>t;
	while(t--){
		cin>>s>>str;
		for(int i=0;i<26;i++)keyboard[s[i]-'a']=i;
		length=str.size();
		ans=0;
		for(int i=1;i<length;i++)ans+=abs(keyboard[str[i]-'a']-keyboard[str[i-1]-'a']);
		cout<<ans<<endl;
	}
    return 0;
}
