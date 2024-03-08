#include <iostream>
using namespace std;
int num,round[21],ss[21][9]={{0},{7,2,4,6,10,12,16,18},{7,1,3,5,9,11,15,17},{7,2,4,8,10,14,16,20},{7,1,3,7,9,13,15,19},{6,2,6,8,12,14,18},{6,1,5,7,11,13,17},{5,4,6,10,12,16},{5,3,5,9,11,15},{6,2,4,8,10,14,20},{6,1,3,7,9,13,19},{6,2,6,8,12,18,20},{6,1,5,7,11,17,19},{5,4,6,10,16,18},{5,3,5,9,15,17},{5,2,4,8,14,16},{5,1,3,7,13,15},{5,2,6,12,14,20},{1,5,11,13,19},{4,4,10,12,18},{4,3,9,11,17}};
bool pd[21];
void output()
{
	for(int i=1;i<=num;i++){
		cout<<round[i]<<' ';
	}
	cout<<endl;
	return;
}
void dfs(int n)
{
	if(n==num+1){
		output();
		return;
	}
	for(int i=1;i<=ss[round[n]][0];i++){
		if(pd[ss[round[n]][i]]&&ss[round[n]][i]<=num){
			round[n+1]=ss[round[n]][i];
			pd[ss[round[n]][i]]=false;
			dfs(n+1);
			pd[ss[round[n]][i]]=true;
		}
	}
	return;
}
int main()
{
	cin>>num;
	round[1]=1;
	for(int i=0;i<21;i++)pd[i]=true;
	pd[1]=false;
	dfs(1);
	return 0;
}
