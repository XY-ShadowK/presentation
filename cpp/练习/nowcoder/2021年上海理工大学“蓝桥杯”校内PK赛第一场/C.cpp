#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int n,k,ai[5010];
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>ai[i];
	sort(ai,ai+n);
	for(int i=0;i<n-1;i++)if(ai[i+1]-ai[i]>k){
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	return 0;
}
