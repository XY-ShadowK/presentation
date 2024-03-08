#include <iostream>
#include <algorithm>
using namespace std;
typedef struct tTree{
	int kids[2],father,now,people,myself;
	void birth(int kid)
	{
		kids[now]=kid;
		now++;
	}
	void empty()
	{
		now=0;
		father=0;
		people=0;
		myself=0;
		kids[0]=0;
		kids[1]=0;
	}
	tTree()
	{
		now=0;
		father=0;
		people=0;
		myself=0;
	}
}tree;
tree n1[105];
int n=0;
int addition(int position,int except,int far)
{
	if(position==0)return 0;
	if(except==-1)return far*n1[position].people+addition(n1[position].kids[0],3,far+1)+addition(n1[position].kids[1],3,far+1)+addition(n1[position].father,n1[position].myself,far+1);
	if(except==1)return far*n1[position].people+addition(n1[position].kids[1],3,far+1)+addition(n1[position].father,n1[position].myself,far+1);
	if(except==2)return far*n1[position].people+addition(n1[position].kids[0],3,far+1)+addition(n1[position].father,n1[position].myself,far+1);
	if(except==3)return far*n1[position].people+addition(n1[position].kids[0],3,far+1)+addition(n1[position].kids[1],3,far+1);
}
int main()
{
	int i,temp,l,r;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>temp>>l>>r;
		n1[i].people=temp;
		n1[i].birth(l);
		n1[l].father=i;
		n1[l].myself=1;
		n1[i].birth(r);
		n1[r].father=i;
		n1[r].myself=2;
	}
	n1[0].empty();
	int minn=9999999;
	for(i=1;i<=n;i++){
		temp=addition(i,-1,0);
		if(temp<minn){
			minn=temp;
		}
	}
	cout<<minn;
}
