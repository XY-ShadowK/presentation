#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
long long a,b,tf,ans;
string ct;
int main()
{
	srand(time(NULL));
	while(1){
		a=rand()%100;
		b=rand()%100;
		tf=rand()%2;
		switch(tf){
			case 0 : {
				cout<<"请计算"<<max(a,b)<<"减"<<min(a,b)<<endl;
				cin>>ans;
				if(ans==abs(a-b))cout<<"完全正确！"<<endl;
				else cout<<"没有做对，继续努力！"<<endl;
				break;
			}
			case 1 : {
				cout<<"请计算"<<a<<"加"<<b<<endl;
				cin>>ans;
				if(ans==(a+b))cout<<"完全正确！"<<endl;
				else cout<<"没有做对，继续努力！"<<endl;
				break;
			}
		}
		cout<<"是否继续答题？请输入Yes或No。[Yes(是)/No(否)]"<<endl;
		cin>>ct;
		if(ct=="No"){
			system("cls");
			break;
		}
		else system("cls");
	}
	return 0;
}
