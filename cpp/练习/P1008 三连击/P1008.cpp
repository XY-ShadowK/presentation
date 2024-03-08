#include <iostream>
using namespace std;
bool master(int a,int n,int x[])
{
	int temp;
	for(temp=0;temp<n;temp++){
		if(a==x[temp])return false;
	}
	return true;
}
int * del(int a,int b,int c,int n,int x[])
{
	int i;
	for(i=0;i<n;i++){
		x[i]=(x[i]==a||x[i]==b||x[i]==c)?-1:x[i];
	}
	return x;
}
void nPr(int n,int x[],int first,int second)
{
	int i,j,k,temp;
	for(i=1;i<10;i++){
		if(master(i,n,x))continue;
		for(j=1;j<10;j++){
			if(i==j||master(j,n,x))continue;
			for(k=1;k<10;k++){
				if(i==k||j==k||master(k,n,x))continue;
				if(i*100+j*10+k==3*second)cout<<first<<' '<<second<<' '<<i*100+j*10+k<<endl;
			}
		}
	}
}
void nPr(int n,int x[],int first)
{
	int i,j,k,temp;
	for(i=1;i<10;i++){
		if(master(i,n,x))continue;
		for(j=1;j<10;j++){
			if(i==j||master(j,n,x))continue;
			for(k=1;k<10;k++){
				if(i==k||j==k||master(k,n,x))continue;
				if(i*100+j*10+k==2*first)nPr(n,del(i,j,k,n,x),first,i*100+j*10+k);
			}
		}
	}
}
void nPr(int n,int x[])
{
	int i,j,k,temp;
	for(i=1;i<10;i++){
		if(master(i,n,x))continue;
		for(j=1;j<10;j++){
			if(i==j||master(j,n,x))continue;
			for(k=1;k<10;k++){
				if(i==k||j==k||master(k,n,x))continue;
				nPr(n,del(i,j,k,n,x),i*100+j*10+k);
			}
		}
	}
}
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	nPr(10,a);
	return 0;
}
