#include <iostream>
using namespace std;
int sz[10]={6,2,5,5,4,5,6,3,7,6},sum=0;
void ds(int n,int num,int gs)
{
	if(gs==3){
		switch(n){
			case 2 : {
				if(num==1){
					sum++;
				}
				return;
			}
			case 3 : {
				if(num==7){
					sum++;
				}
				return;
			}
			case 4 : {
				if(num==4){
					sum++;
				}
				return;
			}
			case 5 : {
				if(num==2||num==3||num==5){
					sum++;
				}
				return;
			}
			case 6 : {
				if(num==0||num==6||num==9){
					sum++;
				}
				return;
			}
			case 7 : {
				if(num==8){
					sum++;
				}
				return;
			}
		}
	}
	else{
		if(n>=2){
			ds(n-2,num+1,gs+1);
			if(n>=3){
				ds(n-3,num+7,gs+1);
				if(n>=4){
					ds(n-4,num+4,gs+1);
					if(n>=5){
						ds(n-5,num+2,gs+1);
						ds(n-5,num+3,gs+1);
						ds(n-5,num+5,gs+1);
						if(n>=6){
							ds(n-6,num+0,gs+1);
							ds(n-6,num+6,gs+1);
							ds(n-6,num+9,gs+1);
							if(n>=7){
								ds(n-7,num+8,gs+1);
							}
						}
					}
				}
			}
		}
	}
	return;
}
int main()
{
	int n,i,j,k;
	cin>>n;
	ds(n-4,0,1);
	cout<<sum;
	return 0;
}
