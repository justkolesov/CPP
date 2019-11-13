#pragma once 

#include <vector>
#include <exception>
#include <string>
#include <iostream>

class TestRunner{
public:
    template<class TestFunc>
    void RunTest(TestFunc func,const string& name_test){
        try{
            func();
            cerr << name_test << " is Ok";
            
        }
        catch(runtime_error& ex){
            ++ fail_count;
            cerr << name_test << " failed " << ex.what() << endl;
        }
    }
    ~TestRunner(){
        if(fail_count > 0){
            cerr << fail_count << " tests faile. The programm terminated";
            exit(1);
        }
    }
private:
    int fail_count = 0 ;
};

void TestAll(){
    TestRunner tr;
    tr.RunTest(TestSize,"TestSize");
    tr.RunTest(TestEmpty,"TestEmpty");
    tr.RunTest(TestOperator,"TestOperator");
}