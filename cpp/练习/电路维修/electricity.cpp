#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef class ElectronicRoad{
	public:
		char road;
		bool arrived;
		inline void change();
		ElectronicRoad();
		~ElectronicRoad();
}ER;
void ER::change()
{
	road=(road=='/')?'\\':'/';
	return;
}
ER::ElectronicRoad()
{
	arrived=false;
}
ER map[510][510];
int r,c,n,dist=999;
void input(int num,string t)
{
	int i;
	for(i=0;i<c;i++)map[num][i].road=t[i];
	return;
}
inline bool overspace(int x,int y)
{
	return x>=0&&x<=r&&y>=0&&y<=c;
}
inline bool d(int x,int y)
{
	return map[x][y].road=='\\';
}
inline bool god(bool a,bool b)
{
	return a==b;
}
inline bool cango(int x1,int y1,int x2,int y2)
{
	int x=x2-x1,y=y2-y1;
	if(d(x1,y1)){
		if((x==1&&y==-1)||(x==-1&&y==1))return false;
		if((x==-1&&y==-1)||(x==1&&y==1))return true;
	}
	if(!d(x1,y1)){
		if((x==-1&&y==-1)||(x==1&&y==1))return false;
		if((x==1&&y==-1)||(x==-1&&y==1))return true;
	}
	if(x==-1&&y==0){
		if(!god(d(x1,y1),d(x2,y2)))return true;
		else return false;
	}
	if(x==1&&y==0){
		if(!god(d(x1,y1),d(x2,y2)))return true;
		else return false;
	}
	if(x==0&&y==-1){
		if(!god(d(x1,y1),d(x2,y2)))return true;
		else return false;
	}
	if(x==0&&y==1){
		if(!god(d(x1,y1),d(x2,y2)))return true;
		else return false;
	}
}
void dfs(int x,int y,int v)
{
	if(x==r&&y==c){
		if(d(x,y)){
			dist=min(dist,v);
			return;
		}
		else return;
	}
	int i,j;
	for(i=-1;i<2;i++){
		for(j=-1;j<2;j++){
			if(i==0&&j==0)continue;
			if(overspace(x+i,x+j)){
				if(cango(x,y,x+i,y+i)){
					map[x][y].arrived=true;
					dfs(x,y,v);
					map[x][y].arrived=false;
				}
				else{
					map[x][y].change();
					if(cango(x,y,x+i,y+i)){
						map[x][y].arrived=true;
						dfs(x,y,v+1);
						map[x][y].arrived=false;
					}
					map[x][y].change();
				}
			}
		}
	}
}
int main()
{
	int i,j;
	string temp;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>r>>c;
		for(j=0;j<r;j++){
			cin>>temp;
			input(j,temp);
		}
		if((r+c)%2){
			cout<<"NO SOLUTION"<<endl;
		}
		dfs(0,0,0);
	}
	
}
