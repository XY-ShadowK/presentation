#include <iostream>
#include <string>
using namespace std;
//ifstream fin("add.in");
//ofstream fout("add.out");
string super_add(string l1,string l2)
{
	string t1,t2,t3;
	int a=0,n,m,i;
	if(l1.size()>l2.size()){
		n=l2.size();
		m=l1.size();
		t1=l1.substr(m-n,n);
		t2=l2;
		t3=l1.substr(0,m-n);
	}
	else{
		n=l1.size();
		m=l2.size();
		t1=l2.substr(m-n,n);
		t2=l1;
		t3=l2.substr(0,m-n);
	}
	string temp(n+1,'0');
	for(i=n-1;i>=0;i--){
		a+=(int)t1[i]+t2[i]-'0'-'0';
		if(a>9){
			temp[i+1]=(char)a%10+temp[i+1];
			a=a/10;
		}
		else{
			temp[i+1]=(char)a+temp[i+1];
			a=0;
		}
	}
	if(a!=0){
		temp[0]=(char)a+temp[0];
	}
	if(temp[0]!='0'){
		t3=super_add(t3,temp.substr(0,1))+temp.substr(1,n);
	}
	else{
		t3=t3+temp.substr(1,n);
	}
	return t3;
}
int main()
{
	string l1,l2;
	cin>>l1>>l2;
	//fin>>l1>>l2;
	cout<<super_add(l1,l2);
	//fout<<super_add(l1,l2);
	return 0;
}
