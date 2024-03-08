#include <iostream>
#include <cmath>
using namespace std;
int n,m,data[1000005]={1,2,3},now=3,t;
bool can[10000005];
bool pd(int num)
{
	for(int j=1;data[j]<(int)sqrt(num)+1;j++)if(!(num%data[j]))return false;
	data[now++]=num;
	can[num]=true;
	return true;
}
int main()
{
	cin>>n>>m;
	can[1]=false;
	can[2]=true;
	can[3]=true;
	for(int i=6;i<=n;i+=6){
		pd(i-1);
		pd(i+1);
	}
	int t;
	for(int i=0;i<m;i++){
		cin>>t;
		if(can[t])cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
