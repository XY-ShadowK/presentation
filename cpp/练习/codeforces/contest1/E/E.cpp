#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
long long addition[100005],n,m,q,data[100005];
int main()
{
	int t,l,r;
	cin>>n>>m>>data[0];
	addition[0]=data[0];
	for(int i=1;i<n;i++){
		cin>>data[i];
		addition[i]=addition[i-1]+data[i];
	}
	for(int i=0;i<m;i++){
		cin>>l>>r;
		if((addition[r-1]-addition[l-1]+data[l-1])%2==0)cout<<"Sim"<<endl;
		else cout<<"Nao"<<endl;
	}
	return 0;
}
