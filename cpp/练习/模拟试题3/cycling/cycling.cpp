#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cycling.in");
ofstream fout("cycling.out");
int n,hill[1001];
int main()
{
//	cin>>n;
	fin>>n;
	int i,max=-1,head=-1,tail=-1,s=0,e=0;
	for(i=0;i<n;i++){
//		cin>>hill[i];
		fin>>hill[i];
	}
	hill[n]=-1;
	head=hill[0];
	for(i=1;i<=n;i++){
		if(hill[i]>=head&&hill[i]!=tail){
			tail=hill[i];
			e=i;
		}
		else{
			if(max<(tail-head)&&s<e){
				max=tail-head;
			}
			head=hill[i];
			s=i;
		}
	}
//	cout<<(max==-1?0:max)<<endl;
	fout<<(max==-1?0:max)<<endl;
	return 0;
} 
