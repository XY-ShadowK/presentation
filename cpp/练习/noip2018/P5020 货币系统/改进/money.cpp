#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int tn[50000],n,ni,temp[105];
int compare()
{
	ni=0;
	int i,j;
	for(i=0;i<n;i++){
		if(tn[temp[i]]==1){
			continue;
		}
		else{
			ni++;
			tn[temp[i]]=1;
			for(j=0;j<temp[n-1]+1;j++){
				if(tn[j]==1){
					tn[j+temp[i]]=1;
				}
			}
		}
	}
	return ni;
}
int main()
{
	int i,j,t;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		for(j=0;j<n;j++){
			cin>>temp[j];
		}
		memset(tn,0,sizeof(tn));
		sort(temp,temp+n);
		cout<<compare()<<endl;
	}
	return 0;
}
