#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
ifstream fin("ex.out");
int ans[1000005];
int main()
{
	freopen("city.out","r",stdin);
	int t=1,temp;
	while(scanf("%d",&ans[t++]));
	for(int i=1;i<t;i++){
		fin>>temp;
		if(temp!=ans[i]){
			cout<<"错误！ 在第"<<i<<"个数据读取到，期望"<<temp<<"得到"<<ans[i]<<endl;
			system("PAUSE");
			return 0;
		}
	}
	cout<<"所有数据正确！"<<endl;
	system("PAUSE");
	return 0;
}
