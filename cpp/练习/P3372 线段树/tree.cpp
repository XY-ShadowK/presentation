#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
const int inf=(1<<30),maxn=100005;
using namespace std;
int n,m,cnt;
int head[maxn];
struct T{
	int l,r;
	long long sum,tag;
}t[maxn<<2];
void build(int pos,int l,int r)
{
	t[pos].l=l,t[pos].r=r;
	if(l==r)	{scanf("%d",&t[pos].sum);return;}
	build((pos<<1),l,((t[pos].l+t[pos].r)>>1));build((pos<<1|1),((t[pos].l+t[pos].r)>>1)+1,r);
	t[pos].sum=t[(pos<<1)].sum+t[(pos<<1|1)].sum;
}
void update(int pos,int l,int r,long long val)
{
	if(l<=t[pos].l&&t[pos].r<=r)
	{
		t[pos].sum+=(t[pos].r-t[pos].l+1)*val,t[pos].tag+=val;
		return;
	}
	if(t[pos].tag)
	{
		long long len=t[pos].r-t[pos].l+1;
		t[(pos<<1)].tag+=t[pos].tag,t[(pos<<1|1)].tag+=t[pos].tag;
		t[(pos<<1)].sum+=(len-(len>>1))*t[pos].tag,t[(pos<<1|1)].sum+=(len>>1)*t[pos].tag;
		t[pos].tag=0;
	}
	if(l<=((t[pos].l+t[pos].r)>>1))	update((pos<<1),l,r,val);
	if(r>((t[pos].l+t[pos].r)>>1))	update((pos<<1|1),l,r,val);
	t[pos].sum=t[(pos<<1)].sum+t[(pos<<1|1)].sum;
}
long long query(int pos,int l,int r)
{
	if(l<=t[pos].l&&t[pos].r<=r)
		return t[pos].sum;
	if(t[pos].tag)
	{
		long long len=t[pos].r-t[pos].l+1;
		t[(pos<<1)].tag+=t[pos].tag,t[(pos<<1|1)].tag+=t[pos].tag;
		t[(pos<<1)].sum+=(len-(len>>1))*t[pos].tag,t[(pos<<1|1)].sum+=(len>>1)*t[pos].tag;
		t[pos].tag=0;
	}
	long long ans=0;
	if(l<=((t[pos].l+t[pos].r)>>1))	ans+=query((pos<<1),l,r);
	if(r>((t[pos].l+t[pos].r)>>1))	ans+=query((pos<<1|1),l,r);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	register int opt,a,b;
	register long long c;
	for(register int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&opt,&a,&b);
		if(opt==1){
			scanf("%d",&c);
			update(1,a,b,c);
		}
		else
			printf("%lld\n",query(1,a,b));
	}
	return 0;
}
