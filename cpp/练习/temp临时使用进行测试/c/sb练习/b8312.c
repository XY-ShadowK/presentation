#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	char phnum[20],yon,tme[50];
	int dct;
	printf("����������ֻ���: ");
	gets(phnum);
	printf("����ֻ���Ϊ: ");
	puts(phnum);
	printf("��ȷ�� (y/n)");
	scanf("%c",&yon);
	if(!(yon-'n')){
		printf("�ֻ��Ų���ȷ���˳�������лл!\n");
		return 0;
	}
	printf("\n\t�����������\n1--516У��������\t2--516У���о�����1����\n\t����������������\n");
	scanf("%d",&dct);
	printf("\t���������������ʱ��\n");
	getchar();
	gets(tme);
	printf("\t�ֻ���Ϊ: %s ��%s",phnum,tme);
	switch(dct){
		case 1 : {
			printf(";��516У��������\n");
			return 0;
		}
		case 2 : {
			printf(";��516У���о�����1����\n");
			return 0;
		}
	}
	printf("����δ�������\n");
	return 0;
}
