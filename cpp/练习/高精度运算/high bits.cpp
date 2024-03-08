#include <iostream>
#include <string>
#include <cmath>
using namespace std;
unsigned long long ulpow(unsigned long long x,unsigned long long y)
{
	unsigned long long i,temp=x;
	for(i=1;i<y;i++){
		temp*=x;
	}
	return temp;
}
unsigned long long f_bits(unsigned long long num)
{
	unsigned long long i;
	for(i=0;num!=0;i++){
		num=num/10;
	}
	return i;
}
string ul_to_str_change(unsigned long long num)
{
	int sz=f_bits(num);
	int i,h=-1;
	string temp(sz,'0');
	unsigned long long hx,nx;
	for(i=sz-1;i>-1;i--){
		hx=ulpow(10,i+1);
		nx=ulpow(10,i);
		temp[++h]=(char)(((num%hx)/(nx==0?1:nx))+'0');
	}
	return temp;
}
typedef struct tHighNum{
	string x;
	string operator+(const tHighNum& b)
	{
		if(x[0]=='-'){
			tHighNum st1,st2;
			st1.x=b.x;
			st2.x=x.substr(1,x.size()-1);
			return st1-st2;
		}
		if(b.x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x;
			st2.x=b.x.substr(1,b.x.size()-1);
			return st1-st2;
		}
		int temp;
		int i,la=x.size(),lb=b.x.size(),cs=la>lb?la:lb;
		string A,B,ans(cs+1,'0'),aout;
		A=x[la-1];
		for(i=la-2;i>-1;i--){
			A=A+x[i];
		}
		for(i=cs-1;i>=la;i--){
			A=A+"0";
		}
		B=b.x[lb-1];
		for(i=lb-2;i>-1;i--){
			B=B+b.x[i];
		}
		for(i=cs-1;i>=lb;i--){
			B=B+"0";
		}
		for(i=0;i<cs;i++){
			temp=(int)(A[i]+B[i]+ans[i]-'0'-'0'-'0');
			ans[i]=(char)(temp%10+'0');
			ans[i+1]=(char)(temp/10+'0');
		}
		int de_zero=0;
		cs=ans.size();
		for(i=cs-1;i>0;i--){
			if(ans[i]=='0'){
				de_zero++;
			}
			else{
				break;
			}
		}
		cs-=de_zero;
		aout=ans[cs-1];
		for(i=cs-2;i>-1;i--){
			aout=aout+ans[i];
		}
		return aout;
	}
	string operator-(const tHighNum& b)
	{
		string t;
		if(x[0]=='-'&&b.x[0]=='-'){
			tHighNum st1,st2;
			st1.x=b.x.substr(1,b.x.size()-1);
			st2.x=x.substr(1,x.size()-1);
			return st1-st2;
		}
		if(x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x.substr(1,x.size()-1);
			st2.x=b.x;
			t=st1+st2;
			t="-"+t;
			return t;
		}
		if(b.x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x;
			st2.x=b.x.substr(1,b.x.size()-1);
			return st1+st2;
		}
		int i,la=x.size(),lb=b.x.size(),cs=la>lb?la:lb;
		int temp,A[100000]={0},B[100000]={0},ans[100000]={0};
		string aout;
		for(i=0;i<la;i++){
			A[i]=(int)(x[la-i-1]-'0');
		}
		for(i=0;i<lb;i++){
			B[i]=(int)(b.x[lb-i-1]-'0');
		}
		bool pd=false;
		int tmp;
		if(lb>la||A[cs-1]<B[cs-1]){
			for(i=0;i<cs;i++){
				tmp=A[i];
				A[i]=B[i];
				B[i]=tmp;
			}
			pd=true;
		}
		for(i=0;i<cs;i++){
			temp=A[i]-B[i]+ans[i];
			if(temp<0){
				temp+=10;
				ans[i]=temp;
				ans[i+1]--;
			}
			else{
				ans[i]=temp;
			}
		}
		int de_zero=0;
		for(i=cs-1;i>-1;i--){
			if(ans[i]==0){
				de_zero++;
			}
			else{
				break;
			}
		}
		cs-=de_zero;
		if(pd==true){
			aout="-";
		}
		else{
			cs--;
			aout=(char)(ans[cs]+'0');
		}
		for(i=cs-1;i>-1;i--){
			aout=aout+(char)(ans[i]+'0');
		}
		return aout;
	}
	string operator*(const tHighNum& b)
	{
		string t;
		if(x[0]=='-'&&b.x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x.substr(1,x.size()-1);
			st2.x=b.x.substr(1,b.x.size()-1);
			return st1*st2;
		}
		if(x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x.substr(1,x.size()-1);
			st2.x=b.x;
			t=st1*st2;
			t="-"+t;
			return t;
		}
		if(b.x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x;
			st2.x=b.x.substr(1,b.x.size()-1);
			t=st1*st2;
			t="-"+t;
			return t;
		}
		string temp="0";
		int i,la=x.size(),lb=b.x.size();
		string A,B,aout="0";
		A=x[la-1];
		for(i=la-2;i>-1;i--){
			A=A+x[i];
		}/*
		B=b.x[lb-1];
		for(i=lb-2;i>-1;i--){
			B=B+b.x[i];
		}*/
		for(i=0;i<la;i++){
			int cs=(int)(A[i]-'0');
//			cout<<" cs="<<cs;
			for(int j=0;j<cs;j++){
				tHighNum st1,st2;
				st1.x=temp;
				st2.x=b.x;
				temp=st1+st2;
//				cout<<" temp="<<temp;
			}
			for(int j=0;j<i;j++){
				temp=temp+"0";
			}
			tHighNum st1,st2;
			st1.x=aout;
			st2.x=temp;
			aout=st1+st2;
			temp="0";
//			cout<<" aout="<<aout;
		}
		return aout;
	}
	string operator/(const tHighNum& b)
	{
		string t;
		if(b.x=="0"){
			return b.x;
		}
		if(x[0]=='-'&&b.x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x.substr(1,x.size()-1);
			st2.x=b.x.substr(1,b.x.size()-1);
			return st1/st2;
		}
		if(x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x.substr(1,x.size()-1);
			st2.x=b.x;
			t=st1/st2;
			t="-"+t;
			return t;
		}
		if(b.x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x;
			st2.x=b.x.substr(1,b.x.size()-1);
			t=st1/st2;
			t="-"+t;
			return t;
		}
		string i;
		string temp=x;
		tHighNum st2,st1,s1,s2;
		st2.x=b.x;
		s2.x="1";
		for(i="-1";temp[0]!='-';s1.x=i,i=s1+s2){
			st1.x=temp;
			temp=st1-st2;
		}
		return i;
	}
	string operator%(const tHighNum& b)
	{
		string t;
		if(b.x=="0"){
			return b.x;
		}
		if(x[0]=='-'&&b.x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x.substr(1,x.size()-1);
			st2.x=b.x.substr(1,b.x.size()-1);
			return st1%st2;
		}
		if(x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x.substr(1,x.size()-1);
			st2.x=b.x;
			t=st1%st2;
			t="-"+t;
			return t;
		}
		if(b.x[0]=='-'){
			tHighNum st1,st2;
			st1.x=x;
			st2.x=b.x.substr(1,b.x.size()-1);
			t=st1%st2;
			t="-"+t;
			return t;
		}
		string i;
		string temp=x;
		tHighNum st2,st1,s1,s2;
		st2.x=b.x;
		s2.x="1";
		for(i="-1";temp[0]!='-';s1.x=i,i=s1+s2){
			st1.x=temp;
			temp=st1-st2;
		}
		st1.x=temp;
		return st1+st2;
	}
	bool operator<(const tHighNum& b)
	{
		tHighNum st1;
		st1.x=x;
		string ans=st1-b;
		return ans[0]=='-';
	}
	bool operator>(const tHighNum& b)
	{
		tHighNum st1,st2;
		st1.x=x;
		st2.x=b.x;
		string ans=st2-st1;
		return ans[0]=='-';
	}
	bool operator<=(const tHighNum& b)
	{
		tHighNum st1,st2;
		st1.x=x;
		st2.x=b.x;
		string ans=st2-st1;
		return ans[0]!='-';
	}
	bool operator>=(const tHighNum& b)
	{
		tHighNum st1;
		st1.x=x;
		string ans=st1-b;
		return ans[0]!='-';
	}
	bool operator==(const tHighNum& b)
	{
		tHighNum st1,st2,st3;
		st1.x=x;
		st2.x=b.x;
		string ans=st1-st2;
		return !(int)(ans[0]-'0');
	}
	string operator^(const tHighNum& b)
	{
		if(x=="0"){
			return x;
		}
		if(b.x=="0"){
			return "1";
		}
		string sum=x;
		tHighNum st1,st2,st3,st4;
		st2.x="1";
		st4.x=x;
		for(st1.x="1";st1<b;st1.x=st1+st2){
			st3.x=sum;
			sum=st3*st4;
		}
		return sum;
	} 
}Hnum;
Hnum a,b;
int main()
{
	char fh;
	cin>>a.x>>fh>>b.x;
	switch(fh){
		case '+' : {
			cout<<a+b<<endl;
			break;
		}
		case '-' : {
			cout<<a-b<<endl;
			break;
		}
		case '*' : {
			cout<<a*b<<endl;
			break;
		}
		case '/' : {
			cout<<a/b<<"��"<<a%b<<endl;
			break;
		}
	}
	return 0;
}
