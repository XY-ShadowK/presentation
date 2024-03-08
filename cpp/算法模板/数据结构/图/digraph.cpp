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
		cout<<"��"<<endl;
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
		cout<<"��㲻���ڣ�"<<endl;
		return;
	}
	cout<<"������Ϊ: "<<stK.size()<<",����Ϊ: "<<stV.size()<<endl;
	cout<<"�����ȱ��ھ�Ϊ: "<<endl;
	printAllSet<key>(stK);
	cout<<"�����ȱ��ھ�Ϊ: "<<endl;
	printAllSet<value>(stV);
	return;
}
int main()
{
	cout<<"��������ͼ"<<endl;
	cout<<"������������ţ�����һ���ӵ�һ����Ž�����ڶ�����Ž��������(����һ��Ϊ-1��ֹ)"<<endl;
	key k=0,node=0;
	value v=0;
	while(k!=-1&&v!=-1){
		cin>>k>>v;
		digraph.insert(make_pair(k,v));
	}
	cout<<"���ҽ��״̬"<<endl;
	cout<<"�������Ų��Ҵ˽ڵ�״̬(����-1��ֹ)"<<endl;
	while(node!=-1){
		cin>>node;
		printNodeStatus(node);
	}
	return 0;
}
