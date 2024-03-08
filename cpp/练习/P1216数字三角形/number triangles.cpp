#include <iostream>
#include <algorithm>
using namespace std;
int triangles[1005][1005],f[1005][1005],r;
int main()
{
	cin>>r;
	int temp;
	cin>>f[0][0];
	for(int i=1;i<r;i++){
		cin>>temp;
		f[i][0]=f[i-1][0]+temp;
		for(int j=1;j<i;j++){
			cin>>temp;
			f[i][j]=max(f[i-1][j-1],f[i-1][j])+temp;
		}
		cin>>temp;
		f[i][i]=f[i-1][i-1]+temp;
	}
	int maxn=0;
	for(int i=0;i<r;i++)maxn=max(maxn,f[r-1][i]);
	cout<<maxn<<endl;
	return 0;
}
