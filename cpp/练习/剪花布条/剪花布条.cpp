#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char A[1007],B[1007];
int P[1007],n,m;
void pre()
{
	P[1]=0;
	int j=0;
	for(int i=1;i<m;i++){
		while(j>0&&B[j+1]!=B[j+1])j=P[j];
		if(B[j+1]==B[j+1])j++;
		P[i+1]=j;
	}
}
int kmp()
{
	int ans=0,j=0;
	for(int i=0;i<n;i++){
		while(j>0&&B[j+1]!=A[i+1])j=P[j];
		if(B[j+1]==A[i+1])j++;
		if(j==m){
			ans++;
			j=0;
		}
	}
	return ans;
}
int main()
{
	while(cin>>A+1){
		if(A[1]=='#')break;
		scanf("%s",B+1);
		m=strlen(B+1);
		n=strlen(A+1);
		pre();
		printf("%d\n",kmp());
	}
	return 0;
}
