#define N 10
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std; 
typedef struct tStudent
{
	char no[11],name[20];
    int score;
}Stu;
Stu ss[N]={{"2035041122","������",79},{"2035052816","���Ƿ�",82},{"2035040120","���",62},{"2035040313","������",71},{"2035041215","��׿",72},{"2035052227","����",73},{"2035052211","���",61},{"2035052512","����",81},{"2035052827","��˼��",86},{"2035040520","���ӻ�",69}};
bool cmp(Stu a,Stu b)
{
	return a.score<b.score;
}
void output(Stu stu[])
{
    int i;
    printf("\n\t\t\t�ɼ���\n\n\t|   ѧ��   |       ����     |   �ɼ�  |\n");
	printf("\t***********************\n");
    for(i=0;i<N;i++)
    {
        printf("\t|%s|%16s|%9d|\n ",stu[i].no,stu[i].name,stu[i].score);
    	printf("\t*********************\n");
    }
}
int main()
{
	sort(ss,ss+N,cmp);
    output(ss);
    return 0;
}
