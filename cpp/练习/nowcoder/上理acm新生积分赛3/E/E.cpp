#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int flag=0,length;
string str;
int main()
{
	cin>>str;
	length=str.size();
	for(int i=0;i<length;i++){
		if(str[i]=='a')flag++;
		else flag--;
		if(flag<0){
			cout<<"Bad";
			return 0;
		}
	}
	if(flag)cout<<"Bad";
	else cout<<"Good";
	return 0;
}
