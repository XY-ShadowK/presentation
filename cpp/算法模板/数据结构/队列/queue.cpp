#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
template<typename T> class nElement{
	private:
		T* element;
		nElement* next;
	public:
		nElement(T* t,nElement* n) : element(t),next(n){}
		nElement(T t,nElement* n) : element (new T(t)),next(n){}
		nElement(T t) : element(new T(t)),next(NULL){}
		nElement() : element(NULL),next (NULL){}
		~nElement()
		{
			delete this->element;
			this->element=NULL;
			this->next=NULL;
		}
		void destroy()
		{
			if(this->next!=NULL)this->next->destroy();
			delete this->element;
			delete this->next;
			this->element=NULL;
			this->next=NULL;
			return;
		}
		T getValue()
		{
			return *(this->element);
		}
		bool isNull()
		{
			return this->element==NULL;
		}
		nElement* getNext()
		{
			return this->next;
		}
		void setNext(nElement* n)
		{
			this->next=n;
			return;
		}
};
template<typename T> class queue{
	private:
		nElement<T>* head;
		nElement<T>* end;
		int _size;
	public:
		queue(T t): head(new nElement<T>(t)),end(new nElement<T>),_size(1)
		{
			this->head->setNext(this->end);
		}
		queue() : head(new nElement<T>),end(head),_size (0){}
		~queue()
		{
			this->head->destroy();
			this->_size=0;
			this->head=NULL;
			this->end=NULL;
			return;
		}
		void push(T t)
		{
			this->end->setNext(new nElement<T>(t));
			this->end=this->end->getNext();
			this->_size++;
			return;
		}
		void pop()
		{
			nElement<T>* front=this->head;
			this->head=this->head->getNext();
			this->_size--;
			delete front;
			front=NULL;
			return;
		}
		T front()
		{
			return this->head->getNext()->getValue();
		}
		T back()
		{
			return this->end->getValue();
		}
		int size()
		{
			return this->_size;
		}
		bool empty()
		{
			return this-> size&&this->head==this->end;
		}
		void print()
		{
			nElement<T>* now=this->head->getNext();
			while(now!=this->end){
				cout<<now->getValue()<<" ";
				now=now->getNext();
			}
			cout<<this->end->getValue()<<" "<<endl;
			return;
		}
};
void func()
{
	queue<int> q;
	int temp;
	q.push(11);
	q.push(41);
	q.push(90);
	q.push(12);
	q.push(16);
	q.push(1);
	q.push(81);
	cout<<"队列内初始成员依次(由队头至队尾)为: 11 41 90 12 16 1 81"<<endl;
	cout<<"请输入三个数入队:"<<endl;
	for(int i=0;i<3;i++){
		cin>>temp;
		q.push(temp);
	}
	cout<<"队列内目前成员依次(由队头至队尾)为: ";
	q.print();
	cout<<"接下来执行出队四次"<<endl;
	for(int i=0;i<4;i++)
		q.pop();
	cout<<"队列内目前成员依次(由队头至队尾)为: ";
	q.print();
	return;
}
int main()
{
	func();
	system("PAUSE");
	return 0;
}

