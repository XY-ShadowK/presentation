#include <iostream>
using namespace std;
int m,s,t;
int main()
{
	cin>>m>>s>>t;
	int s1=0,t1=0,temp;
	for(t1=0;t1<t;t1++){
		if(s1>=s){cout<<"Yes"<<endl<<t1;return 0;}
		if(m>=10){m-=10;s1+=60;continue;}
		temp=((10-m)%4==0?(10-m)/4:(10-m)/4+1)+1;
		if(temp<=t-t1&&s-s1>17*temp){m+=4;continue;}
		else {s1+=17;continue;}
	}
	if(s1>=s)cout<<"Yes"<<endl<<t1;
	else cout<<"No"<<endl<<s1;
	return 0;
}
