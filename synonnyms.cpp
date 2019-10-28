#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <exception>
#include <algorithm>
#include <string>

using namespace std;
using Synonyms = map<string,set<string>>;

void ADDSynonyms(Synonyms& synonyms,const string& first_word,const string& second_word){
    synonyms[first_word].insert(second_word);
    synonyms[second_word].insert(first_word);
}

size_t GetSynonymCount(Synonyms& synonyms,const string& first_word){
    return synonyms.count(first_word);
}

bool AreSynonyms(Synonyms& synonyms, const string& first_word, const string& second_word){
    return synonyms[first_word].count(second_word) == 1;
}


template<typename W>
ostream& operator<<(ostream& os,const set<W>& w){
    os << "{";
    bool first = true;
    for(const auto& element: w){
        if(!first){
            os << ", ";
        }
        first = false;
        os << element;
    }
    return os << "}";
}

template<class K,class W>
ostream& operator<<(ostream& os, const map<K,W>& m){
    os << "{";
    bool first = true;
    for(const auto& element: m){
        if(!first){
            os << ",";
        }
        first = false;
        os << "{" <<  element.first << ", " << element.second << "}";
        
    }
    return os << "}";
}

template<class U,class K>
void AssertEqual(const U&u,const K&k,const string& hint){
    
    if(u != k){
        ostringstream os;
        os << "Assertion Failed : " << k <<  "!= " << u << " Hint: " << hint;
        throw runtime_error(os.str());
    }
}

inline void Assert(bool b,const string& hint){
    AssertEqual(b,true,hint);
}


/* Tests */
void TestADDSynonyms(){
    {
        Synonyms empty;
        ADDSynonyms(empty,"a","b");
        const Synonyms expected = {
            {"a",{"b"}},{"b",{"a"}}
        };
        AssertEqual(empty,expected,"synonyms empty");
    }
    {
        Synonyms synonyms = {
            {"a",{"b"}},
            {"b",{"a","c"}},
            {"c",{"b"}}
        };
        ADDSynonyms(synonyms,"a","c");
        const Synonyms expected = {
            {"a",{"b","c"}},
            {"b",{"a","c"}},
            {"c",{"b","a"}}
        };
        AssertEqual(synonyms,expected,"synonyms ADD");
        
    }
     
        
}

void TestCount(){
    {
        Synonyms empty;
        AssertEqual(GetSynonymCount(empty,"a"),0u,"count for empty");
    }
    
    {
        Synonyms synonyms = {
            {"a",{"b","c"}},
            {"b",{"c"}},
            {"c",{"a"}}
        };
        AssertEqual(GetSynonymCount(synonyms,"a"),1u,"count");
        AssertEqual(GetSynonymCount(synonyms,"c"),1u,"count");
        AssertEqual(GetSynonymCount(synonyms,"f"),0u,"count");
    }
     
}

void TestAreSynonyms(){
    {
        Synonyms empty;
        Assert(!AreSynonyms(empty,"a","b"),"empty a b");
        Assert(!AreSynonyms(empty,"b","c"),"empty b c");
    }
    {
        Synonyms synonyms = {
            {"a",{"b","c"}},
            {"b",{"a"}},
            {"c",{"a"}}
        };
        Assert(AreSynonyms(synonyms,"c","a"),"error 1");
        Assert(AreSynonyms(synonyms,"a","b"),"error 2");
        
    }
    
}

/* class for testing*/
class TestRunner{
public:
    template<class TestFunc>
    void RunTest(TestFunc func,const string& test_name){
        try{
            func();
            cerr << test_name << "OK " << endl;
        }
        catch(runtime_error& ex){
            ++fail_count;
            cerr << test_name << " failed : " << ex.what() << endl;
            
        }
    }
    ~TestRunner(){
        if(fail_count > 0){
            cerr << fail_count << "  tests failed. The programm terminates";
            exit(1);
        }
    }
private:
    int fail_count = 0;
    
};


void TestAll(){
    TestRunner tr;
    tr.RunTest(TestADDSynonyms,"TestADDSynonyms");
    tr.RunTest(TestAreSynonyms,"TestAreSynonyms");
    tr.RunTest(TestCount,"TestCount");
}



int main()
{   
    
    TestAll();
    
    int q;
    cin>>q;
    
    Synonyms synonyms;
    for (int i = 0;i < q;++i){
        string operation_code;
        cin>>operation_code;
        
        if(operation_code == "ADD"){
            string first_word,second_word;
            cin>>first_word>>second_word;
            ADDSynonyms(synonyms,first_word,second_word);
        }
        else if(operation_code == "COUNT"){
            string word;
            cin >> word;
            cout<< GetSynonymCount(synonyms,word) << endl;
        }
        else if(operation_code == "CHECK"){
            string first_word,second_word;
            cin >> first_word >> second_word;
            AreSynonyms(synonyms,first_word,second_word) == 1 ? cout << "YES" : cout << "NO";
        }
            
    }

    return 0;
}
