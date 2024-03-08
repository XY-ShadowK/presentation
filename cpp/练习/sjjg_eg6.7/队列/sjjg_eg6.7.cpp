#include <iostream>
using namespace std;
int fg[105][105],m,n,ans,q[10000][2],head=0,end=0;
void tj(int x,int y)
{
	fg[x][y]=0;
	q[end][0]=x;
	q[end][1]=y;
	end++;
}
void ss(int x,int y)
{
	tj(x,y);
	int i,j;
	for(;head!=end;){
		x=q[head][0];
		y=q[head][1];
		if(fg[x][y+1]){
			tj(x,y+1);
		}
		if(fg[x+1][y]){
			tj(x+1,y);
		}
		if(fg[x][y-1]){
			tj(x,y-1);
		}
		if(fg[x-1][y]){
			tj(x-1,y);
		}
		head++;
	}
}
int main()
{
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>fg[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(fg[i][j]){
				ans++;
				ss(i,j);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
