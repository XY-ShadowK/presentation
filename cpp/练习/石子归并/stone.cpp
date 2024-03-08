#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=0x7fffffff;
const int MAXN=1000;
int n,a[MAXN],sum[MAXN]={0},Fmax[MAXN][MAXN],Fmin[MAXN][MAXN],ans1,ans2;
void init()
{
	cin>>n;
	int i;
	for(i=1;i<=n;i++){cin>>a[i];a[i+n]=a[i];Fmax[i][i]=0;Fmin[i][i]=0;Fmax[i+n][i+n]=0;Fmin[i+n][i+n]=0;}
	sum[1]=a[1];
	for(i=2;i<=2*n;i++){sum[i]=a[i]+sum[i-1];}
}
void dp()
{
	int i,j,k,l;
	for(l=2;l<=n;l++){
		for(i=1;i<=2*n-l;i++){
			j=i+l-1;
			Fmin[i][j]=MAX;
			Fmax[i][j]=0;
			for(k=i;k<j;k++){
				Fmin[i][j]=min(Fmin[i][j],Fmin[i][k]+Fmin[k+1][j]);
				Fmax[i][j]=max(Fmax[i][j],Fmax[i][k]+Fmax[k+1][j]);
			}
			Fmin[i][j]+=sum[j]-sum[i-1];
			Fmax[i][j]+=sum[j]-sum[i-1];
		}
	}
	ans1=MAX;
	ans2=0;
	for(i=1;i<=n;i++){
		ans1=min(ans1,Fmin[i][i+n-1]);
		ans2=max(ans2,Fmax[i][i+n-1]);
	}
}
int main()
{
	init();
	dp();
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}
