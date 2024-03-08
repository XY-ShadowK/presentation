#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
queue<int> q1,q2;
int l1,l2;
string str1,str2;
int main()
{
	cin>>l1>>l2>>str1>>str2;
	for(int i=0;i<=l2-l1;i++){
		q2=queue<int>();
		for(int j=0;j<l1;j++)if(str1[j]!=str2[i+j])q2.push(j+1);
		if(q1.size()>q2.size()||i==0)q1=q2;
	}
	cout<<q1.size()<<endl;
	while(!q1.empty()){
		cout<<q1.front()<<' ';
		q1.pop();
	}
	return 0;
}
