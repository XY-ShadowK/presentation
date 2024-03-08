#include <iostream>
#include <cstring>
using namespace std;
int uup[2]={0,-1};
int ddown[2]={0,1};
int lleft[2]={-1,0};
int rright[2]={1,0};
int map[12][12],ans=0;
int rx,ry;
bool test(int x,int y,int direction)
{
	switch(direction){
		case 1 : {
			return map[x+rright[0]][y+rright[1]];
		}
		case 2 : {
			return map[x+uup[0]][y+uup[1]];
		}
		case 3 : {
			return map[x+lleft[0]][y+lleft[1]];
		}
		case 4 : {
			return map[x+ddown[0]][y+ddown[1]];
		}
		case 5 : {
			return map[x+rright[0]+ddown[0]][y+rright[1]+ddown[1]];
		}
		case 6 : {
			return map[x+rright[0]+uup[0]][y+rright[1]+uup[1]];
		}
		case 7 : {
			return map[x+lleft[0]+uup[0]][y+lleft[1]+uup[1]];
		}
		case 8 : {
			return map[x+lleft[0]+ddown[0]][y+lleft[1]+ddown[1]];
		}
	}
}
void point(int x,int y,int direction)
{
	if(direction!=1&&test(x,y,1)){
		ans+=y-1;
		point(x+rright[0],y+rright[1],3);
	}
	if(direction!=2&&test(x,y,2)){
		point(x+uup[0],y+uup[1],4);
	}
	if(direction!=3&&test(x,y,3)){
		ans-=y;
		point(x+lleft[0],y+lleft[1],1);
	}
	if(direction!=4&&test(x,y,4)){
		point(x+ddown[0],y+ddown[1],2);
	}
	if(direction!=5&&test(x,y,5)){
		point(x+rright[0]+ddown[0],y+rright[1]+ddown[1],7);
	}
	if(direction!=6&&test(x,y,6)){
		point(x+rright[0]+uup[0],y+rright[1]+uup[1],8);
	}
	if(direction!=7&&test(x,y,7)){
		point(x+lleft[0]+uup[0],y+lleft[1]+uup[1],5);
	}
	if(direction!=8&&test(x,y,8)){
		point(x+lleft[0]+ddown[0],y+lleft[1]+ddown[1],6);
	}
}
int main()
{
	int i,j;
	memset(map,255,sizeof(map));
	for(i=1;i<=10;i++){	
		for(j=1;j<=10;j++){
			cin>>map[i][j];
		}
	}
	for(i=1;i<=10;i++){	
		for(j=1;j<=10;j++){
			if(map[i][j]){
				rx=i;
				ry=j;
				point(i,j,0);
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	return 0;
}
