#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct tMagicalBoard{
	int a[2][4];
}MB;
int jc[10]={1,1,2,6,24,120,720,5040},g,st,prt[50005],b[1000000]={0},step[50005];
char a[50005];
MB start,goal,q[90000];
int turn(MB x)
{
	int i,j,res=0,t[8],s;
	for(i=0;i<4;i++)t[i]=x.a[0][i];
	for(i=3;i>=0;i--)t[7-i]=x.a[1][i];
	for(i=0;i<8;i++){
		s=0;
		for(j=i+1;j<=7;j++)if(t[j]<t[i])s++;
		res+=jc[7-i]*s;
	}
	return res;
}
MB change(int way,int num)
{
	MB temp;
	int i;
	if(way==1){
		for(i=0;i<4;i++)temp.a[0][i]=q[num].a[1][i];
		for(i=0;i<4;i++)temp.a[1][i]=q[num].a[0][i];
		return temp;
	}
	if(way==2){
		temp.a[0][0]=q[num].a[0][3];
		temp.a[1][0]=q[num].a[1][3];
		for(i=1;i<4;i++)temp.a[0][i]=q[num].a[0][i-1];
		for(i=1;i<4;i++)temp.a[1][i]=q[num].a[1][i-1];
		return temp;
	}
	if(way==3){
		temp.a[0][0]=q[num].a[0][0];
		temp.a[0][3]=q[num].a[0][3];
		temp.a[1][0]=q[num].a[1][0];
		temp.a[1][3]=q[num].a[1][3];
		temp.a[0][1]=q[num].a[1][1];
		temp.a[0][2]=q[num].a[0][1];
		temp.a[1][2]=q[num].a[0][2];
		temp.a[1][1]=q[num].a[1][2];
		return temp;
	}
}
void print(int num)
{
	if(num==1)return;
	print(prt[num]);
	cout<<a[num];
}
void bfs()
{
	int op=1,cl=1,i,t;
	MB temp;
	q[1]=start;
	step[1]=0;
	prt[1]=1;
	while(op<=cl){
		for(i=1;i<=3;i++){
			temp=change(i,op);
			t=turn(temp);
			if(!b[t]){
				q[++cl]=temp;
				step[cl]=step[op]+1;
				b[t]=1;
				prt[cl]=op;
				a[cl]=char('A'+i-1);
				if(t==g){
					cout<<step[cl]<<endl;
					print(cl);
					return;
				}
			}
		}
		op++;
	}
}
int main()
{
	int i;
	for(i=0;i<4;i++)start.a[0][i]=i+1;
	for(i=3;i>=0;i--)start.a[1][i]=8-i;
	st=turn(start);
	b[st]=1;
	for(i=0;i<4;i++)cin>>goal.a[0][i];
	for(i=3;i>=0;i--)cin>>goal.a[1][i];
	g=turn(goal);
	if(g==st){
		cout<<0;
		return 0;
	}
	bfs();
	return 0;
}
