#include <iostream>
using namespace std;
unsigned long long memory[1500002];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n/2;i++){
		memory[i]=1;
		for(int j=1;j<=i/2;j++){
			memory[i]+=memory[j];
		}
		memory[n]+=memory[i];
	}
	cout<<memory[n]+1;
	return 0;
}
