#include <iostream>
#include <cstring>
using namespace std;
int max(char HI1[],char HI2[])
{
	return (strlen(HI1)>strlen(HI2))?strlen(HI1):strlen(HI2);
}
typedef struct tHighInt{
	char Hint[1001];
	operator+(const tHighInt a)const
	{
		int i,cd=max(Hint,a.Hint);
		char tmp[1001];
		for(i=0;i<cd;i++){
			tmp[i]='0';
			tmp[i+1]='0';
			if((Hint[i]+a.Hint[i]+tmp[i]-'0'-'0'-'0')<10){
				tmp[i]=(char)(Hint[i]+a.Hint[i]+tmp[i]-'0'-'0');
			}
			else{
				tmp[i]=(char)((Hint[i]+a.Hint[i]+tmp[i]-'0'-'0'-'0')%10+'0');
				tmp[i+1]='1';
			}
		}
		return tmp;
	}
}HInt; 
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;)
	}
	return 0;
}
