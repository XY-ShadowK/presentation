#include <iostream>
#include <algorithm>
using namespace std;
int n,ans=0,sum1=0,sum2=0;
long long ai_origin[1000005],ai_sort[1000005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai_origin[i];
		ai_sort[i]=ai_origin[i];
	}
	sort(ai_sort+1,ai_sort+n+1);
	for(int i=1;i<=n;i++){
		sum1+=ai_origin[i];
		sum2+=ai_sort[i];
		ans+=sum1==sum2?1:0;
	}
	cout<<ans<<endl;
	return 0;
}
