#include <iostream>
#include <cstdio>
#include <cmath>
typedef __int128 ull;
typedef unsigned short int usi;
using namespace std;
ull sum=0;
usi n,m,jz[81][81],head[81],end[81];
void scan(__int128 &x)
{
    x=0;
    int f=1;
    char ch;
    if((ch=getchar())=='-')f=-f;
    else x=x*10+ch-'0';
    while((ch=getchar())>='0'&& ch <='9')
        x=x*10+ch-'0';
    x*=f;
}
void print(__int128 x)
{
    if(x<0)
    {
        x=-x;
        putchar('-');
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
bool mycompare(usi y,usi h,usi e)
{
	if(h==e)return true;
	if(jz[y][h]==jz[y][e]){
		if(h+1==e)return true;
		else return mycompare(y,h+1,e-1);
	}
	else{
		if(jz[y][h]<jz[y][e])return true;
		else return false;
	}
}
void develop_sum(usi _n,usi x)
{
	if(mycompare(x,head[x],end[x])){
		sum+=(jz[x][head[x]]*(ull)pow(2,_n));
		head[x]++;
	}
	else{
		sum+=(jz[x][end[x]]*(ull)pow(2,_n));
		end[x]--;
	}
	return;
}
int main()
{
	cin>>n>>m;
	for(usi i=0;i<n;i++){
		head[i]=0;
		end[i]=m-1;
		for(usi j=0;j<m;j++)cin>>jz[i][j];
	}
	for(usi i=1;i<m;i++)for(usi j=0;j<n;j++)develop_sum(i,j);
	for(usi j=0;j<n;j++)sum+=(jz[j][head[j]]*(ull)pow(2,m));
	print(sum);
	cout<<endl;
	return 0;
}
