#include <iostream>
using namespace std;
typedef struct tCS{
	int i=0;
	int * xl;
	void lj(int a)
	{
		xl=new int;
		*xl=a;
		xl++;
		i++;
	}
}CS;
int main()
{
	int n,m,i,l,s,j;
	CS * cs;
	cin>>n>>m;
	cs=new CS [n];
	for(i=1;i<=m;i++){
		cin>>l>>s;
		cs+=l;
		cs->lj(s);
		cs=cs-l+s;
		cs->lj(l);
		cs-=s;
	}
	cs++;
	for(i=1;i<=n;i++,cs++){
		cs->xl-=cs->i;
		for(j=1;j<=cs->i;j++,cs->xl++){
			cout<<*(cs->xl)<<' ';
		}
		cout<<endl;
	}
	return 0;
}
