#include <iostream>
using namespace std;
int n,a[1001],total=0;
void print(int dc)
{
	cout<<n<<'='<<a[0];
	for(int i=1;i<dc;i++){
		cout<<'+'<<a[i];
	}
	cout<<endl;
	total++;
	return;
}
void devide(int num,int dc)
{
	for(int i=a[dc-1];i<=num;i++){
		a[dc]=i;
		if((num-i)==0){
			print(dc+1);
			return;
		}
		devide(num-i,dc+1);
	}
	return;
}
int main()
{
	cin>>n;
	devide(n,0);
	cout<<"total="<<total<<endl;
	return 0;
}
