#include <iostream>
#include "high_bits"
using namespace std;
const unsigned long long ul1 = 2333333333;
const unsigned long long ul2 = 2;
int main()
{
	string a,b;
	cout<<ulpow(ul1,ul2)<<' '<<"5444444442888888889"<<endl;
	cout<<f_bits(ul1)<<' '<<"10"<<endl;
	cout<<ul_to_str_change(ul1)<<' '<<"2333333333"<<endl;
	cout<<"运算测试 输入两个数"<<endl;
	cin>>a>>b;
	Hnum st1,st2;
	st1.x=a;
	st2.x=b;
	cout<<a<<" + "<<b<<" = "<<st1+st2<<endl;
	cout<<a<<" - "<<b<<" = "<<st1-st2<<endl;
	cout<<a<<" * "<<b<<" = "<<st1*st2<<endl;
	cout<<a<<" / "<<b<<" = "<<st1/st2<<endl;
	cout<<a<<" % "<<b<<" = "<<st1%st2<<endl;
	cout<<a<<" > "<<b<<(st1>st2?" 为真 ":" 为假 ")<<endl;
	cout<<a<<" < "<<b<<(st1<st2?" 为真 ":" 为假 ")<<endl;
	cout<<a<<" >= "<<b<<(st1>=st2?" 为真 ":" 为假 ")<<endl;
	cout<<a<<" <= "<<b<<(st1<=st2?" 为真 ":" 为假 ")<<endl;
	cout<<a<<" == "<<b<<(st1==st2?" 为真 ":" 为假 ")<<endl;
	cout<<a<<" ^ "<<b<<" = "<<(st1^st2)<<endl;
	return 0;
}
