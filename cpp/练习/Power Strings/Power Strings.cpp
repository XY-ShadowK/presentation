#include <iostream>
#include <string>
using namespace std;
string a,b;
int main()
{
	cin>>a;
	while(a!="."){
		int i,now=0;
		b=a[0];
		for(i=0;i<a.size();i++){
			if(a[i]==b[now]){
				now++;
				now=now%b.size();
//			cout<<"0 "<<b<<endl;
			}
			else{
//				cout<<b.size()<<' '<<i<<' ';
				b=b+a.substr(b.size(),i-b.size());
				now=0;
//				cout<<"1 "<<b<<' ';
				if(a[i]!=b[now]){
					b=b+a.substr(b.size(),i-b.size()+1);
					continue;
				}
				now++;
//				cout<<b<<' '<<now<<endl;
			}
		}
		cout<<a.size()/b.size()<<endl;
		cin>>a;
	}
	return 0;
}
