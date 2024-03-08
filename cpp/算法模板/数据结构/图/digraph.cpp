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
typedef int key;
typedef int value;
multimap<key,value> digraph;
set<value> findKey(multimap<key,value> m,key k)
{
	multimap<key,value>::iterator it=m.find(k),end=m.end();
	set<value> st;
	for(;it!=end&&it->first==k;it++)st.insert(it->second);
	return st;
}
set<key> findValue(multimap<key,value> m,value v)
{
	multimap<key,value>::iterator it=m.begin(),end=m.end();
	set<key> st;
	for(;it!=end;it++)if(it->second==v)st.insert(it->first);
	return st;
}
template<typename T> void printAllSet(set<T> st)
{
	if(st.size()==0){
		cout<<"无"<<endl;
		return;
	}
	typename set<T>::iterator it=st.begin(),end=st.end();
	for(;it!=end;it++)cout<<*it<<' ';
	cout<<endl;
	return;
}
void printNodeStatus(key node)
{
	set<key> stK=findValue(digraph,node);
	set<value> stV=findKey(digraph,node);
	if(stK.size()==0&&stV.size()==0){
		cout<<"结点不存在！"<<endl;
		return;
	}
	cout<<"结点入度为: "<<stK.size()<<",出度为: "<<stV.size()<<endl;
	cout<<"结点入度边邻居为: "<<endl;
	printAllSet<key>(stK);
	cout<<"结点出度边邻居为: "<<endl;
	printAllSet<value>(stV);
	return;
}
int main()
{
	cout<<"建立有向图"<<endl;
	cout<<"输入两个结点编号，代表一条从第一个编号结点至第二个编号结点的有向边(任意一个为-1中止)"<<endl;
	key k=0,node=0;
	value v=0;
	while(k!=-1&&v!=-1){
		cin>>k>>v;
		digraph.insert(make_pair(k,v));
	}
	cout<<"查找结点状态"<<endl;
	cout<<"输入结点编号查找此节点状态(输入-1中止)"<<endl;
	while(node!=-1){
		cin>>node;
		printNodeStatus(node);
	}
	return 0;
}
