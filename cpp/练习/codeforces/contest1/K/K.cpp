#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
string rhyme_origin,temp,rhyme_copy="";
int main()
{
	int length,num=1,head=0,t;
	char comparison;
	cin>>rhyme_origin;
	rhyme_origin=rhyme_origin+'*';
	length=rhyme_origin.size();
	comparison=rhyme_origin[0];
	for(int i=1;i<length;i++){
		if(rhyme_origin[i]!=comparison){
			stringstream turn;
			t=i-head;
			turn<<t;
			turn>>temp;
			temp=comparison+temp;
			rhyme_copy=rhyme_copy+temp;
			temp="";
			head=i;
			comparison=rhyme_origin[i];
		}
	}
	cout<<rhyme_copy<<endl;
	return 0;
}
