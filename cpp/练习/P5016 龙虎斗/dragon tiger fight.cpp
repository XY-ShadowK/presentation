#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("dtf.in");
int home[100005],n,m;
long long s1,p1,s2;
int main()
{
	cin>>n;
//	fin>>n;
	long long i,q_dragon=0,q_tiger=0,far;
	for(i=1;i<=n;i++){
		cin>>home[i];
//		fin>>home[i];
	}
	cin>>m>>p1>>s1>>s2;
//	fin>>m>>p1>>s1>>s2;
//	cout<<s2/2<<endl; 
	home[p1]+=s1;
	for(i=1;i<m;i++){
		q_dragon+=home[i]*(m-i);
	}
	for(i=n;i>m;i--){
		q_tiger+=home[i]*(i-m);
	}
//	cout<<q_dragon<<' '<<q_tiger<<endl;
	if(q_dragon>q_tiger){
		far=q_dragon-q_tiger;
		far=(long long)(far%s2>s2/2?far/s2+1:far/s2);
		cout<<(m+far>n?n:m+far)<<endl;
	}
	else{
		far=q_tiger-q_dragon;
		far=(long long)(far%s2>s2/2?far/s2+1:far/s2);
		cout<<(m-far<1?1:m-far)<<endl;
	}
	return 0;
}
