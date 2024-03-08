#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
long long n,aj[100005],ans=0,temp,lenj=0;
bool cmp(long long num1,long long num2)
{
	return num1>num2;
}
int main()
{
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>temp;
		if(temp%2)aj[lenj++]=temp;
		else ans+=temp;
	}
	sort(aj,aj+lenj-1,cmp);
	lenj=(lenj%2)?(lenj-1):lenj;
	for(long long i=0;i<lenj;i++)ans+=aj[i];
	cout<<ans<<endl;
	return 0;
}
