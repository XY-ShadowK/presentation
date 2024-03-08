#include <iostream>
using namespace std;
typedef struct tLB{
	int value;
	tLB * dz;
	void start(tLB m)
	{
		dz=&m;
	}
	tLB *szgb(int n)
	{
		tLB *nb;
		nb=dz;
		for(int i=1;i<n;i++){
			nb=nb->dz;
		}
		return nb;
	}
	void _1i(int n,tLB m)
	{
		tLB *nb;
		nb=m.szgb(n);
		cout<<nb->value<<endl;
	}
	void _2iv(int n)
	{
		int v;
		cin>>v;
	}
}LB;
int main()
{
	LB a[1010];
	int n,m,i,cz,h;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].value;
		a[i].start(a[i+1]);
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>cz;
		switch(cz){
			case 1 : {cin>>h;a[h]._1i(n,a[1]);break;}
			case 2 : {cin>>h;a[h]._2iv(n,);n++;break;}
			case 3 : {cin>>h;a[h]._3i(n);n--;break;}
			case 4 : {cin>>h;a[h]._4ij();break;}
		}
	}
	return 0;
} 
