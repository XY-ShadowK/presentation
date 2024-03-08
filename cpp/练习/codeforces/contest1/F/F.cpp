#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
	int n,m,k,ans1,ans2,f,d;
	cin>>n>>m>>k;
	d=ceil(n*0.7);
	if(d>k)ans1=d-k;
	else ans1=0;
	f=k+n-m;
	ans2=(int)f*100.00/n;
	if(ans2<70)ans1=-1;
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}
