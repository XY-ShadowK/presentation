#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int a,b,ta,tb;
	scanf("%d%d",&a,&b);
	ta=a<<1,tb=b<<1;
	printf("%d  %d\n",ta,tb);
	ta=a>>1,tb=b>>1;
	printf("%d  %d\n",ta,tb);
	ta=a&1,tb=b&1;
	printf("%d  %d\n",ta,tb);
	ta=a^1,tb=b^1;
	printf("%d  %d\n",ta,tb);
	ta=~a,tb=~b;
	printf("%d  %d\n",ta,tb);
    return 0;
}
