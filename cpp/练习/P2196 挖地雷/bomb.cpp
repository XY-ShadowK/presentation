#include <iostream>
using namespace std;
int n,l[25][25],count[25],sx[25],_cs,maxn=0,sx_ans[25];
bool come[25];
void fff()
{
	for(int i=0;i<=_cs;i++)sx_ans[i]=sx[i];
	return;
}
void dfs(int cs,int num,int cc)
{
	sx[cs]=num;
	come[num]=true;
	for(int i=1;i<=n;i++){
		if((!come[i])&&l[num][i])dfs(cs+1,i,cc+count[num]);
	}
	if(cc+count[num]>maxn){
		maxn=cc+count[num];
		_cs=cs;
		fff();
	}
	come[num]=false;
	return;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>count[i];
		come[i]=false;
	}
	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++){
		cin>>l[i][j];
	}
	for(int i=1;i<=n;i++)dfs(0,i,0);
	for(int i=0;i<=_cs;i++)cout<<sx_ans[i]<<' ';
	cout<<endl<<maxn<<endl;
	return 0;
}
