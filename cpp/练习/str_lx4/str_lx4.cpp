#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	string t,s;
//	printf("%d %d",'a','A');
	cin>>t>>s;
	int ans=0,lt=t.size(),ls=s.size(),i,yt=0,ys=0;
	for(i=0;i<lt;i++){
		yt+=t[i]%32;
	}
	for(i=0;i<ls-2;i++){
		for(int j=i;j<i+lt;j++){
			ys+=s[j]%32;
		}
		if(yt==ys){ans++;}
		ys=0;
	}
	cout<<ans<<endl;
	return 0;
}
//Æ­·ÖËã·¨ ´æÔÚÂ©¶´ GG£¡£¡£¡ 
