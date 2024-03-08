#include <iostream>
using namespace std;
int t,n;
bool winner=true;
int main()
{
	cin>>t;
	int temp;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>temp;
			if(temp==1)winner=!winner;
		}
		if(winner)cout<<"hamster"<<endl;
		else cout<<"rabbit"<<endl;
		winner=true;
	}
	return 0;
}
