#include <iostream>
#include <algorithm>
using namespace std;
const int M=1000;
int n,head[M],tail[M],f[M][M]={0},ans;
void input()
{
	cin>>n;
	int i;
	for(i=1;i<=n;i++){
		cin>>head[i];
		head[i+n]=head[i];
	}
	for(i=1;i<n;i++){
		tail[i]=head[i+1];
		tail[i+n]=tail[i];
	}
	tail[n]=head[1];
	tail[2*n]=head[1];
}
void dp()
{
	int i,j,k,l;
	for(l=2;l<=n;l++){
		for(i=1;i<=2*n-l+1;i++){
			j=i+l-1;
			for(k=i;k<j;k++){
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+head[i]*tail[j]*tail[k]);
			}
		}
	}
	ans=0;
	for(i=1;i<=n;i++){
		ans=max(ans,f[i][i+n-1]);
	}
}
int main()
{
	input();
	dp();
	cout<<ans<<endl;
	return 0;
}
