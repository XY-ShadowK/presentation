#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("bomb.in");
ofstream fout("bomb.out");
int x1[2001],x2[2001],y1[2001],y2[2001],m,n;
int main()
{
//	cin>>m>>n;
	fin>>m>>n;
	int i,temp=0,last=0,x,y;
	for(i=0;i<m;i++){
//		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		fin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
	}
	for(i=0;i<n;i++){
//		cin>>x>>y;
		fin>>x>>y;
		for(int j=0;j<m;j++){
			if((x1[j]<=x&&x<=x2[j])&&(y1[j]<=y&&y<=y2[j])){
				temp++;
				last=j;
			}
		}
		if(temp==0){
//			cout<<"NO"<<endl;
			fout<<"NO"<<endl;
			continue;
		}
		else{
//			cout<<"YES"<<' '<<temp<<' '<<last<<endl;
			fout<<"YES"<<' '<<temp<<' '<<last+1<<endl;
			temp=0; 
		}
	}
	return 0;
}
