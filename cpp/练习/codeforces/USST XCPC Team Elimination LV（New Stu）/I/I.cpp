#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int t,a,b,num;
int main()
{
	cin>>t;
	while(t--){
		scanf("%d%d",&a,&b);
		num=a+b;
		if(abs(a-b)<=1){
			printf("Ok\n");
			continue;
		}
//		if((a-b)>=-1&&(a-b)<=0)printf("Ok\n");
//		if(!(a-b))printf("Ok\n");
		if(num%2)printf("%d %d\n",num/2,num/2+1);
		else	printf("%d %d\n",num/2,num/2);
	}
	return 0;
}
