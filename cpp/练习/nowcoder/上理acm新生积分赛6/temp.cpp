#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
using namespace std;
const int MAX_LEN=30005;
int n,m1,m2,minn=214748347,cnt=0,cell,now;
int stone[MAX_LEN]={0},pacstone[2][MAX_LEN],add[2];
bool all=false,one;
inline bool ifstone(int k)
{
	for(int i=2;i<=sqrt(k);i++)if(!(k%i))return false;
	return true;
}
inline void bk(int pac,int k)
{
	int i=1;
	while(k!=1&&i<=cnt){
		while(!(k%stone[i])){
			pacstone[pac][i]+=add[pac];
			k/=stone[i];
		}
		i++;
	}
	return;
}
int main()
{
	cin>>n>>m1>>m2;
	add[0]=m2;
	add[1]=1;
	for(int i=2;i<=MAX_LEN;i++)if(ifstone(i))stone[++cnt]=i;
	bk(0,m1);
	for(int i=1;i<=n;i++){
		scanf("%d",&cell);
		one=true;
		now=0;
		memset(&pacstone[1][0],0,sizeof(pacstone)/2);
		bk(1,cell);
		for(int j=1;j<=cnt;j++){
			if(pacstone[0][j]&&(!pacstone[1][j]))one=false;
			if(pacstone[0][j]&&pacstone[1][j]){
				if(!(pacstone[0][j]%pacstone[1][j]))now=max(now,pacstone[0][j]/pacstone[1][j]);
				else now=max(now,pacstone[0][j]/pacstone[1][j]+1);
			}
		}
		if(one){
			all=true;
			minn=min(now,minn);
		}
	}
	if(all)cout<<minn;
	else cout<<-1;
	return 0;
}
