//输入先序遍历和中序遍历求后序遍历 
#include <iostream>
#include <string>
using namespace std;
void PostOrderTraverse(string PreOT,string InOT)
{
	if(PreOT.empty()&&InOT.empty()){
		return;
	}
	if(PreOT.size()==1&&InOT.size()==1){
		cout<<PreOT;
		return;
	}
	int m=InOT.find(PreOT[0]);
	PostOrderTraverse(PreOT.substr(1,m),InOT.substr(0,m));
	PostOrderTraverse(PreOT.substr(m+1,PreOT.size()-m-1),InOT.substr(m+1,InOT.size()-m-1));
	cout<<PreOT[0];
	return;
}
string s1,s2;
int main()
{
	cin>>s1>>s2;
	PostOrderTraverse(s1,s2);
	cout<<endl;
	return 0;
}
