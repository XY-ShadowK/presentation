#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int n,ai[105];
inline bool check(int aa,int bb,int cc)
{
	return (aa<bb+cc&&bb<aa+cc&&cc<aa+bb);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>ai[i];
	sort(ai,ai+n);
	for(int i=0;i<n-2;i++)if(check(ai[i],ai[i+1],ai[i+2])){
		cout<<ai[i]<<' '<<ai[i+1]<<' '<<ai[i+2];
		return 0;
	}
	cout<<"No solution";
	return 0;
}
