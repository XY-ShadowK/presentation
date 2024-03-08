#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
long long t;
cin>>t;
while(t--){
long long n,m,k;
cin>>n>>m>>k;
if(n*(n-1)/2<m||n-1>m)cout<<"NO"<<endl;
else if(n>=3&&(m<n*(n-1)/2&&k<=3||n-1>m||m>=n*(n-1)/2&&k<=2))cout<<"NO"<<endl;
else if((k<=1 && n==1))cout<<"NO"<<endl;
else if((k<=2 && n==2))cout<<"NO"<<endl;
else cout<<"YES"<<endl;
}
return 0;
}
