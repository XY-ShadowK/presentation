#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
const long long S=100005,MO=998244353;
long long t,a_num[S],f[S][10],add,ans,front[10]={0,0,0,1,0,0,4,6,5,7};
int len1,len2;
string str1,head="-nunhehheh";
char str2[S],ch_temp;
inline bool rule(char ch)
{
	switch(ch){
		case 'n' : return true;
		case 'u' : return true;
		case 'h' : return true;
		case 'e' : return true;
		case 'a' : {add=1;return false;}
		default : {add=0;return false;}
	}
}
int main()
{
	cin>>t;
	while(t--){
		cin>>str1;
		len1=str1.size();
		len2=1;
		ans=0;
		for(int i=0;i<len1;i++){
			ch_temp=str1[i];
			if(rule(ch_temp))str2[++len2]=ch_temp,a_num[len2]=a_num[len2-1],f[i][0]=1;
			else a_num[len2]+=add;
		}
		for(int i=2;i<=len2;i++){
			for(int j=1;j<9;j++){
				f[i][j]=f[i-1][j];
				if(str2[i]==head[j]&&f[i-1][front[j]])f[i][j]+=f[i][j-1];
				cout<<i-1<<','<<j<<' '<<f[i][j]<<"          "<<front[j]<<' '<<f[i-1][front[j]]<<endl;
				f[i-2][j]=0;
			}
			f[i][9]=f[i-1][9];
			if(str2[i]==head[9])f[i][9]+=f[i][8];
			ans=(ans+(f[i][9]*a_num[i])%MO)%MO;
			f[i-1][9]=0;
		}
		for(int i=len2-1;i<=len2;i++)for(int j=1;j<=9;j++)f[i][j]=0;
		cout<<ans<<endl;
	}
	return 0;
}
