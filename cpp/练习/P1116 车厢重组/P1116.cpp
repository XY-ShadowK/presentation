#include <iostream>
using namespace std;
int n,train[10005],num=0;
bool change()
{
	int i,temp;
	bool _continue=false;
	for(i=0;i<n-1;i++){
		if(train[i]>train[i+1]){
			temp=train[i+1];
			train[i+1]=train[i];
			train[i]=temp;
			num++;
			_continue=true;
		}
	}
	return _continue;
}
int main()
{
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		cin>>train[i];
	}
	while(change());
	cout<<num<<endl;
	return 0;
}
