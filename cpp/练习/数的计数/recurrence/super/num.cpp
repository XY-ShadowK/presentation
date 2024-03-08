#include <iostream>
using namespace std;
int memory[1500002];
int main()
{
	int n;
	cin>>n;
	memory[1]=1;
	for(int i=2;i<=n/2;i++)
	{
		if(i%2==0)memory[i]=memory[i-1]+memory[i/2];
		else memory[i]=memory[i-1];
		cout<<memory[i]<<"   ";
	}
	for(int i=1;i<=n/2;i++)memory[n]+=memory[i];
	cout<<memory[n]+1;
	return 0;
}
