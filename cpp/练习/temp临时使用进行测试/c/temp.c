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
	printf("�����������Ϊ %d, ǧλֵ:  %d, ��λֵ:  %d, ʮλֵ:  %d, ��λֵ:  %d\nÿ��λ�ϵ����ֺ�Ϊ:   %d\n",num,num/1000,(num%1000)/100,(num%100)/10,num%10,num/1000+(num%1000)/100+(num%100)/10+num%10);
	if((num/1000+(num%1000)/100+(num%100)/10+num%10)&1)return 0;
	fprintf(fout,"ÿ��λ�ϵ����ֺ�Ϊ: %d\n",num/1000+(num%1000)/100+(num%100)/10+num%10);
	fclose(fout);
	return 0;
}
