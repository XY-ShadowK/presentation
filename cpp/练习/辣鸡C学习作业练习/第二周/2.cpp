#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
long long num;
int main()
{
	cout<<"请输入一个整数！"<<endl;
	cin>>num;
	if(num%2)cout<<"你输入的是一个奇数！"<<endl;
	else cout<<"你输入的是一个偶数！"<<endl;
	return 0;
}
