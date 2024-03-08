#include <iostream>
#include <fstream>
using namespace std;
typedef struct tCQZQ{
	int _n;
	int zq[205];
	int now=-1;
	int score=0;
	int next()
	{
		if(now<_n-1){
			now++;
		}
		else{
			now=0;
		}
		return now;
	}
}CQ;
int n,na,nb;
int dx[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
CQ A,B;
int main()
{
	cin>>n>>na>>nb;
	A._n=na;
	B._n=nb;
	int i;
	for(i=0;i<na;i++){
		cin>>A.zq[i];
	}
	for(i=0;i<nb;i++){
		cin>>B.zq[i];
	}
	for(i=0;i<n;i++){
		A.score+=dx[A.zq[A.next()]][B.zq[B.next()]];
		B.score+=dx[B.zq[B.now]][A.zq[A.now]];
	}
	cout<<A.score<<' '<<B.score<<endl;
	return 0;
}
