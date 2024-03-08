#include <iostream>
using namespace std;
int main()
{
	int n,i,now[2]={0,0},ans=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>now[1];
		ans+=now[0]-now[1]>=0?now[0]-now[1]:0;
		now[0]=now[1];
	}
	cout<<ans+now[1]<<endl;
	return 0;
}
