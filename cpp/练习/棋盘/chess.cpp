#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef struct tNode{
	int x,y,color,magic,value;
}CHESS;
CHESS cur;
int n,m,ans,a[105][105],f[105][105];
queue <CHESS> q;
void expand(int x,int y)
{
	int value;
	if(x<1||x>m||y<1||y>m){
		return;
	}
	if(a[x][y]!=-1){
		value=(cur.color==a[x][y])?cur.value:cur.value+1;
		if(value<f[x][y]){
			f[x][y]=value;
			q.push((CHESS){x,y,a[x][y],1,value});
		}
		return;
	}
	if(cur.magic==0){
		return;
	}
	value=cur.value+2;
	if(value<f[x][y]){
		f[x][y]=value;
		q.push((CHESS){x,y,cur.color,0,value});
		return;
	}
}
int main()
{
	memset(a,255,sizeof(a));
	memset(f,127,sizeof(f));
	cin>>m>>n;
	int i,x,y,temp;
	for(i=0;i<n;i++){
		cin>>x>>y>>temp;
		a[x][y]=temp;
	}
	f[1][1]=0;
	q.push((CHESS){1,1,a[1][1],1,0});
	while(!q.empty()){
		cur=q.front();
		q.pop();
		expand(cur.x,cur.y+1);
		expand(cur.x+1,cur.y);
		expand(cur.x,cur.y-1);
		expand(cur.x-1,cur.y);
	}
	if(f[m][m]<20000){
		cout<<f[m][m]<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
	return 0;
}
