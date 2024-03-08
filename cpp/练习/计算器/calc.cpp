#include <iostream>
#include <string>
using namespace std;
const string Count="count";
const string Command="command";
const string Exit="exit";
const string Skip="skip";
int getstring(string &str)
{
	char read;
	string write;
	while(read!='#'){
		cin>>write;
		read=write[write.size()-1];
		str=str+write;
	}
	str=str.substr(0,str.size()-1);
	return str.size();
}
int s[500];
string ss;
void count(string str)
{
	
}
void count()
{
	int temp;
	string strs;
	while(1){
		getstring(strs);
		if((int)strs.find(Exit)!=-1){
			ss=Exit;
			return;
		}
		if((int)strs.find(Skip)!=-1)return;
		if((int)strs.find(Command)!=-1)command();
		if((int)strs.find('=')!=-1)s[strs[strs.find('=')-1]]=count(strs.substr(strs.find('=')+1));
		else count(strs);
	}
}
int main()
{
	while(1){
		getstring(ss);
		if((int)ss.find(Count)!=-1)		count();
		if((int)ss.find(Command)!=-1)	command();
		if((int)ss.find(Exit)!=-1)		return 0;
	}
	return 0;
}
