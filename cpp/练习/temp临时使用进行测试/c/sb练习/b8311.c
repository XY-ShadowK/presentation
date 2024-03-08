#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	FILE *fout;
	int num;
	fout=fopen("even.txt","w");
	srand((unsigned)time(NULL));
	num=rand()%10000;
	printf("所处理的整数为 %d, 千位值:  %d, 百位值:  %d, 十位值:  %d, 个位值:  %d\n每个位上的数字和为:   %d\n",num,num/1000,(num%1000)/100,(num%100)/10,num%10,num/1000+(num%1000)/100+(num%100)/10+num%10);
	if((num/1000+(num%1000)/100+(num%100)/10+num%10)&1)return 0;
	fprintf(fout,"每个位上的数字和为: %d\n",num/1000+(num%1000)/100+(num%100)/10+num%10);
	fclose(fout);
	return 0;
}
