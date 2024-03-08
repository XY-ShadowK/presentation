#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
int a[10001]={0},b[10001],lens,fz[1000];
char s[10001];
void cton(int *a)
{
	int i;
	for(i=0;i<lens;i++){
		a[i+1]=fz[s[i]];
	}
}
int main()
{
	fz['{']=1;
	fz['[']=2;
	fz['(']=3;
	fz['<']=4;
	fz['>']=5;
	fz[')']=6;
	fz[']']=7;
	fz['}']=8;
	int i,n,t=0,m,j,k;
	cin>>m;
	for(i=1;i<=n;i++){
		memset(s,0,sizeof(s));
		cin>>s;
		t=0;
		lens=strlen(s);
		cton(a);
		for(j=1;j<=lens;j++){
			if(a[j]<=4)	if(a[j]>=b[t])b[++t]=a[j];
						else break;
			if(a[j]>=5)	if(a[j]+b[t]==9)t--;
						else t++;
		}
		if(t==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl; 
	}
	return 0;
}
