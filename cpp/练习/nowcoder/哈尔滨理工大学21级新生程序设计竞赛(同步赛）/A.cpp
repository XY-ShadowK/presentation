#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
string days[5]={"Higher mathematics","Linear algebra","Principle of computer composition","Database system concept","Data structures and algorithms"};
int t;
int main()
{
	cin>>t;
	if(t==5)cout<<"You were playing games!";
	else cout<<"You were studying "<<days[t-1]<<'!';
	return 0;
}
