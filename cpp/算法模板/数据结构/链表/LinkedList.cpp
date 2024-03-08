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
			//����delete next ���������������һ����������к����ڵ� 
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
			//��ʹ��ѵ ǧ��Ҫ��ջ���ã������new delete�����ڴ� С�������������µ������������� 
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
	cout<<"������������"<<endl;
	cout<<"1.����0��һ����������������Ԫ����ӵ�����ĩβ"<<endl;
	cout<<"2.����1�����������ֱ����λ�ú�Ԫ��ֵ����������������Ķ�Ӧλ��"<<endl;
	cout<<"3.����2��һ������λ�õ�������ɾ�������Ӧλ�õ�Ԫ��"<<endl;
	cout<<"4.����3��һ������λ�õ���������ѯ�����Ӧλ�õ�Ԫ��ֵ"<<endl;
	cout<<"ps:1Ϊ������ʼλ�ã���������1λ�ô���Ԫ�أ�ÿ�β�������ӡ��ǰ����"<<endl;
	while(true){
		cin>>control;
		switch(control){
			case 0 : {
				cin>>temp;
				intLinkedList.add(temp);
				cout<<"��ǰ����Ϊ��";
				print<int>(intLinkedList);
				break;
			}
			case 1 : {
				cin>>t>>temp;
				intLinkedList.insert(t,temp);
				cout<<"��ǰ����Ϊ��";
				print<int>(intLinkedList);
				break;
			}
			case 2 : {
				cin>>t;
				intLinkedList.erase(t);
				cout<<"��ǰ����Ϊ��";
				print<int>(intLinkedList);
				break;
			}
			case 3 : {
				cin>>t;
				cout<<"��ѯ��Ԫ��ֵΪ��"<<intLinkedList.findValue(t)<<endl;
				cout<<"��ǰ����Ϊ��";
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
