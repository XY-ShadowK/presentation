#include <iostream>
#include <algorithm>
using namespace std;
class Chains{
	private:
		int a[500];
		Chains();
		~Chains();
	public:
		typedef std::string::size_type USL;
		typedef std::string::npos ERROR;
		USL find(int num);
		USL size();
		bool copy(Chains & T);
		USL add()
};
Chains::USL Chains::find(int num)
{
	USL i=0;
	for(i=0;a[i]!=0;i++){
		if(a[i]==num)return i;
	}
	return ERROR;
}
Chains::USL Chains::size()
{
	USL i=0;
	for(i=0;a[i]!=0;i++)return i;
}
Chains::Chains()
{
	a[0]=1;
}
int m=10000,n;
Chains A;
void dfs(int num){
	if(A.find(n)!=Chains::ERROR){
		m=min(m,num+1);
		return;
	}
	int i;
	for(i=n-1;i>=1;i--){
		dfs()
	}
}
int main()
{
	cin>>n;
	dfs(0);
	return 0;
}
