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
			cout<<"���� �ڵ�"<<i<<"�����ݶ�ȡ��������"<<temp<<"�õ�"<<ans[i]<<endl;
			system("PAUSE");
			return 0;
		}
	}
	cout<<"����������ȷ��"<<endl;
	system("PAUSE");
	return 0;
}
