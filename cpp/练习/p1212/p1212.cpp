#include <iostream>
using namespace std;
typedef struct tJX{
    int l_len,s_len,mj;
    void operator<<(const int & len)
    {
        if(len>l_len){
            s_len=l_len;
            l_len=len;
        }
        else{
            s_len=len;
        }
        return;
    }
    tJX()
    {
        l_len=0;
        s_len=0;
        mj=0;
    }
}JX;
JX four[4],ans[6],a[6];
int n,maxn;
void _six_mj(int num)
{
}
int main()
{
    int i,t1,t2;
    for(i=0;i<5;i++){
        cin>>t1>>t2;
        four[i]<<t1;
        four[i]<<t2;
    }
    for(i=0;i<6;i++){
        _six_mj(i);
    }
    for(i=0;i<n;i++){
        cout<<ans[i].s_len<<' '<<ans[i].l_len;
    }
    return 0;
}
