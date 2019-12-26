#include<iostream>
#include <sstream>
#include "SimpleVector.h"

using namespace std;

template<typename T>
ostream& operator<<(ostream& os,const SimpleVector<T>& rhs)
{
    os << "Size: " << rhs.Size() << "Items: ";
    for(const auto& x:rhs){
        os<<" "<<x;
    }
    return os;
}



int main(){
    SimpleVector<int> source(5);
    for(size_t i = 0;i < source.Size();++i)
    {
        source[i] = i;
    }
    
    cout << source << endl;
    source = source;
    cout << source  << endl;
    SimpleVector<int> a,b,c,d,e;
    a = b = c = d = e;
    return 0;
}