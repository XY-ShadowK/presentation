#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
template<typename T> class LinkedElement{
	private:
		T* element;
		LinkedElement* next;
	protected:
		void destroyLink()
		{
			if(this->next!=NULL)this->next->destroyLink();
			delete this->next;
			delete this->element;
			this->next=NULL;
			this->element=NULL;
			return;
		}
	public:
		LinkedElement(T* a,LinkedElement* nextLink) : element(a),next(nextLink){}
		LinkedElement(T a,LinkedElement* nextLink) : LinkedElement(new T(a),nextLink){}
		LinkedElement(T a) : LinkedElement(new T(a),NULL){}
		LinkedElement() : LinkedElement((T*)NULL,NULL){}
		~LinkedElement()
		{
			delete this->element;
			this->element=NULL;
			this->next=NULL;
			//不能delete next 否则会由析构函数一层层销毁所有后续节点 
		}
		void rewrite(T a)
		{
			*(this->element)=a;
			return;
		}
		void link(LinkedElement* nextLink)
		{
			this->next=nextLink;
			return;
		}
		LinkedElement* getNext()
		{
			return this->next;
		}
		T getElement()
		{
			return *(this->element);
		}
};
template<typename T> class LinkedList : protected LinkedElement<T> {
	private:
		int num;
	protected:
		LinkedElement<T>* getElement(int n)
		{
			LinkedElement<T>* element=this;
			for(int i=0;i<n;i++)
				element=element->getNext();
			return element;
		}
	public:
		LinkedList() : LinkedElement<T>(),num(0){}
		~LinkedList()
		{
			this->destroyLink();
			this->num=0;
		}
		int add(T a)
		{
			LinkedElement<T>* last=this->getElement(this->num);
			last->link(new LinkedElement<T>(a));
			return ++(this->num);
		}
		int insert(int n,T a)
		{
			if(n<=0||n>this->num)
				return -1;
			LinkedElement<T>* precursor=this->getElement(n-1);
			LinkedElement<T>* successor=precursor->getNext();
			precursor->link(new LinkedElement<T>(a,successor));
			return ++(this->num);
		}
		int erase(int n)
		{
			if(n<=0||n>this->num)
				return -1;
			LinkedElement<T>* precursor=this->getElement(n-1);
			LinkedElement<T>* self=precursor->getNext();
			precursor->link(self->getNext());
			delete self;
			self=NULL;
			return --(this->num);
		}
		LinkedElement<T>* findElement(int n)
		{
			if(n<0||n>this->num)
				return NULL;
			return this->getElement(n);
			//惨痛教训 千万不要堆栈混用，如果以new delete操作内存 小心匿名变量导致的析构函数问题 
		}
		T findValue(int n)
		{
			if(n==0)
				return T();
			return this->findElement(n)->getElement();
		}
		int getNum()
		{
			return this->num;
		}
};
template<typename T> void print(LinkedList<T>& ll)
{
	LinkedElement<T>* element=ll.findElement(0);
	int length=ll.getNum();
	for(int i=0;i<length;i++){
		element=element->getNext();
		cout<<element->getElement()<<" ";
	}
	cout<<endl;
	return;
}
int main()
{
	LinkedList<int> intLinkedList;
	int control,temp,t;
	cout<<"测试整形链表："<<endl;
	cout<<"1.输入0和一个整数来将此整形元素添加到链表末尾"<<endl;
	cout<<"2.输入1和两个整数分别代表位置和元素值来将它插入至链表的对应位置"<<endl;
	cout<<"3.输入2和一个代表位置的整数来删除链表对应位置的元素"<<endl;
	cout<<"4.输入3和一个代表位置的整数来查询链表对应位置的元素值"<<endl;
	cout<<"ps:1为链表起始位置，即空链表1位置处无元素；每次操作后会打印当前链表"<<endl;
	while(true){
		cin>>control;
		switch(control){
			case 0 : {
				cin>>temp;
				intLinkedList.add(temp);
				cout<<"当前链表为：";
				print<int>(intLinkedList);
				break;
			}
			case 1 : {
				cin>>t>>temp;
				intLinkedList.insert(t,temp);
				cout<<"当前链表为：";
				print<int>(intLinkedList);
				break;
			}
			case 2 : {
				cin>>t;
				intLinkedList.erase(t);
				cout<<"当前链表为：";
				print<int>(intLinkedList);
				break;
			}
			case 3 : {
				cin>>t;
				cout<<"查询的元素值为："<<intLinkedList.findValue(t)<<endl;
				cout<<"当前链表为：";
				print<int>(intLinkedList);
				break;
			}
			default : {
				return 0;
			}
		}
	}
	return 0;
}
