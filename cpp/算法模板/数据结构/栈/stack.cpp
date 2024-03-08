#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
template<typename T> class fElement {
	private:
		T* element;
		fElement* front;
	public:
		fElement(T* t,fElement* f) : element(t),front(f){}
		fElement(T t,fElement* f) : element(new T(t)),front(f){}
		fElement(T t) : element(new T(t)),front(NULL){}
		fElement() : element (NULL), front (NULL){}
		~fElement()
		{
			delete this->element;
			this->element=NULL;
			this->front=NULL;
		}
		void destroy()
		{
			if(this->front!=NULL)this->front->destroy();
			delete this->element;
			delete this->front;
			this->element=NULL;
			this->front=NULL;
			return;
		}
		T getValue()
		{
			return *(this->element);
		}
		fElement* getFront()
		{
			return this->front;
		}
};
template<typename T> class stack{
	private:
		fElement<T>* base;
		fElement<T>* top;
		int _size;
	public:
		stack(T t) : base(new fElement<T>),top(new fElement<T>(t,base)),_size(1){}
		stack() : base(new fElement<T>),top(base),_size(0){}
		~stack()
		{
			this->top->destroy();
			this->_size=0;
			this->top-=NULL;
			this->base=NULL;
		}
		void push(T t)
		{
			this->top=new fElement<T>(t,this->top);
			this->_size++;
			return;
		}
		void pop ()
		{
			fElement<T>*now=this->top;
			this->top=now->getFront();
			this->_size--;
			delete now;
			now=NULL;
			return;
		}
		T getTop()
		{
			return this->top->getValue();
		}
		int size()
		{
			return this->_size;
		}
		bool empty()
		{
			return this->_size==0&&this->top==this->base;
		}
};
bool pd(string str)
{
	stack<char> st;
	int length=str.size();
	for(int i=0;i<length;i++)
		st.push(str[i]);
	for(int i=0;i<length;st.pop(),i++)
		if(st.getTop()!=str[i])
			return false;
	return true;
}
int main()
{
	string str;
	cout<<"请输入一个字符串以检验其是否为回文:"<<endl;
	cin>>str;
	cout<<(pd(str)?"是回文!":"不是回文!")<<endl;
	system("PAUSE");
	return 0;
}


