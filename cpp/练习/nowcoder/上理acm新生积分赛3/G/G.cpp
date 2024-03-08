#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(!b){
           x=1;
           y=0;
           return a;
           }
    int t,s=exgcd(b,a%b,x,y);
    t=x;x=y;
    y=t-a/b*y;
    return s;
}
int main(){
	long long a,b,x,y,sum;
    scanf("%d%d%d",&a,&b);
    if(c!=exgcd(a,b,x,y))
    printf("-1\n");
    printf("%d %d\n",x,y);
    return 0;
}
