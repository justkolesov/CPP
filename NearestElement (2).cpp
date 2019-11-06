#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <exception>
#include <sstream>

using namespace std;

template<class K>
typename set<K>::const_iterator FindNearestElement(const set<K>& numbers,K border){
    if(numbers.empty()){
        ostringstream os;
        os << "Empty set is an exception";
        throw runtime_error(os.str());
    }
    if(*begin(numbers) > border){
        return begin(numbers);
    }
    else if(*(--end(numbers)) < border){
        return --end(numbers);
    }
    else{
        typename set<K>::const_iterator it = begin(numbers);
        typename set<K>::const_iterator prev_it = begin(numbers);
        while(*it < border){
            prev_it = it;
            it = next(it);
        }
        return (*it - border < border - *(prev_it)) ? it :  prev_it;
    }
}

int main() {
  set<int> numbers = {1,4,6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      

    return 0;
}
