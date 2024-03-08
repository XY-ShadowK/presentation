#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath>
using namespace std;
int n,k,num[500002],total=0;
int zhishu(int t)
{
	for(int i=2;i<=sqrt(t);i++)
	{
		if(t%i==0)
		return 1;
	}
	return 0;
}
int xuanshu(int x,int y,int z){
	cout<<x<<" "<<y<<" "<<z<<endl; 
	if(z==k)
	{
		if(!zhishu(y))
		{
			total++;
			cout<<"y = "<<y<<endl;
			return 0;
		}
		return 0;
	}
	for(int i=x;i<=n;i++)
	xuanshu(x+1,y+num[i],z+1);
}
int main(int argc, char** argv) {
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	xuanshu(1,0,0);
	cout<<total;
	return 0;
}

