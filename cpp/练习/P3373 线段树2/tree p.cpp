#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef struct tNode{
	int left,right;
	long long point,lazy_tag;
}Node;
//�����䣬�����䣬ֵ������� 
const int MAXN=100005;
Node tree[MAXN*4];
int n,m;
long long p;
inline int ls(int num){return (num<<1);}
//����� 
inline int rs(int num){return (num<<1|1);}
//�Ҷ��� 
inline int mid(int num){return ((tree[num].left+tree[num].right)>>1);}
// �����е� 
inline void push_up_add(int num)
{
	tree[num].point=tree[ls(num)].point+tree[rs(num)].point;
	//�ö����ǵ�ֵ���ĸ��׵�ֵ 
	return;
}
//inline void push_up	Ĭ������ά������� �ɸ���
inline void push_down(int num)
{
	int len=tree[num].right-tree[num].left+1;
	//��Ϊ�Ǳ����䣬�������䳤�ȵ������ȥ���ټ�һ 
	tree[ls(num)].lazy_tag+=tree[num].lazy_tag;
	tree[rs(num)].lazy_tag+=tree[num].lazy_tag;
	//�ø��׵�����Ǹ��Ķ����ǵ������ 
	tree[ls(num)].point+=(len-(len>>1))*tree[num].lazy_tag;
	tree[rs(num)].point+=(len>>1)*tree[num].lazy_tag;
	//��������Ǹ��Ľڵ�ֵ ��Ϊ�������������ݳ�������λ���㶼������ ��������ʱ(len-(len>>1))!=(len>>1) ǧ��Ҫ��� 
	tree[num].lazy_tag=0;
	//��ո��ڵ������
	return;
}
//inline void push_down	Ĭ������ά������� �ɸ��� 
void build(int now,int l,int r)
{
	tree[now].left=l;
	tree[now].right=r;
	if(l==r){
		scanf("%d",&tree[now].point);
		return;
	}
	//�����������������䣬��ʾһ���� 
	build(ls(now),l,mid(now));
	build(rs(now),mid(now)+1,r);
	//���ֽ��� 
	push_up(now);
	//���������оͽ�������ά�� 
	return;
}
void update_add(int now,int l,int r,int v)
{
	if(l<=tree[now].left&&r>=tree[now].right){
		tree[now].point+=(tree[now].right-tree[now].left+1)*v;
		tree[now].lazy_tag+=v;
		return;
	}
	//ά���Ĳ����Ǽӷ� �ɸ��� 
	if(tree[now].lazy_tag)push_down(now);
	//��������û����վ�ִ������ά�� 
	if(l<=mid(now))update_add(ls(now),l,r,v);
	if(r>mid(now))update_add(rs(now),l,r,v);
	//���ָ����߶��� 
	push_up(now);
	//����ǰ����ά��
	return;
}
void update_mul(int now,int l,int r,int v)
{
	if(l<=tree[now].left&&r>=tree[now].right){
		for(int i=tree[now].left;i<=tree[now].right;i++)tree[now].point=(tree[now].point+)
		tree[now].lazy_tag+=v;
		return;
	}
	//ά���Ĳ����Ǽӷ� �ɸ��� 
	if(tree[now].lazy_tag)push_down(now);
	//��������û����վ�ִ������ά�� 
	if(l<=mid(now))update_add(ls(now),l,r,v);
	if(r>mid(now))update_add(rs(now),l,r,v);
	//���ָ����߶��� 
	push_up(now);
	//����ǰ����ά��
	return;
}
long long query(int now,int l,int r)
{
	if(l<=tree[now].left&&r>=tree[now].right)return tree[now].point;
	//����ڴ�����Χ�ھ�ֱ�ӷ��� 
	if(tree[now].lazy_tag)push_down(now);
	//�����нڵ����ǰ ��������û����� һ��Ҫ����ά��
	long long ans=0;
	if(l<=mid(now))ans=(ans+query(ls(now),l,r)%p)%p;
	if(r>mid(now))ans=(ans+query(rs(now),l,r)%p)%p;
	//���ֲ��� 
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
