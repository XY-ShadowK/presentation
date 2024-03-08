#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
long long n,aa=0,ab=0,ac=0,ad=0,temp,maxn,team;
inline long long mmax(long long num1,long long num2,long long t)
{
	if(num1>=num2)return num1;
	else{
		team=t;
		return num2;
	}
}
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>temp;
		switch(i%4){
			case 0 : {
				ad+=temp;
				break;
			}
			case 1 : {
				aa+=temp;
				break;
			}
			case 2 : {
				ab+=temp;
				break;
			}
			case 3 : {
				ac+=temp;
				break;
			}
		}
	}
	maxn=aa;
	team=1;
	maxn=mmax(maxn,ab,2);
	maxn=mmax(maxn,ac,3);
	maxn=mmax(maxn,ad,4);
	switch(team%4){
		case 0 : {
			cout<<"D"<<endl;
			break;
		}
		case 1 : {
			cout<<"A"<<endl;
			break;
		}
		case 2 : {
			cout<<"B"<<endl;
			break;
		}
		case 3 : {
			cout<<"C"<<endl;
			break;
		}
	}
	return 0;
}
