#include <iostream>
using namespace std;
int main()
{
	int i,n=0;
	for(i=1;i<1001;i++){
		if(i%3==0||i%5==0||i%7==0){
			n++;
		}
	}
	cout<<n<<endl;
	return 0;
}
