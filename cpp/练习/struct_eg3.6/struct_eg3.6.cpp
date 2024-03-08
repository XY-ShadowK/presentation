#include <iostream>
using namespace std;
typedef struct tTime{
	int h,min;
	tTime operator+(const tTime x)const
	{
		tTime tmp;
		tmp.min=(min+x.min)%60;
		tmp.h=h+x.h+(min+x.min)/60;
		return tmp;
	}
}TIME;
int main()
{
	int n;
	TIME a,sum;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a.h>>a.min;
		sum=sum+a;
	}
	cout<<sum.h<<' '<<sum.min<<endl;
	return 0;
}
