#include <iostream>
#include <cstring>
#define MAXN 10
#define MAXM 10
using namespace std;
int map[12][12];//��ŵ�ͼ����߽�Ϊ-1 
int qx[200],qy[200];
void bfs(int x,int y)	//ѭ��ʵ�ֹ���
{	const int zx[4]={0,0,1,-1},zy[4]={1,-1,0,0};//���������ĸ����� 
	int tail=1,head=0,tx,ty;
	map[x][y]=-1;	//������������Ϊ��߽�-1 
	qx[tail]=x,qy[tail]=y;
	while(head!=tail)	//�ǿն��У�ͷβָ��ָ��ͬһ���ط�Ϊ�ն��� 
	{	head++,tx=qx[head],ty=qy[head];
		for (int i=0;i<4;i++)
		{	x=tx+zx[i],y=ty+zy[i];
			if (map[x][y]==-1) continue;//�߽�����ع������� 
			map[x][y]=-1;	//�����ѵ��ĵ���Ϊ��߽�-1 
			tail++,qx[tail]=x,qy[tail]=y;//���Ӷ�����Ԫ�أ�Ϊ�����������ص�λ��
		}
	}	
}
int main()
{	int i,j,ans=0;
	memset(map,255,sizeof(map));	//��߽���Ϊ-1
	for(i=1;i<=MAXN;i++)
	{	for (j=1;j<=MAXM;j++)
		{	cin>>map[i][j];
			map[i][j]=-map[i][j];//��1ת��Ϊ-1,0����0�����ڱ߽�Ҳ��Ϊ-1
		}
	}
	for(i=1;i<=MAXN;i++)
	{	if (!map[i][1]) bfs(i,1);//��1��Ϊ0�Ĺ��� 
		if (!map[i][MAXM]) bfs(i,MAXM);//��MAXM��Ϊ0�Ĺ���
		if (!map[1][i]) bfs(1,i);//��1��Ϊ0�Ĺ���
		if (!map[MAXM][i]) bfs(MAXM,i);//��MAXN��Ϊ0�Ĺ���
	}
	for(i=1;i<=MAXN;i++)
		for(j=1;j<=MAXM;j++)
			if (!map[i][j]) ans++;
	cout<<ans<<endl;
	return 0;
}
/*
������������
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 1 0 0 1 0 0
0 0 0 0 0 1 0 0 1 0
0 0 1 0 0 0 1 0 1 0
0 1 0 1 0 1 0 0 1 0
0 1 0 0 1 1 0 1 1 0
0 0 1 0 0 0 0 1 0 0
0 0 0 1 1 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0
�����������
15
*/
