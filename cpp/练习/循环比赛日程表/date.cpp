#include <iostream>
using namespace std;
int map[105][105];
int m;
void change(int x1,int y1,int x2,int y2)
{
	int i,j,x=(x2-x1+1)/2,y=(y2-y1+1)/2;
	cout<<"CH "<<x<<' '<<y<<endl;
/*	for(i=1;i<=x;i++){
		for(j=1;j<=y;j++){
			map[i+x][j+y]=map[i][j];
		}
	}
	for(i=x+1;i<=x2;i++){
		for(j=1;j<=y;j++){
			map[i-x][j+y]=map[i][j];
		}
	}*/
	for(j=1;j<=y;j++){
		for(i=1;i<=x;i++){
			map[i+x][j+y]=map[i][j];
		}
		for(i=x;i<=x2;i++){
			map[i-x][j+y]=map[i][j];
		}
	}
	for(i=1;i<=(1<<m);i++){
		for(j=1;j<=(1<<m);j++){
			cout<<map[j][i]<<' ';
		}
		cout<<endl;
	}
	return;
}
void divide(int x1,int y1,int x2,int y2)
{
	cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<endl;
	if(x2-x1==1&&y2-y1==1){
		change(x1,y1,x2,y2);
		return;
	}
	int x=(x2-x1+1)/2,y=(y2-y1+1)/2;
	divide(x1,y1,x2-x,y2-y);
	divide(x1+x,y1,x2,y2-y);
	divide(x1,y1+y,x2-x,y2);
	divide(x1+x,y1+y,x2,y2);
	change(x1,y1,x2,y2);
	return;
}
int main()
{
	cin>>m;
	int i,j;
	for(i=1;i<=(1<<m);i++){
		map[i][1]=i;
	}
	divide(1,1,1<<m,1<<m);
	for(i=1;i<=(1<<m);i++){
		for(j=1;j<=(1<<m);j++){
			cout<<map[j][i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
