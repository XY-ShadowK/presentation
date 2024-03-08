#include <iostream>
#include <queue>
using namespace std;
priority_queue <int,vector<int>,greater<int> > t;
int main()
{
	int x,temp,n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		switch(temp){
			case 1 : {
				cin>>x;
				t.push(x);
				break;
			}
			case 2 : {
				cout<<t.top()<<endl;
				break;
			}
			case 3 : {
				t.pop();
				break;
			}
		}
	}
	return 0;
}
