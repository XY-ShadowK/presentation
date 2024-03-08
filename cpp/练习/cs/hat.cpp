#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("hat.in");
ofstream fout("hat.out");
int n,q;
char hat[45][45][45];
int getnum(int x0,int y0,int z0,int x1,int y1,int z1)
{
	int num=0;
	for(int i=x0;i<=x1;i++)for(int j=y0;j<=y1;j++)for(int k=z0;k<=z1;k++)if(hat[i][j][k]=='G')num++;
	return num;
}
void changecolor(int x0,int y0,int z0,int x1,int y1,int z1,char s,char e)
{
	if(s=='#'){
		for(int i=x0;i<=x1;i++)for(int j=y0;j<=y1;j++)for(int k=z0;k<=z1;k++)hat[i][j][k]=e;
		return;
	}
	for(int i=x0;i<=x1;i++)for(int j=y0;j<=y1;j++)for(int k=z0;k<=z1;k++)if(hat[i][j][k]==s)hat[i][j][k]=e;
	return;
}
int main()
{
//	cin>>n>>q;
	fin>>n>>q;
	int temp,x0,y0,z0,x1,y1,z1;
	char cc;
	for(int i=0;i<q;i++){
//		cin>>temp>>x0>>y0>>z0>>x1>>y1>>z1;
		fin>>temp>>x0>>y0>>z0>>x1>>y1>>z1;
		switch(temp){
			case 0 : {
//				cout<<getnum(x0,y0,z0,x1,y1,z1);
				fout<<getnum(x0,y0,z0,x1,y1,z1);
				break;
			}
			case 1 : {
//				cin>>cc;
				fin>>cc;
				changecolor(x0,y0,z0,x1,y1,z1,'#',cc);
				break;
			}
			case 2 : {
//				cin>>cc;
				fin>>cc;
				changecolor(x0,y0,z0,x1,y1,z1,cc,'G');
				break;
			}
		}
	}
	return 0;
}
