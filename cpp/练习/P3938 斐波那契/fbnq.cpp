#include <iostream>
#include <algorithm>
using namespace std;
long long f[65],a,b;
int m;
long long fmax(long long temp)
{
	for(int i=0;i<=59;i++)if(f[i]>=temp)return f[i-1];
}
long long fbnq()
{
	long long t1=a,t2=b;
	while(t1!=t2){
		if(t1>t2)t1-=fmax(t1);
		else t2-=fmax(t2);
	}
	return t1;
}
int main()
{
	cin>>m;
	f[0]=f[1]=1;
	for(int i=2;i<=59;i++)f[i]=f[i-1]+f[i-2];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		cout<<fbnq()<<endl;
	}
	return 0;
}
