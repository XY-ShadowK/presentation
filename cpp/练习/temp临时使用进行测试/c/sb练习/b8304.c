#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	FILE *fout;
	fout=fopen("triangle.txt","w");
	double fa,fb,fc,fp,fans;
	printf("�����������������ߵı߳�\n");
	scanf("%lf%lf%lf",&fa,&fb,&fc);
	fp=(fa+fb+fc)*0.5;
	fans=sqrt(fp*(fp-fa)*(fp-fb)*(fp-fc));
	printf("���������̨�����Ϊ: %.3lfƽ����\n",fans);
	fprintf(fout,"���������̨�����Ϊ: %.3lfƽ����\n",fans);
	fclose(fout);
	return 0;
}
