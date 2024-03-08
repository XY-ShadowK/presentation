#include <iostream>
using namespace std;
enum tFX{
	_up,_down,_left,_right
};
int main()
{
	int n,x,y,i,j,d,sum=0;
	int wl[1001][1001];
	cin>>n>>x>>y>>d;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>wl[i][j];
		}
	}
	switch(d){
		case _up:{
			for(i=x;i>=0;i--){
				sum+=wl[i][y];
			}
			break;
		}
		case _down:{
			for(i=x;i<n;i++){
				sum+=wl[i][y];
			}
			break;
		}
		case _left:{
			for(i=y;i>=0;i--){
				sum+=wl[x][j];
			}
			break;
		}
		case _right:{
			for(i=y;i<n;i++){
				sum+=wl[x][j];
			}
			break;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
