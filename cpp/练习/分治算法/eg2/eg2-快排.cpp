#include <iostream>
using namespace std;
typedef struct tSTR{
	int naive[1000];
	int last;
	int qsort()
	{
		int l=0,r=last,temp;
		int key=naive[(l+r)/2];
		while(l<=r){
			for(;;r--){
				if(naive[r]<=key){
					break;
				}
			}
			for(;;l++){
				if(naive[l]>=key){
					break;
				}
			}
			temp=naive[l];
			naive[l]=naive[r];
			naive[r]=temp;
			l++;
			r--;
		}
		return r;
	}
	tSTR(int copy[],int num)
	{
		int i;
		for(i=0;i<num;i++){
			naive[i]=copy[i];
		}
		last=num-1;
	}
}STR;
int a[10000];
void qs(int le,int ri)
{
	STR t1(a,ri+1);
	int j=t1.qsort();
	int l1=le,r1=j,l2=j+1,r2=ri;
	for(int i=le,k=0;i<=ri;i++,k++){
		a[i]=t1.naive[k];
	}
	if(le<j){
		qs(l1,r1);
	}
	if(j+1<ri){
		qs(l2,r2);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	qs(0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
