#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,l[2005][2005],used[2005],thing[2005],time=999999999,ww;
int dfs(int num,int th,int t)
{
	cout<<num<<' '<<th<<' '<<t<<endl;
    if(th>=ww){
        time=min(time,t);
        return th;
    }
    used[num]=1;
    for(int i=2;i<=n;i++){
        if(l[num][i]!=-1&&(!used[i]))th+=dfs(i,th+thing[i],max(t,l[num][i]));
    }
    used[num]=0;
    return th;
}
int main()
{
    cin>>n>>ww;
    int temp,u,v,w;
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)l[i][j]=-1;
    for(int i=2;i<=n;i++)scanf("%d",&thing[i]);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&u,&v,&w);
        l[u][v]=w;
        l[v][u]=w;
    }
    dfs(1,0,0);
    cout<<time<<endl;
    return 0;
}
