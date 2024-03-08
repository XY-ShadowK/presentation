#include <iostream>
using namespace std;
int qp[1000][1000],n,sum;
bool pd(int x,int y)
{
	int i,hl=0;
	for(i=0;i<n;i++){
		if(qp[x][i]==1||qp[i][y]==1){
			hl=1;
		}
	}
	for(i=0;x-i!=-1&&y-i!=-1;i++){
		if(qp[x-i][y-i]==1){
			hl=1;
		}
	}
	for(i=0;x+i<n&&y+i<n;i++){
		if(qp[x+i][y+i]==1){
			hl=1;
		}
	}
	for(i=0;y-i!=-1&&x+i<n;i++){
		if(qp[x+i][y-i]==1){
			hl=1;
		}
	}
	for(i=0;x-i!=-1&&y+i<n;i++){
		if(qp[x-i][y+i]==1){
			hl=1;
		}
	}
	if(hl==0){
		return true;
	}
	else{
		return false;
	}
}

void dfs(int x){
	int i,j,k;
	for(i=0;i<n;i++)
	  {
	  	if(pd(x,i))
	  	  {
	  	  	if(x==n-1)
	  	  	  {
	  	  	  	sum++;
	  	  	  	continue;
			  }
	  	  	qp[x][i]=1;
	  	  	dfs(x+1);
	  	  	qp[x][i]=0;
		  }
	  }
	return;
}

int main()
{
	cin>>n;
	int i,j,k;
	dfs(0);
	cout<<sum;
	return 0;
}
