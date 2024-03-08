#include <iostream>
#include <string>
using namespace std;
int n,m;
string a="0";
int main()
{
	cin>>n>>m;
	int temp,l,r,c,x,ans;
	string::size_type d;
	char t;
	for(int i=1;i<=n;i++){
		cin>>temp;
		a=a+(char)temp;
	}
	for(int i=0;i<m;i++){
		cin>>temp;
		temp--;
		if(temp){
			cin>>x;
			t=a[x+1];
			a[x+1]=a[x];
			a[x]=t;
		}
		else{
			cin>>l>>r>>c;
			ans=0;
			d=0;
			while(1){
				d=a.find(c,d);
				if(d==a.npos)break;
				ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
