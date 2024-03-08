#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
double data,x1,x2,a,b,c;
void pd_data()
{
//	data=b*b-4*a*c;
	if((fabs(b*b-4*a*c)<(numeric_limits<double>::min)()){
		data=0.00;
		return;
	}
	if((b*b-4*a*c)>(numeric_limits<double>::min)()){
		data=b*b-4*a*c;
		return;
	}
	data=-1.00;
	return;
}
void prt()
{
	double temp1=(-b+sqrt(data))/(2*a),temp2=(-b-sqrt(data))/(2*a);
	temp1>temp2?cout<<"x1="<<fixed<<setprecision(5)<<temp2<<";x2="<<fixed<<setprecision(5)<<temp1:cout<<"x1="<<fixed<<setprecision(5)<<temp1<<";x2="<<fixed<<setprecision(5)<<temp2;
}
int main()
{
	bool hh=false;
	cin>>a>>b>>c;
	pd_data();
	if(data==0.00){
		cout<<"x1="<<fixed<<setprecision(5)<<(-b+sqrt(data))/(2*a)<<";x2="<<fixed<<setprecision(5)<<(-b+sqrt(data))/(2*a);
		hh=true;
	}
	if(data==-1.00){
		cout<<"No answer!";
		hh=true;
	}
	if(hh==false){
		prt();
	}
	return 0;
}
