#include <iostream>
#include "tree"
using namespace std;
int main()
{
	BiTree<char> a;
	a.InOrderTraverse(a.GetRoot());
	return 0;
}
