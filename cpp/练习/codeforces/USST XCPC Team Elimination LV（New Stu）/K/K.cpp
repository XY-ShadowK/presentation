#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
string ss;
string::size_type s;
int main()
{
	getline(cin,ss);
	if(ss.find("?")!=string::npos){
		cout<<7<<endl;
		return 0;
	}
	s=ss.find("Sussu");
	if(s!=string::npos&&(s==0||ss[s-1]==' ')&&(ss[s+5]=='.'||ss[s+5]==' '||ss[s+5]=='!')){
		cout<<"AI SUSSU!"<<endl;
		return 0;
	}
	cout<<"O cara é bom!"<<endl;
	return 0;
}
