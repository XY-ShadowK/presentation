#include <iostream>
using namespace std;
long long q[1000001],two=1,three=1,real=2;
void g_out(int _t)
{
	int i;
	while(real<=_t){
		if(q[two]*2+1<q[three]*3+1){
			if(q[real-1]!=q[two]*2+1){
				q[real++]=q[two]*2+1;
			}
			two++;
		}
		if(q[two]*2+1==q[three]*3+1&&q[real-1]!=q[three]*3+1){
			q[real++]=q[three]*3+1;
			two++;
			three++;
		}
		if(q[two]*2+1>q[three]*3+1){
			if(q[real-1]!=q[three]*3+1){
				q[real++]=q[three]*3+1;
			}
			three++;
		}
	}
}
void start(int _t)
{
	int i;
	for(i=1;i<=_t;i++){
		q[i]=0;
	}
	two=1;
	three=1;
	real=2;
}
int main()
{
	int temp;
	int t,i;
	cin>>t;
/*	while(cin>>q[1]){
		cin>>temp;
		g_out(temp);
	}*/
	for(i=0;i<t;i++){
		cin>>q[1]>>temp;
		g_out(temp);
		cout<<q[temp];
		start(temp);
	}
	return 0;
}
