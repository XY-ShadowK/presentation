#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int l,t,ans;
string str;
int main()
{
	cin>>t;
	while(t--){
		scanf("%d",&l);
		cin>>str;
		ans=0;
		l=0;
		for(int i=0;i<str.size();i++){
			if(str[i]=='(')l++;
			if(str[i]==')'&&l>0)l--,ans++;
		}
		printf("%d\n",str.size()/2-ans);
	}
	return 0;
}
