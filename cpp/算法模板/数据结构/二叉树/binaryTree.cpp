#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
template<typename T> class binaryTree{
	private:
		binaryTree<T>* leftChild;
		binaryTree<T>* rightChild;
		int number;
		T data;
	public:
		binaryTree<T>() : leftChild(NULL),rightChild(NULL),number(-1),data((T)-1){}
		binaryTree<T>(binaryTree* l,binaryTree* r) : leftChild(l),rightChild(r),number(-1),data((T)-1){}
		binaryTree<T>(binaryTree* l,binaryTree* r,int num,T t) : leftChild(l),rightChild(r),number(num),data(t){}
		~binaryTree()
		{
			if(this->leftChild!=NULL)
				delete this->leftChild;
			if(this->rightChild!=NULL)
				delete this->rightChild;
			number=-1;
			data=(T)-1;
			leftChild=NULL;
			rightChild=NULL;
		}
		int getNumber()
		{
			return this->number;
		}
		T getData()
		{
			return this->data;
		}
		binaryTree<T>* getLeft()
		{
			return this->leftChild;
		}
		binaryTree<T>* getRight()
		{
			return this->rightChild;
		}
		void setNumber(int num)
		{
			this->number=num;
			return;
		}
		void setData(T t)
		{
			this->data=t;
			return;
		}
		void setLeft(binaryTree* l)
		{
			this->leftChild=l;
			return;
		}
		void setRight(binaryTree* r)
		{
			this->rightChild=r;
			return;
		}
		binaryTree<T>* preSearch(int num)
		{
			if(this->number==num)return this;
			if(this->number>num)return NULL;
			binaryTree<T>* result=NULL;
			if(this->leftChild!=NULL)result=this->leftChild->preSearch(num);
			if(this->rightChild!=NULL&&result==NULL)return this->rightChild->preSearch(num);
			return result;
		}
		binaryTree<T>* inSearch(int num)
		{
			binaryTree<T>* result=NULL;
			if(this->leftChild!=NULL)result=this->leftChild->inSearch(num);
			if(result!=NULL)return result;
			if(this->number==num)return this;
			if(this->number>num)return NULL;
			if(this->rightChild!=NULL)return this->rightChild->inSearch(num);
			return NULL;
		}
		binaryTree<T>* postSearch(int num)
		{
			binaryTree<T>* result=NULL;
			if(this->leftChild!=NULL)result=this->leftChild->postSearch(num);
			if(result!=NULL)return result;
			if(this->rightChild!=NULL)result=this->rightChild->postSearch(num);
			if(this->number==num)return this;
			return result;
		}
		void preTraversal()
		{
			cout<<"number="<<this->getNumber()<<",data="<<this->getData()<<endl;
			if(this->getLeft()!=NULL)this->leftChild->preTraversal();
			if(this->getRight()!=NULL)this->rightChild->preTraversal();
			return;
		}
		void inTraversal()
		{
			if(this->getLeft()!=NULL)this->leftChild->inTraversal();
			cout<<"number="<<this->getNumber()<<",data="<<this->getData()<<endl;
			if(this->getRight()!=NULL)this->rightChild->inTraversal();
			return;
		}
		void postTraversal()
		{
			if(this->getLeft()!=NULL)this->leftChild->postTraversal();
			if(this->getRight()!=NULL)this->rightChild->postTraversal();
			cout<<"number="<<this->getNumber()<<",data="<<this->getData()<<endl;
			return;
		}
};
template<typename T> binaryTree<T>* perfectBinaryTreeBuild(int num,const int& n,const T* data)
{
	if(n==0||sizeof(data)/sizeof(T)==0)return NULL;
	binaryTree<T>* root=new binaryTree<T>(NULL,NULL,num+1,data[num]);
	int leftNum=2*num+1,rightNum=2*num+2;
	if(leftNum<=n-1)root->setLeft(perfectBinaryTreeBuild<T>(leftNum,n,data));
	if(rightNum<=n-1)root->setRight(perfectBinaryTreeBuild<T>(rightNum,n,data));
	return root;
}
template<typename T> inline void printResult(binaryTree<T>* node)
{
	binaryTree<T>* l=node->getLeft();
	binaryTree<T>* r=node->getRight();
	cout<<"�ڵ�����="<<node->getData();
	if(l!=NULL)cout<<";���ӱ��="<<l->getNumber()<<",����="<<l->getData();
	else cout<<";�˽ڵ�������";
	if(r!=NULL)cout<<";�Һ��ӱ��="<<r->getNumber()<<",����="<<r->getData()<<endl;
	else cout<<";�˽ڵ����Һ���"<<endl;
	return;
}
int main()
{
	binaryTree<int> *intBinaryTree,*treeNode,*l,*r;
	int size,*data,temp=1;
	cin>>size;
	data=new int[size];
	for(int i=0;i<size;i++)
		cin>>data[i];
	intBinaryTree=perfectBinaryTreeBuild<int>(0,size,data);
	cout<<"������ȫ�����������������:"<<endl;
	cout<<"�������:"<<endl;
	intBinaryTree->preTraversal();
	cout<<"�������:"<<endl;
	intBinaryTree->inTraversal();
	cout<<"�������:"<<endl;
	intBinaryTree->postTraversal();
	cout<<"������Ҫ���ҵĽڵ�"<<endl;
	while(temp!=0){
		cin>>temp;
		if(temp<0||temp>size){
			cout<<"�ڵ㲻����!"<<endl;
			continue;
		}
		treeNode=intBinaryTree->preSearch(temp);
		cout<<"������ҽ��Ϊ: "<<endl;
		printResult<int>(treeNode);
		treeNode=intBinaryTree->inSearch(temp);
		cout<<"������ҽ��Ϊ: "<<endl;
		printResult<int>(treeNode);
		treeNode=intBinaryTree->postSearch(temp);
		cout<<"������ҽ��Ϊ: "<<endl;
		printResult<int>(treeNode);
	}
	return 0;
}
