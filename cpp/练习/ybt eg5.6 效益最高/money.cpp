#include <iostream>
using namespace std;
int maxn=0,money[5][5]={{13,11,10,4,7},{13,10,10,8,5},{5,9,7,7,4},{15,12,10,11,5},{10,11,8,8,4}},work[5];
bool pd[5];
void getmoney(int cost,int dc)
{
	for(int i=0;i<5;i++){
		if(dc<4){
			if(pd[i]){
				pd[i]=false;
				work[dc]=i;
				getmoney(money[dc][i]+cost,dc+1);
				pd[i]=true;
			}
		}
		else{
			if(money[dc][i]+cost>maxn)maxn=money[dc][i]+cost;
			return;
		}
	}
}
int main()
{
	for(int i=0;i<5;i++)pd[i]=true;
	getmoney(0,0);
	for(int i=0;i<5;i++)cout<<(char)('A'+i)<<":J"<<work[i]+1<<"   ";
	cout<<endl<<maxn<<endl;
	return 0;
}
