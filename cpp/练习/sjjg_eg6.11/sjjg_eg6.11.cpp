#include <iostream>
using namespace std;
int n,m,fajo[100000];
bool ok(int h){
	int i,s_fajo=1,m_fajo=0;
	for(i=0;i<n;i++){
		if(m_fajo+fajo[n]>h){
			s_fajo++;
			m_fajo=0;
		}
		m_fajo+=fajo[n];
		if(m_fajo>h){
			return false;
		}
	}
	return s_fajo<=m;
}
int main()
{
	cin>>n>>m;
	int i;
	for(i=0;i<n;i++){
		cin>>fajo[i];
	}
	int l=1,r=10000*n,mid;
	while(l<=r){
		mid=(l+r)/2;
		cout<<mid<<endl;
		if(ok(mid)){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<l<<endl;
	return 0;
}
