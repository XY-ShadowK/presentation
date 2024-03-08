#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
int piles[2],direction,num;
int main()
{
	cin>>piles[0]>>piles[1];
	while(piles[0]!=0||piles[1]!=0){
		if(piles[0]>piles[1]){
			cout<<1<<' '<<piles[0]-piles[1]<<endl;
			piles[0]=piles[1];
		}
		else{
			cout<<2<<' '<<piles[1]-piles[0]<<endl;
			piles[1]=piles[0];
		}
		if(piles[0]||piles[1]){
			cout.flush();
			cin>>direction>>num;
			piles[direction-1]-=num;		
		}
	}
	return 0;
}
