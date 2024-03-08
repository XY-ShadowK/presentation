#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int n,num=0,temp;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		num+=temp;
	}
	if(num%5)cout<<num/5+1<<endl;
	else cout<<num/5<<endl;
	return 0;
}
