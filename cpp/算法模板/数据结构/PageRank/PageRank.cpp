#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdarg>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <utility>
#include <fstream> 
using namespace std;
using LL=long long;
ifstream fin("directedgraph.txt");
template<typename T> class matrix{
	private:
		T* data;
		T multiple;
		int row;
		int column;
	public:
		matrix<T>() : data(NULL),multiple((T)1),row(0),column(0){}
		matrix<T>(int n,int m) : data(new T[n*m]),multiple((T)1),row(n),column(m)
		{
			this->setDataZero();
		}
		matrix<T>(int n,int m,T* dat) : data(new T[n*m]),multiple((T)1),row(n),column(m)
		{
			this->setData(dat);
		}
		~matrix()
		{
			this->purge();
		}
		inline void purge()
		{
			delete this->data;
			this->data=NULL;
			this->row=0;
			this->column=0;
			this->multiple=(T)1;
			return;
		}
/*		void release()
		{
			delete this->data;
			this->data=NULL;
			delete this;
			return;
		}*/
		inline void reset(int n,int m)
		{
			delete this->data;
			this->data=new T[n*m];
			this->row=n;
			this->column=m;
			this->multiple=(T)1;
			return;
		}
		inline void reset(int n,int m,T* dat,T mut)
		{
			this->reset(n,m);
			this->setData(dat);
			this->multiple=mut;
			return;
		}
		inline void setData(T* dat)
		{
			memcpy(this->data,dat,sizeof(T)*this->row*this->column);
			return;
		}
		inline void setData(int n,int m,T elem)
		{
			this->data[this->getCoordinate(n,m)]=elem;
			return;
		}
		inline void setDataZero()
		{
			memset(this->data,(T)0,sizeof(T)*this->row*this->column);
			return;
		}
		inline int getCoordinate(const int& n,const int& m) const
		{
			return n*this->column+m;
		}
		void copy(const matrix<T>* m1)
		{
			this->reset(m1->row,m1->column,m1->data,m1->multiple);
			return;
		}
		inline T multiplyMut(T mut)
		{
			this->multiple=this->multiple*mut;
			return this->multiple;
		}
		inline T multiplyMut(int num,T mut,...)
		//T mut防止单int参数时与同名函数混淆 
		{
			va_list valist;
			va_start(valist,mut);
			this->multiple=this->multiple*mut;
			for(int i=1;i<num;i++)this->multiple=this->multiple*va_arg(valist,T);
			va_end(valist);
			return this->multiple;
		}
		bool multiply(const matrix<T>* m1,const matrix<T>* m2)
		{
			if(m1->column!=m2->row)return false;
			int n=m1->row,m=m2->column,p=m2->row;
			this->reset(n,m);
			this->setDataZero();
			for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<p;k++)
				this->data[this->getCoordinate(i,j)]+=m1->data[m1->getCoordinate(i,k)]*m2->data[m2->getCoordinate(k,j)];
			this->multiplyMut(2,m1->multiple,m2->multiple);
			return true;
		}
		bool add(const matrix<T>* m1)
		{
			if(m1->row!=this->row||m1->column!=this->column)return false;
			int n=m1->row,m=m1->column;
			for(int i=0;i<n;i++)for(int j=0;j<m;j++)
				this->data[this->getCoordinate(i,j)]=this->data[this->getCoordinate(i,j)]*this->multiple+m1->data[m1->getCoordinate(i,j)]*m1->multiple;
			this->multiple=(T)1;
			return true;
		}
		bool checkSimilar(const T& threshold,const matrix<double>* m1) const
		{
			if(m1->row!=this->row||m1->column!=this->column)return false;
			int n=m1->row,m=m1->column;
			for(int i=0;i<n;i++)for(int j=0;j<m;j++)
				if(abs(this->data[this->getCoordinate(i,j)]-m1->data[m1->getCoordinate(i,j)])>threshold)
					return false;
			return true;
		}
		void printData(const int& n,const int& m) const
		{
			cout<<n<<' '<<m<<' '<<this->data[this->getCoordinate(n,m)]<<endl;
			return;
		}
		void printData() const
		{
			cout<<"matrix multiple: "<<this->multiple<<endl;
			for(int i=0;i<this->row;i++){
				for(int j=0;j<this->column;j++)
					cout<<this->data[this->getCoordinate(i,j)]<<' ';
				cout<<endl;
			}
		}
};
void matrixTest()
{
	matrix<int>* m1=new matrix<int>(2,3);
	matrix<int>* m2=new matrix<int>(3,2);
	int dt[]={1,2,3,4,5,6};
	m1->setData(dt);
	m2->setData(dt);
	m1->printData();
	cout<<endl;
	m2->printData();
	cout<<endl;
	m1->multiplyMut(2);
	m2->multiplyMut(3);
	m1->printData();
	cout<<endl;
	m2->printData();
	cout<<endl;
	matrix<int>* m0=new matrix<int>();
	m0->multiply(m1,m2);
	m0->printData();
	m1->copy(m0);
	cout<<endl;
	m1->printData();
}
template<typename T> bool cmp(pair<T,T> p1,pair<T,T> p2)
{
	return p1.first<p2.first;
}
template<typename T> matrix<double>* buildTransferMatrix(int num)
{
	vector<pair<T,T>> edge;
	vector<pair<T,double>> edgeNode;
	int numEdge=0,numNode=0;
	T temp1,temp2;
	while(!fin.eof()){
		fin>>temp1>>temp2;
		edge.push_back(make_pair(temp1,temp2));
		if(edgeNode.empty()||temp1!=(*(edgeNode.end()-1)).first)
			edgeNode.push_back(make_pair(temp1,1.00));
		else (*(edgeNode.end()-1)).second+=1.00;
	}
//	for(int i=0;i<edge.size();i++)cout<<edge[i].first<<' '<<edge[i].second<<endl;
	numEdge=edge.size();
	numNode=edgeNode.size();
//	cout<<"numEdge= "<<numEdge<<" numNode= "<<numNode<<endl;
	matrix<double>* m=new matrix<double>(num,num);
	typename vector<pair<T,T>>::iterator it=edge.begin();
	for(int i=0;i<numNode;i++){
//		cout<<"node= "<<edgeNode[i].first<<",num of edges= "<<edgeNode[i].second<<endl<<endl;
		for(int j=0;j<edgeNode[i].second;j++){
//			cout<<"i= "<<i<<",j= "<<j<<endl;
			m->setData((*it).second-(T)1,edgeNode[i].first-(T)1,1.00/edgeNode[i].second);
//			m->printData((*it).second-(T)1,edgeNode[i].first-(T)1);
			it++;
		}
	}
	return m;
}
matrix<double>* buildInitialPageRank(int num)
//设置初始向量R0为各分量均为1/num的列向量 
{
	matrix<double>* initialPageRank=new matrix<double>(num,1);
	double n=num;
	for(int i=0;i<num;i++)initialPageRank->setData(i,0,1.00/n);
	return initialPageRank;
}
matrix<double>* buildToolVector(int num,double d)
//将导入平滑项转移矩阵而造成的迭代式中第二项设置
{
	matrix<double>* toolVector=new matrix<double>(num,1);
	double elem=num;
	elem=(1.00-d)/elem;
	for(int i=0;i<num;i++)toolVector->setData(i,0,elem);
	return toolVector;
}
int cnt=0;
matrix<double>* getPageRank(const double& d,const double& threshold,const matrix<double>* tM,const matrix<double>* r0,const matrix<double>* tail)
{
	matrix<double>* rT=new matrix<double>();
	matrix<double>* rTNext=new matrix<double>();
	matrix<double>* temp=new matrix<double>();
	bool stop=false;
	rT->copy(r0);
	rTNext->copy(r0);
	while(!stop){
		temp->multiply(tM,rT);
		temp->multiplyMut(d);
		temp->add(tail);
		rTNext->copy(temp);
		if(rTNext->checkSimilar(threshold,rT))stop=true;
		rT->copy(rTNext);
		cnt++;
	}
	return rT;
}
int main()
{
	double damping=0.85;
	double threshold=1e-13;
	int numNode=16;
	//预设共16个节点 
	matrix<double>* transferMatrix=buildTransferMatrix<int>(numNode);
	matrix<double>* initialPageRank=buildInitialPageRank(numNode);
	matrix<double>* toolVector=buildToolVector(numNode,damping);
	matrix<double>* pageRank=getPageRank(damping,threshold,transferMatrix,initialPageRank,toolVector);
	cout<<"共迭代 "<<cnt<<" 次,所得pageRank如下向量(以矩阵形式打印)"<<endl;
	cout<<setiosflags(ios::left);
	cout.precision(15);
	pageRank->printData();
	return 0;
}
