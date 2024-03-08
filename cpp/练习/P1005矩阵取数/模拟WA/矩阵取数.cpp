#include <iostream>
#include <cmath>
#include <cstdio>
#include "high_bits"
using namespace std;
typedef struct tJZ{
	Hnum jz[80];
	int head=0,tail=-1;
	void push(string temp)
	{
		jz[++tail].x=temp;
	}
	string front()
	{
		return jz[head].x;
	}
	string back()
	{
		return jz[tail].x;
	}
	string delete_head()
	{
		head++;
		return jz[head-1].x;
	}
	string delete_tail()
	{
		tail--;
		return jz[tail+1].x;
	}
	bool empty()
	{
		return tail==-1;
	}
}JZ;
unsigned long long n,m;
JZ a[80];
int main()
{
	string sum="0";
	string temp;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>temp;
			a[i].push(temp);
		}
	}
	Hnum st1,st2,st3,st4;
	st1.x="2";
	st2.x="1";
	string tmp;
	for(unsigned long long i=0;i<m;i++){
		for(int j=0;j<n;j++){
			temp=a[j].front()<a[j].back()?a[j].delete_head():a[j].delete_tail();
			st2.x=change(i+1);
			tmp=st1^st2;
			st3.x=tmp;
			st4.x=temp;
			sum+=st3*st4;
		}
		cout<<endl;
	}
	cout<<sum;
	return 0;
}
