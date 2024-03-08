#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int N=5e5+5;
int ans,cnt,nxt[N],ch[N][30],bo[N],que[N];
void make(string s)
{
	int u=1,len=s.size(),c;
	for(int i=0;i<len;i++){
		c=(int)s[i]-'a';
		if(!ch[u][c]){
			ch[u][c]=++cnt;
			memset(ch[cnt],0,sizeof(ch[cnt]));
		}
		u=ch[u][c];
	} 
	bo[u]++;
	return;
}
void bfs()
{
	int i,q1,q2,u,v;
	for(i=0;i<=25;i++)ch[0][i]=1;
	que[1]=1;
	nxt[1]=0;
	for(q1=1,q2=1;q1<=q2;q1++){
		u=que[q1];
		for(i=0;i<=25;i++){
			if(!ch[u][i])ch[u][i]=ch[nxt[u]][i];
			else{
				que[++q2]=ch[u][i];
				v=nxt[u];
				nxt[ch[u][i]]=ch[v][i];
			}
		}
	}
}
void find(string s)
{
	int i,u=1,len=s.size(),c,k;
	for(i=0;i<len;i++){
		c=(int)s[i]-'a';
		k=ch[u][c];
		while(k>1){
			ans+=bo[k];
			bo[k]=0;
			k=nxt[k];
		}
		u=ch[u][c];
	}
	return;
}
int main()
{
	int t,n,i;
	string s;
	cin>>t;
	while(t--){
		ans=0;
		cnt=1;
		memset(bo,0,sizeof(bo));
		for(i=1;i<26;i++)ch[0][i]=1,ch[1][i]=0;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>s;
			make(s);
		}
		bfs();
		cin>>s;
		find(s);
		cout<<ans<<endl;
	}
	return 0;
}
