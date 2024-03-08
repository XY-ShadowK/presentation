#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n=0;
string ss[100];
typedef struct tTree{
	int kids[26],now,father;
	void birth(int kid,char me)
	{
		kids[me-'A']=kid;
		now++;
	}
	tTree()
	{
		now=0;
		father=-1;
	}
}tree;
tree n1[500];
int main()
{
	int i=0,j,num=1;
	while(cin>>ss[i]){
		i++;
		n++;
	}
	for(i=0;i<n;i++){
		for(j=0;j<ss[i].size();j++){
			
		}
	}
	return 0; 
}
