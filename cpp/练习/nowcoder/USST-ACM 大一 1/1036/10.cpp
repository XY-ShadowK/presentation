#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
long long score[5];
int main()
{
	cin>>score[0]>>score[1]>>score[2];
	sort(score,score+3);
	cout<<score[2];
	return 0;
}
