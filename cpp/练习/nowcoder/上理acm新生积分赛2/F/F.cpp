#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <set>
using namespace std;
int t,n,k,l,cnt=0,tt;
bool tof[30];
int main()
{
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++)tof[i]=true;
		cnt=n;
		l=0;
		tt=0;
		while(cnt){
			if(tof[l]){
				tt++;
				if(tt==k){
					cout<<l+1<<' ';
					tt=0;
					cnt--;
					tof[l]=false;
				}
			}
			l=(l+1)%n;
		}
		cout<<endl;
	}
	return 0;
}
