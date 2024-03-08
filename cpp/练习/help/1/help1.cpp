#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int m,k;
	int sum=0,ws;
	cin>>m>>k;
	if(m%19){
		cout<<"NO"<<endl;
		return 0;
	}
	else{
		int temp=m;
		for(ws=0;temp!=0;ws++){
			temp=temp/10;
		}
		for(int i=ws-1;i>-1;i--){
			if(((m%((int)pow(10,i+1)))/((int)pow(10,i)))==3){
				sum++;
			}
		}
		if(sum==k){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	return 0;
} 
