#include <iostream>
using namespace std;
int gz[101][101];
bool found(int x,int y)
{
	bool real=false;
	if(gz[x][y]==0){
		return real;
	}
	else{
		real=true;
	}
	gz[x][y]=0;
	if(gz[x][y+1]==1){
		found(x,y+1);
		real=true;
	}
	if(gz[x+1][y]==1){
		found(x+1,y);
		real=true;
	}
	if(gz[x][y-1]==1){
		found(x,y-1);
		real=true;
	}
	if(gz[x-1][y]==1){
		found(x-1,y);
		real=true;
	}
	return real;
}
int main()
{
	int i,j,n,m,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>gz[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(found(i,j)==true){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
