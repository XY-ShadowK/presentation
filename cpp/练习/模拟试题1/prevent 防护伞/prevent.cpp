#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("prevent.in");
ofstream fout("prevent.out");
const double PI = 3.1415926535;
int n,x_bp[1005],y_bp[1005];
double round(int m)
{
	int i;
	double temp,max=0.00;
	for(i=0;i<n;i++){
		temp=(double)sqrt((x_bp[m]-x_bp[i])*(x_bp[m]-x_bp[i])+(y_bp[m]-y_bp[i])*(y_bp[m]-y_bp[i]));
		if(temp>max){
			max=temp;
		}
	}
	return max;
}
int main()
{
	cin>>n;
//	fin>>n;
	int i;
	double r,temp;
	for(i=0;i<n;i++){
		cin>>x_bp[i]>>y_bp[i];
//		fin>>x_bp[i]>>y_bp[i];
	}
	r=999999.0;
	for(i=0;i<n;i++){
		temp=round(i);
		r=r>temp?temp:r;
	}
	cout<<fixed<<setprecision(4)<<r*r*PI<<endl;
//	fout<<fixed<<setprecision(4)<<r*r*PI<<endl;
	return 0;
}
