#include <iostream>
#include <algorithm>
using namespace std;
long long f[100005][3][2];
int n,abc[100005][3];
void dp()
{
	int i,j,k,ans=0;
	for(j=0;j<3;j++){
		f[1][0][0]=f[1][1][0]=f[1][1][1]=f[1][2][1]=0;
		f[1][j][0]=f[1][j][1]=abc[1][j];
		for(i=2;i<=n;i++){
			f[i][0][0]=max(f[i-1][1][1],f[i-1][2][1])+abc[i][0];
			f[i][1][0]=f[i-1][2][1]+abc[i][1];
			f[i][1][1]=f[i-1][0][0]+abc[i][1];
			f[i][2][1]=max(f[i-1][0][0],f[i-1][1][0])+abc[i][2];
		}
		switch(j){
			case 0 : {ans=max((long long)ans,max(f[n][1][1],f[n][2][1]));break;}
			case 1 : {ans=max((long long)ans,max(f[n][0][0],f[n][2][1]));break;}
			case 2 : {ans=max((long long)ans,max(f[n][0][0],f[n][1][0]));break;}
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	cin>>n;
	int i;
	for(i=1;i<=n;i++)cin>>abc[i][0]>>abc[i][1]>>abc[i][2];
	dp();
	return 0;
}
