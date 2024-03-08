#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long score[5],m[5];
int main()
{
	cin>>score[0]>>score[1]>>score[2]>>score[3];
	m[0]=abs(score[3]+score[2]-score[1]-score[0]);
	m[1]=abs(score[3]+score[1]-score[2]-score[0]);
	m[2]=abs(score[3]+score[0]-score[2]-score[1]);
	sort(m,m+3);
	cout<<m[0];
	return 0;
}
