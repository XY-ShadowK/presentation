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
			//��ת���� sz[i*m+j];
		}
	}
	return 0;
}//����ָ��д�� 14�� ʹ��ʱ�ϸ��� 
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
			//��ת���� sz[i]
		}
	}
	return 0;
}//ָ��д�� 21�� ʹ��ʱ�ϼ� 
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
			//��ת���� pp[i][j];
		}
	}
	return 0;
}//����ʦ����ָ��д�� 22�� ʹ��ʱ������ 
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
			//��ת���� pp[i][j];
		}
	}
	return 0;
}//����ʦ��ֵָ��д��֮��ά��ʽ δ����� 
