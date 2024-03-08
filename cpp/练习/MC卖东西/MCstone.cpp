#include <iostream>
#include <string>
using namespace std;
typedef struct tMinecraft_Subject_Property{
	string sName;
	int StackSize;
	int Cost;
	int Quantity;
	int Real_Cost;
	void add(int number)
	{
		Quantity+=number;
	}
	void start(string name,int number,int value,int size)
	{
		sName=name;
		Quantity=number;
		Cost=value;
		StackSize=size;
		Real_Cost=Cost*StackSize;
	}
}MSP;
MSP subject[105];
int now=0,bag,n;
void AddSubject(int num,int value,int ssize,string name)
{
	int i;
	for(i=0;i<now;i++){
		if(name==subject[i].sName){
			subject[i].add(num);
			return;
		}
	}
	subject[now].start(name,num,value,ssize);
	now++;
}
int Maxn()
{
	int maxn=0,maxi,maxnum,nownum,i,now_money;
	for(i=0;i<now;i++){
		now_money=subject[i].Real_Cost;
		nownum=subject[i].StackSize;
		if(subject[i].Quantity<subject[i].StackSize){
			now_money=subject[i].Cost*subject[i].Quantity;
			nownum=subject[i].Quantity;
		}
		if(now_money>maxn){
			maxn=now_money;
			maxi=i;
			maxnum=nownum;
		}
	}
	subject[maxi].Quantity-=maxnum;
	return maxn;
}
int main()
{
	cin>>bag>>n;
	bag=21-bag;
	int i,j,ai,bi,ci;
	string sti;
	for(i=0;i<n;i++){
		cin>>ai>>bi>>ci>>sti;
		AddSubject(ai,bi,ci,sti);
	}
	int money=0;
	for(i=0;i<bag;i++){
		money+=Maxn();
	}
	cout<<money<<endl;
	return 0;
}
