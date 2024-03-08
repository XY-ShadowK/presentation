#include <iostream>
#include <algorithm>
using namespace std;
typedef class cQueue
{
	public:
		long long minn;
		long long maxn;
		int start;
		int end;
		cQueue()
		{
			minn=0;
			maxn=0;
			start=0;
			end=0;
		}
		~cQueue(){}
		bool operator<(const cQueue &q)
		{
			return maxn<=q.minn;
		}
		bool operator>(const cQueue &q)
		{
			return minn>q.maxn;
		}
		int eat(const cQueue &q)
		{
			minn=minn<q.minn?minn:q.minn;
			maxn=maxn>q.maxn?maxn:q.maxn;
			end=q.end;
			return end;
		}
		void open(long long a,long long b,int s,int e)
		{
			minn=a;
			maxn=b;
			start=s;
			end=e;
			return;
		}
}cqueue;
int n,ans=1,direction=0;
cqueue ai[1000005];
long long temp;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		ai[i].open(temp,temp,i,i);
	}
	for(int i=1;i<n;i++){
		if(ai[direction]>ai[i])ai[direction].eat(ai[i]);
		else{
			ans++;
			direction=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
