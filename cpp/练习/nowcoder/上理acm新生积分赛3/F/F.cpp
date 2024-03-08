#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int f[1250][1250],length;
string str;
int main()
{
	cin>>str;
	length=str.size();
    for(int i=0;i<length;i++){
		str[i]=tolower(str[i]);
		f[i][i]=1;
    }
	for(int i=length-1;i>=0;i--)for(int j=i+1;j<length;j++){
		if (str[i]==str[j]) f[i][j]=f[i+1][j-1]+2;
		else f[i][j]=max(f[i+1][j],f[i][j-1]);
	}
    cout<<length-f[0][length-1];
	return 0;
}
