#include <iostream>
#include <algorithm>
using namespace std;
long long r,d[505],k[505],c[505],cs=0,f[300005],days[300005];
int n,m,p,q,last[505];
int main()
{
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++){
		cin>>d[i]>>k[i]>>c[i];
		last[i]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>p>>q;
		while(q--)days[++cs]=p;
	}
	sort(days+1,days+1+cs);
	f[0]=0;
	for(int i=1;i<=cs;i++){
		f[i]=f[i-1]+r;
		for(int j=1;j<=n;j++){
			while(1){
				if(days[last[j]]+d[j]-1<days[i]||last[j]+k[j]-1<i)last[j]++;
				else break;
			}
			f[i]=min(f[i],f[last[j]-1]+c[j]);
		}
	}
	cout<<f[cs]<<endl;
	return 0;
}
