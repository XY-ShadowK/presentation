#include <iostream>
using namespace std;
int m=0,a;
bool b;
int r[1000001],s[1000001][2];
void bfs(int x,int y){
	if(r[s[x][0]]==r[s[y][1]]&&r[s[x][1]]==r[s[y][0]]){
		if(s[x][0]!=-1){
			a+=2;
			bfs(s[x][0],s[y][1]);
		}
		if(s[x][1]!=-1&&x!=y){
			a+=2;
			bfs(s[x][1],s[y][0]);
		}
	}
	else b=true;
}
int main()
{
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>r[i];
	}
	for(i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(i=1;i<=n;i++){
		a=1;
		b=false;
		bfs(i,i);
		if(b){
			continue;
		}
		if(a>m){
			m=a;
		}
	}
	cout<<m;
	return 0;
}
