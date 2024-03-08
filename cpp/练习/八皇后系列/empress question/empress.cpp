#include <iostream>
using namespace std;
bool d[16]={0},b[9]={0},c[16]={0};
int sum=0,a[9];
void print()
{
	int i,j;
	sum++;
	cout<<"No. "<<sum<<endl;
	for(j=1;j<=8;j++){
		for(i=1;i<=8;i++){
			if(a[i]==j)cout<<"1 ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
}
void search(int i)
{
	int j;
	for(j=1;j<=8;j++)if((!b[j])&&(!c[i+j])&&(!d[i-j+7])){
		a[i]=j;
		b[j]=1;
		c[i+j]=1;
		d[i-j+7]=1;
		if(i==8)print();
		else search(i+1);
		b[j]=0;
		c[i+j]=0;
		d[i-j+7]=0;
	}
}
int main()
{
	search(1);
	return 0;
}
