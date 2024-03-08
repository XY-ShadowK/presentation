#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool d[16]={0},b[9]={0},c[16]={0};
int sum=0,a[9],dd[100];
int save()
{
	int i,j;
	for(i=0;i<8;i++){
		dd[sum]+=(int)pow(10,7-i)*a[i];
	}
	sum++;
}
int search(int i)
{
	int j;
	for(j=1;j<=8;j++)if((!b[j])&&(!c[i+j])&&(!d[i-j+7])){
		a[i]=j;
		b[j]=1;
		c[i+j]=1;
		d[i-j+7]=1;
		if(i==8)save();
		else search(i+1);
		b[j]=0;
		c[i+j]=0;
		d[i-j+7]=0;
	}
}
int main()
{
	search(1);
	int n,temp;
	cin>>n;
	sort(dd,dd+92);
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		cout<<dd[temp]<<endl;
	}
	return 0;
}
