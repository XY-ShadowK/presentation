#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int arg[10]={1,2,3,4,5,6,7,8};
int main()
{
	for(int i=0;i<40320;i++){
		for(int j=0;j<7;j++)printf("%d ",arg[j]);
		printf("%d\n",arg[7]);
		next_permutation(arg,arg+8);
	}
	return 0;
}
