#include <iostream>
using namespace std;
typedef struct tPointBian{
	int gs=0,tPoint[5010]={0};
}tPB;
tPB point[5010];
int main()
{
	int n,m,i,ls[2][100010];
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>ls[0][i]>>ls[1][i];
	}
	for(i=m;i>0;i--){
		point[ls[0][i]].tPoint[point[ls[0][i]].gs]=ls[1][i];
		point[ls[1][i]].tPoint[point[ls[1][i]].gs]=ls[0][i];
		point[ls[0][i]].gs++;
		point[ls[1][i]].gs++;
	}
	for(i=1;i<=n;i++){
		cout<<point[i].gs<<' ';
		for(int j=0;j<point[i].gs;j++){
			cout<<point[i].tPoint[j]<<' ';
		}
		cout<<endl;
	}
	return 0;
} 
