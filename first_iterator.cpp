#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

template<class K>
void SearchSet(K border,K range_end){
    for(K it = border; it != range_end;++it){
        cout << *it << " ";
    }
}

template<class T>
vector<T> FindGreatSearcher(const set<T>& elements,const T& border){
    vector<T> v;
    typename set<T>::iterator result = find_if(begin(elements),end(elements),[border](const T& element){return element > border; });
    for(typename set<T>::iterator it = result; it != end(elements);++it){
        v.push_back(*it);
    }
    return v;
}

int main()
{
    set<int> vv = {1,2,3,4,5};
    for(auto& el:FindGreatSearcher(vv,3)){
        cout << el << " ";
    }

    return 0;
}
