#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
struct node
{
	int x;
	int y;
	int e;
}con[1100];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>con[i].x;
		cin>>con[i].y;
		cin>>con[i].e;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int dis1=con[i].x-con[j].x;
			int dis2=con[i].y-con[j].y;
			int dis=(dis1*dis1)+(dis2*dis2);
			if(dis==(con[i].e+con[j].e)*(con[i].e+con[j].e))cout<<i<<" "<<j<<endl;
		}
	}
return 0;
}
