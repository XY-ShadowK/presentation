#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand((unsigned)time(NULL));
	int num=rand()%10000;
	printf("�����������Ϊ %d, ǧλֵ:  %d, ��λֵ:  %d, ʮλֵ:  %d, ��λֵ:  %d\nÿ��λ�ϵ����ֺ�Ϊ:   %d\n",num,num/1000,(num%1000)/100,(num%100)/10,num%10,num/1000+(num%1000)/100+(num%100)/10+num%10);
	return 0;
}
