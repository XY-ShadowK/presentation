#include <iostream>
#include <set>
#include <string>
using namespace std;
set <string> t;
int n;
int main()
{
	cin>>n;
	string temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		t.insert(temp);
	}
	cout<<t.size()<<endl;
	return 0;
}
