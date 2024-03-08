#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string c,cc;
unsigned long long s,h[1000005],bn[1000005];
const unsigned long long b=1000000007;
int Hash(int now,int k,bool a)
{
	int i;
	unsigned long long re=(unsigned long long)cc[now];
	for(i=now+1;i<=k;i++){
		re=re*b+(unsigned long long)cc[i];
	}
	return re;
}
void Hash(int now)
{
	h[now+1]=h[now]*b+(unsigned long long)c[now+1];
}
void change()
{
	int i,sc=c.size(),scc=cc.size();
	for(i=0;i<sc;i++){
		c[i]=c[i]-'A'+1;
	}
	for(i=0;i<scc;i++){
		cc[i]=cc[i]-'A'+1;
	}
}
int main()
{
	int t;
	bn[0]=1;
	for(t=1;t<100005;t++){
		bn[t]=pow(b,t);
	}
	cin>>t;
	for(;t>0;t--){
		cin>>cc>>c;
		change();
		unsigned long long m=c.size(),n=cc.size();
		s=Hash(0,n-1,true);
		int i;
		h[0]=c[0];
		for(i=0;i<m-1;i++){
			Hash(i);
		}
		int j,ans=0;
		for(i=0;i<m-n;i++){
			if(i==0){
				if(h[i+n-1]==s){
					ans++;
				}
			}
			else	if((h[i+n-1]-h[i-1]*bn[n-1])==s){
						ans++;
					}
		}
		cout<<ans<<endl;
	}
	return 0;
}
