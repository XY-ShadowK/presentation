#include <iostream>
#include <cstring>
using namespace std;
typedef struct tSTICK{
	int dish[21],n;
	bool push(int x)
	{
		if(n==0){dish[0]=x;n++;return true;}
		if(x<dish[n-1]){dish[n]=x;n++;return true;}
		else return false;
	}
	int pop()
	{
		if(n!=0){n--;return dish[n];}
		else return false;
	}
	tSTICK()
	{
		memset(dish,0,sizeof(dish));
		n=0;
	}
}ST;
int n;
char stick[3];
ST st[3];
int answer(int from,int to)
{
	if(!st[to].push(st[from].pop()))return 0;
	if(st[1].n==0&&st[2].n==0)return 1;
	if()
}
int main()
{
	cin>>n>>stick[0]>>stick[1]>>stick[2];
	for(int i=0;i<n;i++){
		st[1].dish[i]=i+1;
	}
	answer(1,3);
	return 0;
}
