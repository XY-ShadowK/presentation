#include <iostream>
using namespace std;
int n,k,ans[210][210],l[210];
int main()
{
	int i,j;
	cin>>n>>k;
	if(k>2*n-1){cout<<0<<endl;return 0;}
	for(i=1;i<=n;i++)l[2*i-1]=l[2*i]=2*i-1;
	for(i=0;i<=2*n-1;i++)ans[i][0]=1;
	for(i=1;i<=2*n-1;i++)for(j=1;j<=l[i];j++){
		ans[i][j]=ans[i-1][j]+ans[i-1][j-1]*(l[i]-j+1);
		ans[i][j]%=504;
	}
	cout<<ans[2*n-1][k]<<endl;
	return 0;
}
