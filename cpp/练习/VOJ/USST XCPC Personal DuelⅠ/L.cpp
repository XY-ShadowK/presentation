#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
long long k,sum=0;
int digit[100005],l,i,ans=0;
string n;
int main()
{
	cin>>k>>n;
	l=n.size();
	for(i=0;i<l;i++){
		digit[i]=n[i]-'0';
		sum+=digit[i];
	}
	if(sum>=k){
		cout<<0;
		return 0;
	}
	sort(digit,digit+l);
	for(i=0;i<l;i++){
		sum+=9-digit[i];
		if(sum>=k){
			cout<<i+1;
			break;
		}
	}
	return 0;
}
