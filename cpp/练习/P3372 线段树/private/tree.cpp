#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,m;
struct node{
int l,r;
long long zhi,tag;
}tree[2000005];
long long chaxun(int now,int l,int r)
{
if(l<=tree[now].l&&r>=tree[now].r)
return tree[now].zhi;
if(tree[now].tag)
{
int len=tree[now].r-tree[now].l+1;
tree[(now<<1)].tag+=tree[now].tag,tree[(now<<1|1)].tag+=tree[now].tag;
tree[(now<<1)].zhi+=(len-(len>>1))*tree[now].tag,tree[(now<<1|1)].zhi+=(len>>1)*tree[now].tag; 
tree[now].tag=0;
}
	long long ans=0;
	if(l<=((tree[now].l+tree[now].r)>>1))	ans+=chaxun((now<<1),l,r);
	if(r>((tree[now].l+tree[now].r)>>1))	ans+=chaxun((now<<1|1),l,r);
	return ans;
}
void xiugai(int now,int l,int r,int val)
{
if(l<=tree[now].l&&r>=tree[now].r)
{
tree[now].zhi+=(tree[now].r-tree[now].l+1)*val;tree[now].tag+=val;
return;
}
if(tree[now].tag)
{
int len=tree[now].r-tree[now].l+1;
tree[(now<<1)].tag+=tree[now].tag;tree[(now<<1|1)].tag+=tree[now].tag;
tree[(now<<1)].zhi+=(len-(len>>1))*tree[now].tag,tree[(now<<1|1)].zhi+=(len>>1)*tree[now].tag; 
tree[now].tag=0;
}
if(l<=((tree[now].l+tree[now].r)>>1)) xiugai((now<<1),l,r,val);
if(r>((tree[now].l+tree[now].r)>>1)) xiugai((now<<1|1),l,r,val);
tree[now].zhi=tree[(now<<1)].zhi+tree[(now<<1|1)].zhi;
}
void build(int now,int l,int r)
{
tree[now].l=l;tree[now].r=r;
if(l==r) {cin>>tree[now].zhi;return;}
build((now<<1),l,((tree[now].l+tree[now].r)>>1));
build((now<<1|1),((tree[now].l+tree[now].r)>>1)+1,r);
tree[now].zhi=tree[(now<<1)].zhi+tree[(now<<1|1)].zhi;
}
int main(){
int n,m,t1,t2,t3,t4;
cin>>n>>m;
build(1,1,n);
for(int i=1;i<=m;i++)
{
cin>>t1>>t2>>t3;
if(t1==1)
{
cin>>t4;
xiugai(1,t2,t3,t4);
}
if(t1==2)
{
cout<<chaxun(1,t2,t3);
cout<<endl;
}
}
return 0;}
