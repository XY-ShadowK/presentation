#include <iostream>
using namespace std;
int main()
{
	int n,jm[100005],i,j,zero=0,cs=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>jm[i];
	}
	for(i=n-1;i>=0;i--){
		if(jm[i]<jm[i+1]){
			zero=i+1;
			break;
		}
	}
	while(jm[zero]!=0){
		for(i=1;i<=n;i++){
			if(jm[i]!=0){
				for(j=i;j<=n;j++){
					if(jm[j]!=0){
						jm[j]--;
					}
					else{
						break;
					}
				}
				cs++;
				break;
			}
		}
	}
	cout<<cs<<endl;
	return 0;
}
