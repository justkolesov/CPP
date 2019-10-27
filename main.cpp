#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
#include <cassert>
#include <sstream>
#include <cmath>


using namespace std;


/* overload operator  for unit testing*/
template<class K>
ostream& operator<<(ostream& os,const vector<K>& k){
    os << "{";
    bool first = true;
    for(const auto& element:k){
        if(!first){
            os << ", ";
        }
        first = false;
        os << element;
    }
    return os << "}";
}



/* AssertEqual  function for unit testing*/
template<class T, class U>
void AssertEqual(const T& t, const U& u,
    const string& hint)
{
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u
       << " hint: " << hint;
    throw runtime_error(os.str());
  }
}



/* technique, which is responsible for worry persons */
void StartWorry(vector<bool>& v,int index){
    try{
        if(index < v.size()){
            v[index] = true;
        }
        else{
            vector<bool> additional_vector(index - v.size() + 1,false);
            additional_vector.insert(additional_vector.begin(),v.begin(),v.end());
            v = additional_vector;
            v[index] = true;
        }
    }catch(exception& ex){
        cout << "exception.happens in StartWorry : "<< ex.what();
    }
}

/* Unit test for the previous function*/
void  TestStartWorry(){
    {
        vector<bool> trial_1 = {false,false,false};
        StartWorry(trial_1,2);
        const vector<bool> expected = {false,false,true};
        AssertEqual(trial_1,expected,"error with trial 1 in StartWorry");
    }
    {
        vector<bool> empty;
        StartWorry(empty,3);
        const vector<bool> expected = {false,false,false,true};
        AssertEqual(empty,expected,"error with empty in StartWorry");
        
    }
    cout << "StartWorry is ok"<< endl;
}


/* Technique, which is responsible for unworry persons */
void FinishWorry(vector<bool>& v, int index){
    try{
        if(index < v.size()){
            v[index] = false;
        }
        else{
            vector<bool> additional_vector(index - v.size() + 1,false);
            additional_vector.insert(additional_vector.begin(),v.begin(),v.end());
            v = additional_vector;
        }
        
    }
    catch(exception& ex){
        cout << "exception happens in FinishWorry: "<<ex.what();
    }
}

/* Unit testing for the prrevious function*/
void TestFinishWorry(){
    {
        vector<bool> trial_1 = {false,false,true};
        FinishWorry(trial_1,2);
        const vector<bool> expected = {false,false,false};
        AssertEqual(trial_1,expected,"error with trial 1 in FinishWorryorry");
    }
    {
        vector<bool> empty;
        FinishWorry(empty,5);
        const vector<bool> expected = {false,false,false,false,false,false};
        AssertEqual(empty,expected,"error with empty in FinishWorry ");
    }
    cout << "TestFinishWorry is ok "<< endl;
}



/* next function*/
int GetWorryCount(const vector<bool>& v){
    return count(v.begin(),v.end(),true);       
}

/* Unit testing for the previous function*/
void TestGetWorryCount(){
    {
        vector<bool> trial_1 = {false,true,true};
        AssertEqual(GetWorryCount(trial_1),2," error in trial 1 in  TestGetWorryCount ");
    }
    {
        vector<bool> empty;
        AssertEqual(GetWorryCount(empty),0," error in empty in TestGetWorryCount ");
    }
    cout << " TestGetWorryCount is ok " << endl;
}


/* final technique*/
void ComeInOutQueue(vector<bool>& v, int k){
    try{
        if(k < 0 && !(v.size() < (-1)*(k))){
            int i = 0;
            int const_size = v.size();
            while(const_size - i > const_size - (-1)*k) {
                v.pop_back();
                i++;
                
            }
        }
        else if(k > 0){
            int i = 0;
            while(v.size() + i < v.size() + k){
                v.push_back(false);
                i++;
            }
        }
        else if(k > 0 && v.size() < k){
            v.resize(0,false);
        }
        
        
    }
    catch(exception& ex){
        cout<<"exception happens in ComeInOutQueue"<<ex.what();
    }
}

/*Unit testing for the final function*/
void TestComeInOutQueue(){
    {
        vector<bool> empty;
        ComeInOutQueue(empty,2);
        const vector<bool> expected = {false,false};
        AssertEqual(empty,expected,"error empty + TestComeInOutQueue");
    }
    {
        vector<bool> trial_1 = {true,false,false,false};
        ComeInOutQueue(trial_1,-3);
        const vector<bool> expected = {true};
        AssertEqual(trial_1,expected,"error trial - in TestComeInOutQueue");
    }
    {
        vector<bool> trial_1 = {true,true,false};
        ComeInOutQueue(trial_1,2);
        const vector <bool> expected = {true,true,false,false,false};
        AssertEqual(trial_1,expected,"error trial+ TestComeInOutQueue");
    }
    {
        vector<bool> empty;
        ComeInOutQueue(empty,-2);
        const vector<bool> expected = {};
        AssertEqual(empty,expected,"error empty - in TestComeInOutQueue");
    }
    cout << " TestComeInOutQueue is ok "<< endl;
}

/* commom test function*/
void TestAll(){
    TestStartWorry();
    TestFinishWorry();
    TestGetWorryCount();
    TestComeInOutQueue();
}


int main(){
    
    TestAll();
    
    
    /*
    int q,number;
    string operation_code;
    vector<bool> v; 
    cin >> q;
    for(int i = 0 ; i < q; ++i){
        cin >> operation_code;
        cin >> number;
        if(operation_code == "WORRY" && number > 0){
            if(!v.empty()){
                v.resize(number,false);
            }
            StartWorry(v,number);
        }
        else if(operation_code == "COME"){
            ComeInOutQueue(v,number);
        }
        else if(operation_code == "QUIET" && number > 0){
            if(!v.empty()){
                v.resize(number,false);
            }
            FinishWorry(v,number);
        }
        else if(operation_code == "WORRY_COUNT"){
            cout << GetWorryCount(v) << endl;
        }
    }
    */

    return 0;
}
