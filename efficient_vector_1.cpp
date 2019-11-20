#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

class LogDuration{
public:
    explicit LogDuration(const string& msg):message(msg + ":  "),start(steady_clock::now()){}
    ~LogDuration(){
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << message << duration_cast<milliseconds>(dur).count() << " ms" << endl; 
    }
private:
    steady_clock::time_point start;
    string message;
};


template<class K>
void LogVectorParams(const vector<K>& v){
    cout << " Length :  " << v.size()<< ", " <<" capacity :  "<< v.capacity() << "\n";
}

int main()
{
    
    vector<int> v = {1,2,3};
    LogVectorParams(v);
    v.push_back(4);
    LogVectorParams(v);
    const int* data = v.data();
    for(size_t i = 0;i < v.capacity();++i){
        cout << *(data + i) << " ";
    }
    cout << "\n";
    v.shrink_to_fit();//shrinkage
    LogVectorParams(v);
    
     
    {
        LogDuration input("first");
        vector<int> b;
        for(size_t i = 0;i < 1000000;++i){
            b.push_back(i);
        }
    }
    {
        LogDuration input("second");
        vector<int> b;
        b.reserve(1000000);
        for(size_t i = 0;i < 1000000;++i){
            b.push_back(i);
        }
    }
    
    return 0;
}
