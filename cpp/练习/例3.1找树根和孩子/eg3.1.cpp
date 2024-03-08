#include <iostream>
#include <algorithm>
using namespace std;
typedef struct tTree{
	int kids[205],now,father;
	void birth(int kid)
	{
		kids[now]=kid;
		now++;
	}
	tTree()
	{
		now=0;
		father=-1;
	}
}tree;
tree n1[205];
int n,m;
int main()
{
	cin>>n>>m;
	int i,x,y,max[2]={0,0};
	for(i=0;i<m;i++){
		cin>>x>>y;
		n1[x].birth(y);
		n1[y].father=x;
	}
	for(i=1;i<=m;i++){
		if(n1[i].father==-1)cout<<i<<endl;
		if(n1[i].now>max[1]){
			max[0]=i;
			max[1]=n1[i].now;
		}
	}
	cout<<max[0]<<endl;
	sort(n1[max[0]].kids,n1[max[0]].kids+n1[max[0]].now);
	for(i=0;i<n1[max[0]].now;i++){
		cout<<n1[max[0]].kids[i]<<' ';
	}
	cout<<endl;
	return 0;
}
