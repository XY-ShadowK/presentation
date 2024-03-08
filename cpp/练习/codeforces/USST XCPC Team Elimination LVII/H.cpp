#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,m,x,y,_x,_y,l,w,ans;
int main()
{
	cin>>n>>m>>x>>y>>_x>>_y;
	l=_y-y+1;
	w=_x-x+1;
	ans=w*(((y-1)&1)+((m-_y)&1));
	ans+=(n-w)*(m&1);
	cout<<(ans+1)/2;
	return 0;
}
