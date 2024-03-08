#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int n,k,candles[100005],ans=(int)1e9+5;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>candles[i];
	for(int i=0;i+k-1<n;i++){
		int l=i,r=i+k-1;
		ans=min(ans,candles[r]-candles[l]+min(abs(candles[r]),abs(candles[l])));
	}
	cout<<ans<<endl;
 	return 0;
}
