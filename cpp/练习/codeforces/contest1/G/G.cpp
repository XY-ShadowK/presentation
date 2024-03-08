#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
string q;
int main()
{
	cin>>q;
	int ans=0,length;
	length=q.size();
	for(int i=0;i<length;i++){
		if(q[i]=='A')ans++;
		else ans--;
		if(ans<0){
			cout<<"Nao"<<endl;
			return 0;
		}
	}
	if(!ans)cout<<"Sim"<<endl;
	else cout<<"Nao"<<endl;
	return 0;
}
