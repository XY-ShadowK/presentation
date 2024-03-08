#include <iostream>
#include <string>
using namespace std;
typedef struct jh{
	bool zm[26];
	string str;
	void jhin()
	{
		cin>>str;
		for(int i=0;i<str.size();i++){
			zm[str[i]-'a']=true;
		}
	}
	
}JH;
