#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define RG register int
#define rep(i,a,b)	for(RG i=a;i<=b;i++)
#define per(i,a,b)	for(RG i=a;i>=b;i--)
#define inf (1<<30)
#define maxn 100005
#define ll long long
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid ((t[pos].l+t[pos].r)>>1)
using namespace std;
int n,m,cnt;
int head[maxn];
struct T{
	int l,r;
	ll sum,tag;
}t[maxn<<2];
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

void build(int pos,int l,int r)
{
	t[pos].l=l,t[pos].r=r;
	if(l==r)	{t[pos].sum=read();return;}
	build(ls,l,mid);build(rs,mid+1,r);
	t[pos].sum=t[ls].sum+t[rs].sum;
}

void update(int pos,int l,int r,ll val)
{
	if(l<=t[pos].l&&t[pos].r<=r)
	{
		t[pos].sum+=(t[pos].r-t[pos].l+1)*val,t[pos].tag+=val;
		return;
	}
	if(t[pos].tag)
	{
		ll len=t[pos].r-t[pos].l+1;
		t[ls].tag+=t[pos].tag,t[rs].tag+=t[pos].tag;
		t[ls].sum+=(len-(len>>1))*t[pos].tag,t[rs].sum+=(len>>1)*t[pos].tag;
		t[pos].tag=0;
	}
	if(l<=mid)	update(ls,l,r,val);
	if(r>mid)	update(rs,l,r,val);
	t[pos].sum=t[ls].sum+t[rs].sum;
}

ll query(int pos,int l,int r)
{
	if(l<=t[pos].l&&t[pos].r<=r)
		return t[pos].sum;
	if(t[pos].tag)
	{
		ll len=t[pos].r-t[pos].l+1;
		t[ls].tag+=t[pos].tag,t[rs].tag+=t[pos].tag;
		t[ls].sum+=(len-(len>>1))*t[pos].tag,t[rs].sum+=(len>>1)*t[pos].tag;
		t[pos].tag=0;
	}
	ll ans=0;
	if(l<=mid)	ans+=query(ls,l,r);
	if(r>mid)	ans+=query(rs,l,r);
	return ans;
}

int main()
{
	n=read(),m=read();
	build(1,1,n);
	RG opt,a,b;
	register ll c;
	rep(i,1,m)
	{
		opt=read(),a=read(),b=read();
		if(opt==1)
			c=read(),update(1,a,b,c);
		else
			printf("%lld\n",query(1,a,b));
	}
	return 0;
}



