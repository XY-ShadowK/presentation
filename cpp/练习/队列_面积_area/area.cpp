#include <iostream>
using namespace std;
int picture[11][11];
int main()
{
	int i,j,pd,ans=0;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			cin>>picture[i][j];
		}
	}
	for(i=0;i<10;i++){
		pd=0;
		for(j=0;j<10;j++){
			if(picture[i][j]){
				pd++;
			}
			if((pd%2)&&(picture[i][j]==0)){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
