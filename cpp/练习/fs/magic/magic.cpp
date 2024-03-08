#include <iostream>
#include <fstream>
using namespace std;
int n,hf[40][40];
void gz(int sx,int sy,int num)
{
	if(num>n*n){
		return;
	}
	if(sx==0&&sy!=n-1){
		hf[n-1][sy+1]=num;
		gz(n-1,sy+1,num+1);
		return;
	}
	if(sy==n-1&&sx!=0){
		hf[sx-1][0]=num;
		gz(sx-1,0,num+1);
		return;
	}
	if(sx==0&&sy==n-1){
		hf[sx+1][sy]=num;
		gz(sx+1,sy,num+1);
		return;
	}
	if(sx!=0&&sy!=n-1){
		if(hf[sx-1][sy+1]==0){
			hf[sx-1][sy+1]=num;
			gz(sx-1,sy+1,num+1);
			return;
		}
		else{
			hf[sx+1][sy]=num;
			gz(sx+1,sy,num+1);
			return;
		}
	}
}
int main()
{
	cin>>n;
	hf[0][n/2]=1;
	gz(0,n/2,2);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<hf[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
