#include <iostream>
using namespace std;
int n,temp[105],ni;
void sz_xd(int x)
{
	int i;
	for(i=0;i<n;i++){
		if(x==temp[i]){
			ni--;
			return;
		}
	}
	return;
}
int compare()
{
	int i,j,ans;
	for(i=0;i<n;i++){
		ans=temp[i];
		for(j=i+1;j<n;j++){
			ans+=temp[j];
			sz_xd(ans);
		}
	}
	return ni;
}
int main()
{
	int t,i,j;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		ni=n;
		for(j=0;j<n;j++){
			cin>>temp[j];
		}
		cout<<compare()<<endl;
	}
	return 0;
}
