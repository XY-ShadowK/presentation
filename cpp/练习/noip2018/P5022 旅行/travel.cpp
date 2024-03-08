#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef struct tCITY{
	int road;
	int next_city[5005];
	bool arrived;
	void add_city(int next)
	{
		next_city[road]=next;
		road++;
	}
	tCITY()
	{
		road=0;
		arrived=true;
	}
}CT;
int n,m,travel[5005];
CT city[5005];/*
void trip(int city_num)
{
	int roads=city[city_num].road,i;
	for(i=0;i<roads;i++){
		if(city[city[city_num].next_city[i]].arrived){
			city[city[city_num].next_city[i]].arrived=false;
			trip(city[city_num].next_city[i]);
		}
	}
}
void trip(int city_num,string min_str,int now)
{
	city[city_num].arrived=false;
	int roads=city[city_num].road,i;
	string str;
	sort(city[city_num].next_city,city[city_num].next_city+roads);
	for(i=0;i<roads;i++){
		if(city[city[city_num].next_city[i]].arrived){
			now++;
			str=city[city_num].next_city[i];
			trip(city[city_num].next_city[i],min_str+str);
			break;
		}
	}
	return;
}*/
int trip(int order,int city_num,bool used)
{
//	cout<<order<<'_'<<city_num<<'-'<<used<<endl;
	travel[order]=city_num;
	city[city_num].arrived=false;;
	if(order==n-1){
		return n;
	}
	int roads=city[city_num].road,next_num=99999,i,temp;
	sort(city[city_num].next_city,city[city_num].next_city+roads);
	if(order>0){
		for(i=0;i<roads;i++){
			if(city[city[city_num].next_city[i]].arrived){
				next_num=city[city_num].next_city[i];
				break;
			}
		}
		temp=trip(order-1,travel[order-1],true);
		next_num=next_num>temp?temp:next_num;
	}
	else{
		for(i=0;i<roads;i++){
			if(city[city[city_num].next_city[i]].arrived){
				next_num=city[city_num].next_city[i];
				break;
			}
		}
	}
	if(used){
		return next_num;
	}
	travel[order+1]=next_num;
	return trip(order+1,travel[order+1],false);
}
int main()
{
	cin>>n>>m;
	int i,temp1,temp2;
	for(i=1;i<=m;i++){
		cin>>temp1>>temp2;
		city[temp1].add_city(temp2);
		city[temp2].add_city(temp1);
	}
	trip(0,1,false); 
	for(i=0;i<n-1;i++){
		cout<<travel[i]<<' ';
	}
	cout<<travel[i];
	return 0;
} 
