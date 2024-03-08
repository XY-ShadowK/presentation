#include <iostream>
#include <string>
using namespace std;
int n,ans=0,temp=0,l[300005]={0},r[300005]={0};
int main()
{
	
	string str;
	cin>>n>>str;
	if(str[0]=='W')l[0]++;
	else r[0]++;
	for(int i=1;i<n;i++){
		if(str[i]=='W'){
			l[i]=l[i-1]+1;
			r[i]=r[i-1];
		}
		else{
			r[i]=r[i-1]+1;
			l[i]=l[i-1];
		}
	}
	ans=r[n-1]-r[0];
	for(int i=1;i<n;i++){
		temp=l[i-1]+r[n-1]-r[i];
		if(temp<ans)ans=temp;
	}
	cout<<ans<<endl;
 	return 0;
}
