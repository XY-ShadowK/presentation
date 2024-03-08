#include<bits/stdc++.h>
#define shit_CCF freopen("tour.in","r",stdin);freopen("tour.out","w",stdout);
#define FUCK_CCF fclose(stdin);fclose(stdout);return 0;
using namespace std;
struct node
{
    int k,d,num;
    friend bool operator< (node x,node y)
    {
        return x.d>y.d;
    }
};
int sum,n,m,nu;
int first[100001],nex[100001],v[100001],vis[100001],w[100001],dis[400001][31],ans=999999999;
priority_queue<node>p;
void add(int x,int y,int z)
{
    nu++;
    v[nu]=y;
    nex[nu]=first[x];
    first[x]=nu;
    w[nu]=z;
}
int main()
{
	shit_CCF
    int q,z;
    memset(first,-1,sizeof(first));
    memset(dis,127/3,sizeof(dis));
    scanf("%d%d%d",&n,&m,&sum);
    scanf("%d%d",&q,&z);
    q++;z++;
    for(int i=1;i<=m;i++)
    {
        int a,b,z;
        scanf("%d%d%d",&a,&b,&z);
        a++,b++;
        add(a,b,z);
        add(b,a,z);
    }
    node u,x;
    dis[q][0]=0;
    x.k=0;
    x.num=q;
    x.d=0;
    p.push(x);
    while(p.empty()==false)
    {
        u=p.top();
        p.pop();
        for(int i=first[u.num];i!=-1;i=nex[i])
        {
            int to=v[i];
            node t;
            if(dis[to][u.k]>u.d+w[i])
            {
                dis[to][u.k]=u.d+w[i];
                t.d=dis[to][u.k];
                t.k=u.k;
                t.num=to;
                p.push(t);
            }
            if(u.k+1<=sum)
            {
                if(u.d<dis[to][u.k+1])
                {
                    dis[to][u.k+1]=u.d;
                    t.k=u.k+1;
                    t.num=to;
                    t.d=dis[to][u.k+1];
                    p.push(t);
                }

            }
        }
    }
    for(int i=0;i<=sum;i++)
    ans=min(ans,dis[z][i]);
    printf("%d",ans);
    FUCK_CCF
}
