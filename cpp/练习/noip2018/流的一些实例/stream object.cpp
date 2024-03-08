#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
template <class TA,class TB>
void change(const TA& ta,const TB& tb)
{
	std::stringstream stream;
	stream<<ta;
	stream>>tb;
	stream.clear();
}
int main()
{
	
	return 0;
}
