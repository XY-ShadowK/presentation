#include <iostream>
#include <cstring>
using namespace std;
typedef struct tKH{
	int mi[8];
	int count;
	tKH(){
		memset(mi,0,sizeof(mi));
		count=0;
	}
}KH;
int n,now=0;
KH h[1000];
void open(int num)
{
	while(h[num].mi[0]!=0){
		for(int i=0;;i++){
			if((2<<i)>h[num].mi[0]){
				h[num].mi[0]=h[num].mi[0]-(2<<(i-1));
				h[num].mi[h[num].count]=now;
				h[num].count++;
				h[now].mi[0]=i-1;
				h[now].count++;
				now++;
				break;
			}
		}
	}
}
void output(int num)
{
	if(h[num].count==1){
		if(h[num].mi[0]!=1){
			cout<<'('<<h[num].mi[0]<<')';
		}
		return;
	}
	for(int i=1;i<h[num].count;i++){
		cout<<'2';
		output(h[num].mi[i]);
		cout<<'+';
	}
}
int main()
{
	cin>>n;
	int ss=0;
	while(n!=0){
		for(int i=0;;i++){
			if((2<<i)>n){
				n=n-(2<<(i-1));
				h[now].mi[0]=i-1;
				h[now].count++;
				now++;
				ss++;
				break;
			}
		}
	}
	for(int i=0;i<now;i++){
		open(i);
	}
	for(int i=0;i<ss;i++){
		output(i);
	}
	return 0;
}
