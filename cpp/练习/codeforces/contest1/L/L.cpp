#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
int n,t;
struct tSkill{
	unsigned int level,num;
}skill[100010];
bool cmp(tSkill s1,tSkill s2)
{
	return s1.level>s2.level;
}
int main()
{
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>t;
		skill[i].level=t;
		skill[i].num=i;
	}
	sort(skill+1,skill+n+1,cmp);
	if(skill[1].level!=skill[2].level)cout<<skill[1].num<<endl;
	else cout<<-1<<endl;
	return 0;
}

