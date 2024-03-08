#include <iostream>
#include <algorithm>
using namespace std;
int n,x,f[1005][1005];
int main()
{
	cin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++){
		cin>>v[i]>>p[i];
		p[i]*=v[i];
	}
	for(i=1;i<=m;i++){
		for(j=n;j>=v[i];j--){
			int x=f[i-1][j];
			int y=f[i-1][j-v[i]]+p[i];
			f[i][j]=x>y?x:y;
		}
	}
	cout<<f[m][n]<<endl;
	return 0;
}
