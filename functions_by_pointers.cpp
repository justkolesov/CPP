#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<class K>
void Swap(K* first,K* second){
    K swap = *first;
    *first = *second;
    *second = swap;
}

template<class K>
void SortPointers(vector<K*>& pointers){
    sort(begin(pointers),end(pointers),[](K* lhs,K* rhs)
    {
        return *lhs < *rhs;
    });
}

template<class K>
void ReversedCopy(K* src,int count,K* dst){
    K* source_begin = src;
    K* source_end = src + count;
    K* destination_begin = dst;
    K* destination_end = dst + count;
    if(source_end <= destination_begin || destination_end <= source_begin ){
        reverse_copy(source_begin,source_end,destination_begin);
    }
    else if(destination_begin > source_begin){
        for(size_t i = 0; destination_begin > i + source_begin;++i){
            *(destination_end - 1 - i) = *(source_begin + i);
        }
        reverse(destination_begin,source_end);
    }
    else{
        for(size_t i = 0; source_end - i - 1 >= destination_end;++i){
            *(destination_begin + i) = *(source_end - 1 - i);
        }
        reverse(source_begin,destination_end);
    }
}



int main()
{
    return 0;
}
