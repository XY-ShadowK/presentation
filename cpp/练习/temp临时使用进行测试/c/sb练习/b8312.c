#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	char phnum[20],yon,tme[50];
	int dct;
	printf("请输入你的手机号: ");
	gets(phnum);
	printf("你的手机号为: ");
	puts(phnum);
	printf("请确认 (y/n)");
	scanf("%c",&yon);
	if(!(yon-'n')){
		printf("手机号不正确，退出本程序，谢谢!\n");
		return 0;
	}
	printf("\n\t封控区域代码表\n1--516校区格致堂\t2--516校区研究生第1宿舍\n\t输入你进入区域代码\n");
	scanf("%d",&dct);
	printf("\t输入你进入该区域的时间\n");
	getchar();
	gets(tme);
	printf("\t手机号为: %s 于%s",phnum,tme);
	switch(dct){
		case 1 : {
			printf("途径516校区格致堂\n");
			return 0;
		}
		case 2 : {
			printf("途径516校区研究生第1宿舍\n");
			return 0;
		}
	}
	printf("进入未封控区域\n");
	return 0;
}
