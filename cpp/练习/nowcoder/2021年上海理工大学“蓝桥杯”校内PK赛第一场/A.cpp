#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int n,fa,fb,fc;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>fa>>fb>>fc;
		if(fa>90&&fb>90&&fc>60)cout<<"A+"<<endl;
		else cout<<"E+"<<endl;
	}
	return 0;
}
