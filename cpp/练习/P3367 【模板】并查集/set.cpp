#include <iostream>
using namespace std;
int n,m,f[100005];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
	//return f[num]=(f[num]==num?num:find(f[num]));
}
void yn(int xi,int yi)
{
	if(!(find(xi)-find(yi)))cout<<'Y'<<endl;
	else cout<<'N'<<endl;
	return;
}
void ad(int xi,int yi)
{
	f[find(xi)]=find(yi);
	return;
}
int main()
{
	cin>>n>>m;
	int x,y,z;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=0;i<m;i++){
		cin>>z>>x>>y;
		z--;
		if(z)yn(x,y);
		else ad(x,y);
	}
	return 0;
}
