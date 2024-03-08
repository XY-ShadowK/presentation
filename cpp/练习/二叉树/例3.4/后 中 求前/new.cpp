//输入中序遍历和后序遍历求先序遍历 
#include <iostream>
#include <string>
using namespace std;
void PreOrderTraverse(string InOT,string PostOT)
{
	if(InOT.empty()&&PostOT.empty()){
		return;
	}
	cout<<PostOT[PostOT.size()-1];
	if(InOT.size()==1&&PostOT.size()==1){
		return;
	}
	int m=InOT.find(PostOT[PostOT.size()-1]);
	PreOrderTraverse(InOT.substr(0,m),PostOT.substr(0,m));
	PreOrderTraverse(InOT.substr(m+1,InOT.size()-m-1),PostOT.substr(m,InOT.size()-m-1));
	return;
}
string s1,s2;
int main()
{
	cin>>s1>>s2;
	PreOrderTraverse(s1,s2);
	cout<<endl;
	return 0;
}
