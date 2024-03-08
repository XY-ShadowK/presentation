#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
string rhyme;
int main()
{
	int length,num=1,head=0,t,i=0,j=0;
	cin>>rhyme;
	length=rhyme.size();
	while(i<length){
		j=i+1;
		while(j<length){
			if(rhyme[i]!=rhyme[j])break;
			j++;
		}
		cout<<rhyme[i]<<j-i;
		i=j;
	}
	return 0;
}

