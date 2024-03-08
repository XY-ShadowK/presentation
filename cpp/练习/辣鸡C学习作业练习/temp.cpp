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
Stu ss[N]={{"2035041122","刘诚宇",79},{"2035052816","李智凡",82},{"2035040120","刘睿锋",62},{"2035040313","张怡静",71},{"2035041215","陈卓",72},{"2035052227","徐阳",73},{"2035052211","李冬杰",61},{"2035052512","郭斌",81},{"2035052827","许思文",86},{"2035040520","梁子华",69}};
bool cmp(Stu a,Stu b)
{
	return a.score<b.score;
}
void output(Stu stu[])
{
    int i;
    printf("\n\t\t\t成绩表\n\n\t|   学号   |       姓名     |   成绩  |\n");
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
