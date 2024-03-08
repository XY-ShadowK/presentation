#include<bits/stdc++.h>
using namespace std;
typedef struct Bnode{
	char data;
	Bnode *lch,*rch;
}Bnode,*Btree;
void CreatBtree(Btree &T)
{
	char ch;
	cin>>ch;
	if(ch=='.') T=NULL;
	else{
		T=(Btree)malloc(sizeof(Bnode));
		if(!T) exit(OVERFLOW);
		T->data=ch;
		CreatBtree(T->lch);
		CreatBtree(T->rch);
	}
}
void PreOrderTraverse(Btree T)
{
	if(T==NULL) return ;
	cout<<T->data;
	PreOrderTraverse(T->lch);
	PreOrderTraverse(T->rch);
}
void InOrderTraverse(Btree T)
{
	if(T==NULL) return ;
	InOrderTraverse(T->lch);
	cout<<T->data;
	InOrderTraverse(T->rch);
}
void PostOrderTraverse(Btree T)
{
	if(T==NULL) return ;
	PostOrderTraverse(T->lch);
	PostOrderTraverse(T->rch);
	cout<<T->data;
}
int main()
{
	Btree root;
	CreatBtree(root);
/*	PreOrderTraverse(root);
	cout<<endl;*/
	InOrderTraverse(root);
	cout<<endl;
	PostOrderTraverse(root);
	cout<<endl;
}
