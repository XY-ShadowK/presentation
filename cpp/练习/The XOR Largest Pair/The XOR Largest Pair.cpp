#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <cstring>
using namespace std;
int n,ch[100005][2],tot;
void insert(int x)
{
	stringstream ss;
	bitset <32> num(x);
	ss<<num;
	string s;
	ss>>s;
	int len=s.size(),i,c,u=1;
	for(i=len-1;i>=0;i--){
		c=s[i]-'0';
		if(!ch[u][c])ch[u][c]=++tot;
		u=ch[u][c];
	}
	return;
}
long long find()
{
	int i,ans=0,u1=1,u2=1;
	for(i=0;;i++){
		if(ch[u1][0]&&ch[u2][1]){
			ans+=1<<i;
			u1=ch[u1][0];
			u2=ch[u2][1];
		}
		if(ch[u1][1]&&ch[u2][0]){
			ans+=1<<i;
			u1=ch[u1][1];
			u2=ch[u2][0];
		}
		if(!(ch[u1][0]||ch[u1][1]||ch[u2][0]||ch[u2][1]))return ans;
	}
}
int main()
{
	memset(ch,0,sizeof(ch));
	cin>>n;
	int t;
	tot=1;
	while(n--){
		cin>>t;
		insert(t);
	}
	for(int i=0;i<tot;i++){
		cout<<ch[i][0]<<' '<<ch[i][1]<<endl;
	}
	cout<<find();
	return 0;
} 
