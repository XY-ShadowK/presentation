#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
string aa,bb;
int n,l1,l2,p[200005];
int main()
{
	cin>>n>>aa>>bb;
	aa='0'+aa+aa;
	bb='0'+bb;
	l1=2*n;
	l2=n;
	p[1]=0;
	int j=0;
	for(int i=1;i<l2;i++){
		while(j>0&&bb[j+1]!=bb[i+1])j=p[j];
		if(bb[j+1]==bb[i+1])j++;
		p[i+1]=j;
	}
	j=0;
	for(int i=0;i<l1;i++){
		while(j>0&&bb[j+1]!=aa[i+1])j=p[j];
		if(bb[j+1]==aa[i+1])j++;
		if(j==l2){
			cout<<"wow";
			return 0;
		}
	}
	cout<<"TAT";
	return 0;
}
