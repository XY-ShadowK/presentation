#include <iostream>
#include <string>
using namespace std;
typedef struct tID{
	char type;
	union{
		string id;
		long long qq;
	};
}ID;
ID a[10001];
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i].type;
		
	}
	return 0;
}
