#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
string f,e,t;
queue<string> sch,sbl,ssh,sint,sl,sfl,sdl,sll,sld;
inline void push(string k)
{
	if(k.substr(0,4)=="char"){sch.push(k);return;}
	if(k.substr(0,4)=="bool"){sbl.push(k);return;}
	if(k.substr(0,5)=="short"){ssh.push(k);return;}
	if(k.substr(0,3)=="int"){sint.push(k);return;}
	if(k.substr(0,9)=="long long"){sll.push(k);return;}
	if(k.substr(0,11)=="long double"){sld.push(k);return;}
	if(k.substr(0,4)=="long"){sl.push(k);return;}
	if(k.substr(0,5)=="float"){sfl.push(k);return;}
	if(k.substr(0,6)=="double"){sdl.push(k);return;}
	e=k;
	return;
}
int main()
{
	std::ios::sync_with_stdio(false);
	getline(cin,f);
	while(e.empty()){
		getline(cin,t);
		push(t);
	}
	cout<<f<<endl;
	while(!sch.empty()){cout<<sch.front()<<endl;sch.pop();}
	while(!sbl.empty()){cout<<sbl.front()<<endl;sbl.pop();}
	while(!ssh.empty()){cout<<ssh.front()<<endl;ssh.pop();}
	while(!sint.empty()){cout<<sint.front()<<endl;sint.pop();}
	while(!sl.empty()){cout<<sl.front()<<endl;sl.pop();}
	while(!sfl.empty()){cout<<sfl.front()<<endl;sfl.pop();}
	while(!sdl.empty()){cout<<sdl.front()<<endl;sdl.pop();}
	while(!sll.empty()){cout<<sll.front()<<endl;sll.pop();}
	while(!sld.empty()){cout<<sld.front()<<endl;sld.pop();}
	cout<<e;
	return 0;
}
