#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <set>
#include <queue>
using namespace std;
typedef struct tDataWithTime
{
	string str;
	int time,node;
}dwt;
bool operator< (const tDataWithTime& t1,const tDataWithTime& t2)
{
	return t1.str!=t2.str;
}
int n,cnt=0;
dwt t,p[105];
set<dwt> st;
bool cmp(dwt aa,dwt bb)
{
	return aa.time<bb.time;
}
int main()
{
//	cout<<"My Input:"<<endl<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t.str>>t.time;
		t.node=i;
		st.insert(t);
	}
	set<dwt>::iterator it;
	for(it=st.begin();it!=st.end();it++)p[cnt++]=*it;
//	cout<<endl<<"The first Output from set:"<<endl<<endl;
	for(int i=0;i<cnt;i++)cout<<p[i].str<<' '<<p[i].time<<' '<<p[i].node<<endl;
	sort(p,p+n,cmp);
//	cout<<endl<<"The second Output with sort:"<<endl<<endl;
 	for(int i=0;i<cnt;i++)cout<<p[i].str<<' '<<p[i].time<<' '<<p[i].node<<endl;
//	for(int i=0;i<cnt;i++)cout<<p[i].node<<endl;
	return 0;
}
