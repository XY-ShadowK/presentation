#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+5;
const int Z=10;
int T,n,tot,ch[N][Z];
bool bo[N];
string s;
void clear()
{
	memset(ch,0,sizeof(ch));
	memset(bo,false,sizeof(bo));
}
bool insert(string ss)
{
	int len=ss.size(),u=1;
	bool flag=false;
	for(int i=0;i<len;++i){
		int c=s[i]-'0';
		if(!ch[u][c])ch[u][c]=++tot;
		else if(i==len-1)flag=true;
		u=ch[u][c];
		if(bo[u])flag=true;
	}
	bo[u]=true;
	return flag;
}
int main()
{
	cin>>T;
	while(T--){
		cin>>n;
		tot=1;
		clear();
		bool ans=false;
		for(int i=1;i<=n;i++){
			cin>>s;
			if(insert(s))ans=true;
		}
		if(!ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
