#include <iostream>
#include <algorithm>
using namespace std;
typedef struct tSubject{
	int cost;
	int importance;
	int ci;
}S;
bool cmp(S a,S b)
{
	return a.ci>b.ci;
}
S subject[26];
int n,m;
int main()
{
	cin>>n>>m;
	int i;
	for(i=0;i<m;i++){
		cin>>subject[i].cost>>subject[i].importance;
		subject[i].ci=subject[i].cost*subject[i].importance;
	}
	sort(subject,subject+m,cmp);
	int _ci=0;
	for(i=0;i<m;i++){
		if(subject[i].cost<=n){
			_ci+=subject[i].ci;
			n-=subject[i].cost;
		}
	}
	cout<<_ci<<endl;
	return 0;
}
