#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("bomb.in");
ofstream fout("bomb.out");
typedef struct tMAP{
	int x=-1,y=-1;
	int bomb=0;
	int last;
	void start(int xn,int yn)
	{
		x=xn;
		y=yn;
	}
	void add(int num)
	{
		bomb++;
		last=num;
	}
}MAP;
MAP map[100000000];
int m,n,zs=0;
int find(int xn,int yn)
{
	int i;
	for(i=0;i<zs;i++){
		if(map[i].x==xn&&map[i].y==yn){
			return i;
		}
	}
	return -1;
}
int main()
{
	cin>>m>>n;
	int i,j,k,x1,x2,y1,y2,h;
	for(i=0;i<m;i++){
		cin>>x1>>y1>>x2>>y2;
		for(j=x1;j<=x2;j++){
			for(k=y1;k<=y2;k++){
				h=find(j,k);
				if(h==-1){
					map[zs].start(j,k);
					h=zs;
					zs++;
				}
				map[h].add(i+1);
			}
		}
	}
	for(i=0;i<n;i++){
		cin>>x1>>x2;
		h=find(x1,x2);
		if(h==-1){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES "<<map[h].bomb<<' '<<map[h].last<<endl;
		}
	}
	return 0;
}
