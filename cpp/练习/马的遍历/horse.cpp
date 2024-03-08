#include <iostream>
using namespace std;
int x[4]={1,2,1,2},y[4]={2,1,-2,-1},a[100][2],t=0;
void print(int n)
{
	t++;
	cout<<t<<':';
	for(int i=1;i<n;i++)cout<<a[i][0]<<','<<a[i][1]<<"-->";
	cout<<"8,4"<<endl;
}
void search(int dc)
{
	for(int i=0;i<4;i++){
		if(a[dc-1][0]+x[i]>=0&&a[dc-1][0]+x[i]<=8&&a[dc-1][1]+y[i]>=0&&a[dc-1][1]+y[i]<=4){
			a[dc][0]=a[dc-1][0]+x[i];
			a[dc][1]=a[dc-1][1]+y[i];
			if(a[dc][0]==8&&a[dc][1]==4)print(dc);
			else search(dc+1);
		}
	}
}
int main()
{
	a[1][0]=0;
	a[1][1]=0;
	search(2);
	return 0;
}
