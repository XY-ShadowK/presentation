#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;

template<typename T>
class intervalTime{
    static_assert( is_same_v<T,chrono::seconds> || is_same_v<T,chrono::milliseconds> || is_same_v<T,chrono::microseconds> || is_same_v<T,chrono::nanoseconds>,
    "Type for intervalTime should be one of seconds,milliseconds,microseconds,nanoseconds in std::chrono" );
    private:
        chrono::steady_clock::time_point start;
        chrono::steady_clock::time_point end;
        T dur;
    public:
        void updateStart();
        void updateEnd();
        T getDuration();
};

class randomInt{
    private:
        random_device seed;
        ranlux48 engine;
        uniform_int_distribution<> distrib;
    public:
        randomInt();
        void setDistrib(int,int);
        int getRandom();
};

float quickRSqrtStep1(float );
float quickRSqrtStep2(float );
void quickReverseSqrtTest(int);

ofstream fout("testOutPut.txt");
intervalTime<chrono::nanoseconds> iT;

int main()
{
    if(sizeof(int) == 4){
        cout<<"on 64 bit"<<endl;
        fout<<"on 64 bit"<<endl;
    }
    else{
        cout<<"not on 64 bit"<<endl;
        fout<<"not on 64 bit"<<endl;
    }
    randomInt rI;
    int times,n;
    rI.setDistrib(0,100);
    // cin>>times;
    // for(int i=0;i<times;i++){
    //     cout<<"test "<<i<<"\tn="<<n<<endl;
    //     float ans[4];
    //     long long t[4];
    //     n = (float) rI.getRandom();
    //     // 测试快算-单步牛顿法
    //     iT.updateStart();
    //     // cout<<quickRSqrtStep1(n)<<"\t";  // 0.70693 when n==2
    //     ans[0] = quickRSqrtStep1(n);  // 0.70693 when n==2
    //     iT.updateEnd();
    //     // cout<<"\t"<<iT.getDuration().count()<<endl;
    //     t[0] = iT.getDuration().count();
    //     // 测试快算-二次牛顿法
    //     iT.updateStart();
    //     // cout<<quickRSqrtStep2(n)<<"\t";  // 0.707107 when n==2
    //     ans[1] = quickRSqrtStep2(n);  // 0.707107 when n==2
    //     iT.updateEnd();
    //     // cout<<"\t"<<iT.getDuration().count()<<endl;
    //     t[1] = iT.getDuration().count();
    //     // 测试化算
    //     iT.updateStart();
    //     // cout<<(sqrt(n)/n)<<"\t";  // 0.707107 when n==2
    //     ans[2] = (sqrt(n)/n);  // 0.707107 when n==2
    //     iT.updateEnd();
    //     // cout<<"\t"<<iT.getDuration().count()<<endl;
    //     t[2] = iT.getDuration().count();
    //     // 测试直算
    //     iT.updateStart();
    //     // cout<<(1/sqrt(n))<<"\t";  // 0.707107 when n==2
    //     ans[3] = (1/sqrt(n));  // 0.707107 when n==2
    //     iT.updateEnd();
    //     // cout<<"\t"<<iT.getDuration().count()<<endl;
    //     t[3] = iT.getDuration().count();
    //     for(int j=0;j<4;j++)
    //         cout<<ans[j]<<' '<<t[j]<<endl;
    //     cout<<endl;
    // }
    cin>>times;
    for(int i=0;i<times;i++){
        n = (float) rI.getRandom();
        cout<<"test "<<i<<"\tn="<<n<<endl;
        fout<<"test "<<i<<"\tn="<<n<<endl;
        quickReverseSqrtTest(n);
    }
    return 0;
}

template<typename T>
void intervalTime<T>::updateStart()
{
    this->start = chrono::steady_clock::now();
    return;
}
template<typename T>
void intervalTime<T>::updateEnd()
{
    this->end = chrono::steady_clock::now();
    return;
}
template<typename T>
T intervalTime<T>::getDuration()
{
    this->dur = chrono::duration_cast<chrono::nanoseconds>(this->end - this->start);
    return this->dur;
}

randomInt::randomInt() : seed(),engine(seed()),distrib(0,0) {}
void randomInt::setDistrib(int mmin,int mmax)
{
    this->distrib = uniform_int_distribution<>(mmin,mmax);
    return;
}
int randomInt::getRandom()
{
    return this->distrib(this->engine);
}

float quickRSqrtStep1(float n)
{
    int intX0;
    float halfN,floatX0,floatX1;
    halfN = n * 0.5f;
    floatX0 = n;
    intX0 = * ( int * ) &floatX0;
    intX0 = 0x5f3759df - ( intX0 >> 1 );
    floatX0 = * ( float * ) &intX0;
    floatX1 = floatX0 * ( 1.5f - ( halfN * floatX0 * floatX0 ) );   // 0.70693 when n==2
    return floatX1;
}

float quickRSqrtStep2(float n)
{
    int intX0;
    float halfN,floatX0,floatX1;
    halfN = n * 0.5f;
    floatX0 = n;
    intX0 = * ( int * ) &floatX0;
    intX0 = 0x5f3759df - ( intX0 >> 1 );
    floatX0 = * ( float * ) &intX0;
    floatX1 = floatX0 * ( 1.5f - ( halfN * floatX0 * floatX0 ) );   // 0.70693 when n==2
    floatX1 = floatX1 * ( 1.5f - ( halfN * floatX1 * floatX1 ) );   // 0.707107 when n==2
    return floatX1;
}

void quickReverseSqrtTest(int n)
{
    float ans[4];
    long long t[4],tMin;
    int fastestMethod,same[4];
    memset(same,0,sizeof(same));
    // 测试快算-单步牛顿法
    iT.updateStart();
    ans[0] = quickRSqrtStep1(n);  // 0.70693 when n==2
    iT.updateEnd();
    t[0] = iT.getDuration().count();
    // 测试快算-二次牛顿法
    iT.updateStart();
    ans[1] = quickRSqrtStep2(n);  // 0.707107 when n==2
    iT.updateEnd();
    t[1] = iT.getDuration().count();
    // 测试化算
    iT.updateStart();
    ans[2] = (sqrt(n)/n);  // 0.707107 when n==2
    iT.updateEnd();
    t[2] = iT.getDuration().count();
    // 测试直算
    iT.updateStart();
    ans[3] = (1/sqrt(n));  // 0.707107 when n==2
    iT.updateEnd();
    t[3] = iT.getDuration().count();
    tMin=min(t[0],min(t[1],min(t[2],t[3])));
    cout<<"ans\t\ttime\t\t"<<endl;
    fout<<"ans\t\ttime\t\t"<<endl;
    for(int j=0;j<4;j++){
        cout<<ans[j]<<"\t"<<t[j]<<endl;
        fout<<ans[j]<<"\t"<<t[j]<<endl;
        if(tMin==t[j])fastestMethod = j;
        for(int k=0;k<4;k++)
            if(ans[j]==ans[k])same[j]++;
    }
    cout<<"The fastest is method "<<fastestMethod<<endl;
    fout<<"The fastest is method "<<fastestMethod<<endl;
    for(int j=0;j<4;j++)
        if(same[j]>1){
            cout<<"ans"<<j<<":\t"<<same[j]<<" same answers"<<endl;
            fout<<"ans"<<j<<":\t"<<same[j]<<" same answers"<<endl;
        }
    cout<<endl;
    fout<<endl;
}