#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <fstream>
using namespace std;
ifstream fin("socialnetwork.txt");
multimap<int,int> followRelation;
void getFollowList()
{
	int follower,followed;
	while(!fin.eof()){
		fin>>follower>>followed;
		followRelation.insert(make_pair(follower,followed));
	}
	return;
}
set<int> getFollowed(int user)
{
	multimap<int,int>::iterator mapIt;
	set<int> st;
	mapIt=followRelation.find(user);
	if(user==mapIt->first){
		for(multimap<int,int>::iterator it=mapIt;it->first==user;it++)
			st.insert(it->second);
	}
	return st;
}
int main()
{
	set<int> userSet;
	getFollowList();
	int user;
	cin>>user;
	while(user!=0){
		userSet=getFollowed(user); 
		if(!userSet.empty()){
			set<int> userSet2;
			cout<<"该用户关注的其他用户为: ";
			for(set<int>::iterator it=userSet.begin();it!=userSet.end();it++){
				cout<<*it<<' ';
				set<int> _userSet2=getFollowed(*it);
				userSet2.insert(_userSet2.begin(),_userSet2.end());
			}
			cout<<endl<<"该用户关注的用户关注的其他用户为: ";
			for(set<int>::iterator it=userSet2.begin();it!=userSet2.end();it++)
				cout<<*it<<' ';
			cout<<endl;
		}
		else cout<<"用户不存在！"<<endl;
		cin>>user;
	}
	return 0;
}
