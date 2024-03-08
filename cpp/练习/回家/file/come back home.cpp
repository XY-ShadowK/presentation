#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int map[52][52],p,minn=9999999;
int Min()
{
	int i,h=0;
	for(i=26;i<51;i++){
		if(minn>map[i][51]){
			minn=map[i][51];
			h=i;
		}
	}
	return h;
}
char i_char(int a)
{
	if(a>=0&&a<=25){
		return (char)a+'a';
	}
	if(a>=26&&a<=51){
		return (char)a+'A'-26;
	}
}
int ch_int(char a)
{
	if(a>='a'&&a<='z'){
		return (int)a-'a';
	}
	if(a>='A'&&a<='Z'){
		return (int)a-'A'+26;
	}
}
void floyd()
{
	int i,j,k;
	for(i=0;i<52;i++){
		for(j=0;j<52;j++){
			for(k=0;k<52;k++){
				if(map[i][k]+map[k][j]<map[i][j]){
					map[i][j]=map[i][k]+map[k][j];
				}
			}
		}
	}
}
int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	cin>>p;
	int i,j,temp1,temp2;
	char x,y;
	for(i=0;i<52;i++){
		for(j=0;j<52;j++){
			map[i][j]=99999999;
			if(i==j){
				map[i][j]=0;
			}
		}
	}
	for(i=0;i<p;i++){
		cin>>x>>y;
		temp1=ch_int(x);
		temp2=ch_int(y);
		cin>>map[temp1][temp2];
		map[temp2][temp1]=map[temp1][temp2];
	}
	floyd();
	char ans=i_char(Min());
	cout<<ans<<' '<<minn<<endl;
	/*
	cout<<"  ";
	for(i=0;i<52;i++){
		cout<<i_char(i)<<' ';
	}
	cout<<endl;
	for(i=0;i<52;i++){
		cout<<i_char(i)<<' ';
		for(j=0;j<52;j++){
			if(map[i][j]==99999999){
				cout<<" "<<' ';
			}
			else{
				cout<<map[i][j]<<' ';
			}
		}
		cout<<endl;
	}*/
	return 0;
} 
