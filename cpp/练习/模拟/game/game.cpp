#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("game.in");
ofstream fout("game.out");
int main()
{
	string temp,jxq="jxq",ztz="ztz";
	int s_jxq=0,s_ztz=0;
	bool sp=false;
	while(1){
//		cin>>temp;
		fin>>temp;
		if(temp==jxq){
			s_jxq++;
		}
		if(temp==ztz){
			s_ztz++;
		}
		if(s_jxq==10&&s_ztz==10){
			sp=true;
		}
		if(sp){
			if(s_jxq==13){
//				cout<<s_ztz<<':'<<s_jxq<<endl<<jxq;
				fout<<s_ztz<<':'<<s_jxq<<endl<<jxq;
				return 0;
			}
			if(s_ztz==13){
//				cout<<s_ztz<<':'<<s_jxq<<endl<<ztz;
				fout<<s_ztz<<':'<<s_jxq<<endl<<ztz;
				return 0;
			}
		}
		else{
			if(s_jxq==11){
//				cout<<s_ztz<<':'<<s_jxq<<endl<<jxq;
				fout<<s_ztz<<':'<<s_jxq<<endl<<jxq;
				return 0;
			}
			if(s_ztz==11){
//				cout<<s_ztz<<':'<<s_jxq<<endl<<ztz;
				fout<<s_ztz<<':'<<s_jxq<<endl<<ztz;
				return 0;
			}
		}
	}
	return 0;
}
