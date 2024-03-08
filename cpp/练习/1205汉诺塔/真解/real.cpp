#include <iostream>
#include <cstdio>
using namespace std;
int n;
char a,b,c;
void HanNoi(int n,char x,char y,char z)
{
	if(n==1){
		printf("%c->%d->%c\n",x,n,z);
//		cout<<x<<"->"<<n<<"->"<<z<<endl;
	}
	else{
		HanNoi(n-1,x,z,y);
		printf("%c->%d->%c\n",x,n,z);
//		cout<<x<<"->"<<n<<"->"<<z<<endl;
		HanNoi(n-1,y,x,z);
	}
}
int main()
{
	cin>>n>>a>>b>>c;
	HanNoi(n,a,b,c);
	return 0;
}
