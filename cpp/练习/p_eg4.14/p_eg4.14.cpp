//eg4.14
#include <iostream>
using namespace std;
void swpav(int a,int b){
	int temp=a;
	a=b;
	b=temp;
}
void swpap(int *fa,int *fb){
	int temp;
	temp=*fa;
	*fa=*fb;
	*fb=temp;
}
void swapr(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
int main()
{
	int a=10,b=20;
	swpav(a,b);
	cout<<a<<' '<<b<<endl;
	swpap(&a,&b);
	cout<<a<<' '<<b<<endl;
	swapr(a,b);
	cout<<a<<' '<<b<<endl;
	return 0;
}
