#pragma once

#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<cassert>
#include<utility>
#include<exception>


template<class RandomIt>
void AssertEqual(pair<RandomIt,RandomIt> u, pair<RandomIt,RandomIt> k, const string& hint){
    if(u != k){
        ostringstream os;
        os << " Assertion Failed  :Hint" << hint;
        throw runtime_error(os.str());
    }
}


void TestFunc(){
    {
        vector<string> v = {"amiak","amman","anuas","anyas","danube"};
        const string& message = "am";
        const pair<vector<string>::iterator,vector<string>::iterator> expected = make_pair(begin(v),++next(begin(v)));
        AssertEqual(Func(begin(v),end(v),message),expected," simple test for task");
    }
    
}