#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
double n,ans=1.00;
int cnt=2;
int main()
{
	cin>>n;
	for(double i=3.00;i<=2*n-1.00;i+=2.00){
		if(cnt%2)ans+=1.00/i;
		else ans-=1.00/i;
		cnt++;
	}
	printf("%.8lf",ans*4.00);
	return 0;
}
