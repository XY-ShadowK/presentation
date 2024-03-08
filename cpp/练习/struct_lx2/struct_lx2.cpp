#include <iostream>
using namespace std;
typedef struct tSB{
	int zs,bh;
}SB;
int main()
{
	SB px[10001];
	int n,i,j,o,p,max[2];
	cin>>n;
	o=n;
	for(i=0;i<n;i++){
		cin>>px[i].zs;
	}
	max[0]=px[0].zs;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(px[i].zs>max[0]&&px[i].zs<p){
				max[0]=px[i].zs;
				max[1]=i;
			}
		}
		px[max[1]].bh=o;
		p=max[0];
		o--;
	}
	for(i=0;i<n;i++){
		cout<<px[i].bh<<' '; 
	}
	cout<<endl;
	return 0;
}
