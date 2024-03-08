#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef struct tNode{
	int left,right;
	long long point,lazy_tag;
}Node;
//左区间，右区间，值，懒标记 
const int MAXN=100005;
Node tree[MAXN*4];
int n,m;
long long p;
inline int ls(int num){return (num<<1);}
//左儿子 
inline int rs(int num){return (num<<1|1);}
//右儿子 
inline int mid(int num){return ((tree[num].left+tree[num].right)>>1);}
// 二分中点 
inline void push_up_add(int num)
{
	tree[num].point=tree[ls(num)].point+tree[rs(num)].point;
	//用儿子们的值更改父亲的值 
	return;
}
//inline void push_up	默认向上维护区间和 可改造
inline void push_down(int num)
{
	int len=tree[num].right-tree[num].left+1;
	//因为是闭区间，所以区间长度等于左减去右再加一 
	tree[ls(num)].lazy_tag+=tree[num].lazy_tag;
	tree[rs(num)].lazy_tag+=tree[num].lazy_tag;
	//用父亲的懒标记更改儿子们的懒标记 
	tree[ls(num)].point+=(len-(len>>1))*tree[num].lazy_tag;
	tree[rs(num)].point+=(len>>1)*tree[num].lazy_tag;
	//利用懒标记更改节点值 因为不管是整形数据除法还是位运算都是整数 所以奇数时(len-(len>>1))!=(len>>1) 千万不要打错 
	tree[num].lazy_tag=0;
	//清空父节点懒标记
	return;
}
//inline void push_down	默认向下维护区间和 可改造 
void build(int now,int l,int r)
{
	tree[now].left=l;
	tree[now].right=r;
	if(l==r){
		scanf("%d",&tree[now].point);
		return;
	}
	//如果左区间等于右区间，表示一个点 
	build(ls(now),l,mid(now));
	build(rs(now),mid(now)+1,r);
	//二分建树 
	push_up(now);
	//建树过程中就进行向上维护 
	return;
}
void update_add(int now,int l,int r,int v)
{
	if(l<=tree[now].left&&r>=tree[now].right){
		tree[now].point+=(tree[now].right-tree[now].left+1)*v;
		tree[now].lazy_tag+=v;
		return;
	}
	//维护的操作是加法 可改造 
	if(tree[now].lazy_tag)push_down(now);
	//如果懒标记没有清空就执行向下维护 
	if(l<=mid(now))update_add(ls(now),l,r,v);
	if(r>mid(now))update_add(rs(now),l,r,v);
	//二分更新线段树 
	push_up(now);
	//回溯前向上维护
	return;
}
void update_mul(int now,int l,int r,int v)
{
	if(l<=tree[now].left&&r>=tree[now].right){
		for(int i=tree[now].left;i<=tree[now].right;i++)tree[now].point=(tree[now].point+)
		tree[now].lazy_tag+=v;
		return;
	}
	//维护的操作是加法 可改造 
	if(tree[now].lazy_tag)push_down(now);
	//如果懒标记没有清空就执行向下维护 
	if(l<=mid(now))update_add(ls(now),l,r,v);
	if(r>mid(now))update_add(rs(now),l,r,v);
	//二分更新线段树 
	push_up(now);
	//回溯前向上维护
	return;
}
long long query(int now,int l,int r)
{
	if(l<=tree[now].left&&r>=tree[now].right)return tree[now].point;
	//如果在此树范围内就直接返回 
	if(tree[now].lazy_tag)push_down(now);
	//对所有节点操作前 如果懒标记没有清空 一定要向下维护
	long long ans=0;
	if(l<=mid(now))ans=(ans+query(ls(now),l,r)%p)%p;
	if(r>mid(now))ans=(ans+query(rs(now),l,r)%p)%p;
	//二分查找 
	return ans%p;
}
int main()
{
	int t1,t2,t3,t4;
	scanf("%d%d%lld",&n,&m,&p);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		t1--;
		if(t1)cout<<query(1,t2,t3)<<endl;
		else{
			scanf("%d",&t4);
			update_add(1,t2,t3,t4);
		}
	}
	return 0;
}
