#include <iostream>
#include <cmath>
using namespace std;
int n,d;
double island[1005][2];
int main()
{
    cin>>n;
    int i;
    double t;
    for(i=0;i<n;i++){cin>>island[i][0]>>island[i][1];if(island[i][1]>d){cout<<-1<<endl;return 0;}t=sqrt(d*d-island[i][1]*island[i][1]);island[i][1]=island[i][0]+t;island[i][0]=island[i][0]-t;}
	
    return 0;
}
