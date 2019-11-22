#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class T>
class Simplevector{
public:
    //explicit constructor
    explicit Simplevector(size_t size)
    {
       data = new T[size]; 
       end_ = data + size;
    }
    //operator
    T& operator[](size_t index){
        return *(data + index);
    }
    //const techniques
    T* begin(){return data;}
    T* end(){return end_;}
    //unconst techniques
    const T* begin() const {return data;}
    const T* end() const {return end_;}
    //destructor
    ~Simplevector()
    {
        delete[] data;
    }
    // private variables;
private:
    T* data;
    T* end_;
};

template<class T>
void PrintVector(const vector<T>& v){
    for(const auto& element:v){
        cout << element << " ";
    }
}

int main()
{
    return 0;
}
