#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int M=1000000007;
int n,k,a[100005];
long long ans=0,sa,ss=0;
set <int> t;
long long scan1(int num)
{
	long long ans1=0,ans2=0;
	int tt;
	for(int i=num;i<=n;i++){
		t.clear();
		for(int j=i-num+1;j<=i;j++){
			t.insert(a[j]);
		}
		ans1=(ans1%M+t.size()%M)%M;
	}
	for(int i=n+1;i<=n+num-1;i++){
		t.clear();
		for(int j=i-num+1;j<=i;j++){
			tt=j>n?j-n:j;
			t.insert(a[tt]);
		}
		ans2=(ans2%M+t.size()%M)%M;
	}
	if(num==n)sa=ans1;
	return (ans1*k%M+ans2*(k-1)%M)%M;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ans=n*k%M;
	for(int i=2;i<=n;i++)ans=(ans%M+scan1(i))%M;
	ss=(sa*(((1+n*(k-1)%M)*n*(k-1)%M)/2)%M)%M;
	ans=(ans+ss)%M;
	cout<<ans<<endl;
	return 0;
}
