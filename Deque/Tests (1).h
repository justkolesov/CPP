#pragma once 

#include<string>
#include<exception>
#include<vector>
#include<sstream>
#include<cassert>

using namespace std;

template<class K, class W>
void AssertEqual(K k,W w,const string& hint){
    ostringstream os;
    if(k != w){
        os << " Assertion failed " << k << " != " << w << "endl";
        throw runtime_error(os.str());
    }
}

void TestSize(){
    {
        vector<string> forward = {"moscow","narrow","wimldone"};
        vector<string> backward = {"buenos","venezuela","watfard"};
        Deque<string> tr(forward,backward);
        size_t expected = 6;
        AssertEqual(tr.Size(),expected,"the error , which is about size");
    }
}

void TestEmpty(){
    {
        vector<string> forward = {};
        vector<string> backward = {};
        Deque<string> tr(forward,backward);
        bool expected = true;
        AssertEqual(tr.Empty(),expected," the error, which is about empty string");
    }
    {
        Deque<int>  tr;
        bool expected = true;
        AssertEqual(tr.Empty(),expected,"the error, which is about empty string");
    }
}

void TestOperator(){
    {
        vector<string> forward = {"sport","austria","room","shelbey"};
        vector<string> backward = {"real","mountain","suiwtezer"};
        Deque<string> tr(forward,backward);
        const string expected = "mountain";
        AssertEqual(tr[5],expected," first operator test");
    }
    {
        vector<string> forward = {"sport","austria","room","shelbey"};
        vector<string> backward = {"real","mountain","suiwtezer"};
        Deque<string> tr(forward,backward);
        const string expected = "austria";
        AssertEqual(tr[1],expected," second operator test");
        
    }
}
