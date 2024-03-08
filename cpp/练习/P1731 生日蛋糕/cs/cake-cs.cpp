#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,ans=99999999;
int ini1[20], ini2[20];
void init(void){
    for(int i=1;i<=m;i++){
        ini1[i]=pow(i,3)+ini1[i-1];
        ini2[i]=2*i*i+ini2[i-1]; 
    }
    return ;
}
void dfs(int nowv,int nows,int r,int h,int t){
    if(t==0){
        if(nows==n)ans=min(ans,nowv);
        return;
    }
    if(nowv+ini2[t-1]>=ans)return;
    if(nows+ini1[t-1]>=n)return;
    for(int i=r-1;i>=t;i--){
        if(t==m)nowv=i*i;
        int hh=min(h-1,(n-nows-ini1[t-1])/(i*i));
        for(int j=hh;j>=t;j--){
            dfs(nowv+2*i*j,nows+i*i*j,i,j,t-1);
        }
    }
    return;
}
int main(){
	cin>>n>>m;
    init();
    int temp=sqrt(n);
    dfs(0,0,temp+1,n+1,m);
    if(ans==99999999){
        cout<<0;
        return 0;
    }
    cout<<ans;
    return 0;
}
