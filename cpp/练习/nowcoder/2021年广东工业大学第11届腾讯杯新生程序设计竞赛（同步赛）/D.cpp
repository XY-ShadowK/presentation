#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
#include <queue>
using namespace std;
int n,m1[15][15],m2[15][15],out[105],all,cnt=0;
queue<int> q;
inline bool pd(int aa,int bb)
{
	if(aa>bb)return aa==all&&bb==1;
	return bb==aa+1;
}
int main()
{
	cin>>n;
	all=n*n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		cin>>m2[i][j];
		m1[i][j]=++cnt;
	}
	for(int i=2;i<n;i++)for(int j=2;j<n;j++)if(m1[i][j]!=m2[i][j]){
		cout<<"NO";
		return 0;
	}
	cnt=0;
	for(int i=2;i<=n;i++){
		out[cnt++]=m1[1][i];
		q.push(m2[1][i]);
	}
	for(int i=2;i<=n;i++){
		out[cnt++]=m1[i][n];
		q.push(m2[i][n]);
	}
	for(int i=n-1;i>0;i--){
		out[cnt++]=m1[n][i];
		q.push(m2[n][i]);
	}
	for(int i=n-1;i>0;i--){
		out[cnt++]=m1[i][1];
		q.push(m2[i][1]);
	}
	while(q.front()!=out[0])q.push(q.front()),q.pop();
	for(int i=0;i<cnt;i++){
		if(q.front()!=out[i]){
			cout<<"NO";
			return 0;
		}
		q.pop();
	}
	cout<<"YES";
	return 0;
}
