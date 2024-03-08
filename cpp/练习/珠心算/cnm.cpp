#include <iostream>
using namespace std;
int num[105],i,j,k,ans=0,aans,n;
int main()
{
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				j++;
			}
			aans=num[i]+num[j];
			for(k=0;k<n;k++){
				if(k==i||k==j){
					k++;
				}
				if(num[k]==aans){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
