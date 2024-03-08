#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand((unsigned)time(NULL));
	int num=rand()%10000;
	printf("所处理的整数为 %d, 千位值:  %d, 百位值:  %d, 十位值:  %d, 个位值:  %d\n每个位上的数字和为:   %d\n",num,num/1000,(num%1000)/100,(num%100)/10,num%10,num/1000+(num%1000)/100+(num%100)/10+num%10);
	return 0;
}
