#include <iostream>
using namespace std;
typedef struct tHH{
	int * qp[1000];
	int gs=0;
	void start(int n)
	{
		int i;
		for(i=0;i<n;i++){
			qp[i] = new int [n];
		}
	}
	void _open(int x,int y,int n)
	{
		int i;
		gs++;
		for(i=0;i<n;i++){
			*qp[x]=1;
			qp[x]++;
		}
		for(i=0;i<n;i++){
			qp[i]+=y;
			*qp[i]=1;
			qp[i]-=y;
		}
		for(i=0;x-i!=0&&y-i!=0;i++){
			qp[x-i]+=y-i;
			*qp[x-i]=1;
			qp[x-i]-=y-i;
		}
		for(i=0;x+i!=0&&y+i!=0;i++){
			qp[x+i]+=y+i;
			*qp[x+i]=1;
			qp[x+i]-=y+i;
		}
		for(i=0;x-i!=0&&y+i!=0;i++){
			qp[x-i]+=y+i;
			*qp[x-i]=1;
			qp[x-i]-=y+i;
		}
		for(i=0;x+i!=0&&y-i!=0;i++){
			qp[x+i]+=y-i;
			*qp[x+i]=1;
			qp[x+i]-=y-i;
		}
	}
	bool open(int x,int y,int n)
	{
		qp[x]+=y;
		if(*qp[x]!=1){
			_open(x,y,n);
			return true;
		}
		qp[x]-=y;
		return false;
	}
	void close(int n)
	{
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				*qp[i]=0;
				qp[i]++;
			}
			qp[i]-=n;
		}
	}
}HH;
int main()
{
	HH nhh;
	int i,j,n,sum=0;
	cin>>n;
	nhh.start(n);
	nhh.close(n);
	nhh._open(0,0,n);
	for(i=0;i<n;i++){
		if(nhh.gs==n){
			sum++;
			nhh.close(n);
		}
		for(j=0;j<n;j++){
			if(nhh.open(i,j,n)){
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
