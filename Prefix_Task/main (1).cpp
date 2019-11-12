#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

#include "profiler.h"
#include "solve.h"
#include "tests.h"
#include "test_runner.h"

#define RUN_TEST(tr,func)\
    RunTest(func,#func)
    
 
int main()
{
    TestAll();
    vector<string> v = {"hai","peninsula","pep","pepsi","peres","pumpkin"};
    {
        LogDuration total("total");
        {
            for(auto start = Func(begin(v),end(v),"pe").first ; start!= Func(begin(v),end(v),"pe").second; ++start){
            cout << *start << " ";
            }
            cout << endl;
        }
    }
     

    return 0;
}
