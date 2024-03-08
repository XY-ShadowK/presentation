#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	FILE *fout;
	fout=fopen("triangle.txt","w");
	double fa,fb,fc,fp,fans;
	printf("请输入三角形三条边的边长\n");
	scanf("%lf%lf%lf",&fa,&fb,&fc);
	fp=(fa+fb+fc)*0.5;
	fans=sqrt(fp*(fp-fa)*(fp-fb)*(fp-fc));
	printf("三角形领操台的面积为: %.3lf平方米\n",fans);
	fprintf(fout,"三角形领操台的面积为: %.3lf平方米\n",fans);
	fclose(fout);
	return 0;
}
