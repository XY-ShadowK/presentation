#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int ans1,n,dd[10001],f1[10001],f2[10001],a1=-1,a2=-1,pd=0;
void l_add()
{
	int i;
	
}
int main()
{
	cin>>n;
	int i;
	memset(f1,-1,sizeof(f1));
	memset(f2,-1,sizeof(f2));
	for(i=0;i<n;i++){
		cin>>dd[i];
	}
	for(i=0;i<n;i++){
		if(a1!=-1){
			if(dd[i]<=f1[a1]&&pd==0){
				a1++;
				f1[a1]=dd[i];
			}
			else{
				if(a2!=-1){
					if(dd[i]<=f2[a2]){
						a2++;
						f2[a2]=dd[i];
					}
					else{
						l_add();
					}
				}
				else{
					a2++;
					f2[a2]=dd[i];
					pd=-1;
				}
			}
		}
		else{
			a1++;
			f1[a1]=dd[i];
		}
	}
	return 0;
}
