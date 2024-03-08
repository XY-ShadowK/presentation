#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
ofstream fout("space_change.out");
string ss,s;
int len;
int main()
{
	while(getline(cin,ss)){
		len=ss.size();
		s=ss[0];
		for(int i=1;i<len;i++){
			if(ss[i]==' ')s=s+"¡¡";
			else s=s+ss[i];
		}
		fout<<s<<endl;
	}
	return 0;
}
