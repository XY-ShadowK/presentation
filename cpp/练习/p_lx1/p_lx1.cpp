#include <iostream>
using namespace std;
int main()
{
	int i,j,sz[1000001],m,n;
	cin>>n>>m;
	for(i=0;i<n*m;;i++){
		cin>>sz[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			//翻转操作 sz[i*m+j];
		}
	}
	return 0;
}//不用指针写法 14行 使用时较复杂 
int main()
{
	int i,j,m,n,sz2;
	int *sz[1000001];
	cin>>n>>m;
	for(i=0;i<n;i++){
		sz[i]= new int [m];
		for(j=0;j<m;j++){
			cin>>sz2;
			*sz[i]=sz2;
			sz[i]++;
		}
	}
	for(i=0;i<n;i++){
		sz[i]-=m;
		for(j=0;j<m;j++,sz[i]++){
			//翻转操作 sz[i]
		}
	}
	return 0;
}//指针写法 21行 使用时较简单 
int main()
{
	int n,m;
	cin>>n>>n;
	int *p;
	p=new int [n*m];
	int *pp;
	pp=new int * [n];
	for(i=0;i<n;i++){
		pp[i]=p+i*m;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>pp[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			//翻转操作 pp[i][j];
		}
	}
	return 0;
}//黄老师超级指针写法 22行 使用时超级简单 
int main()
{
	int n,m,i,j,o,k;
	cin>>n>>n>>o;
	int *p;
	p=new int [n*m];
	int *pp;
	pp=new int * [n];
	for(i=0;i<n;i++){
		pp[i]=p+i*m;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>pp[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			//翻转操作 pp[i][j];
		}
	}
	return 0;
}//黄老师超值指针写法之三维变式 未完待续 
