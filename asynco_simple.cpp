#include <iostream>
#include <future>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <mutex>

using namespace std;
// Struct 
struct Account{
    int balance;
    vector<int> history;
    mutex m;
    
    bool Spend(int value){
        lock_guard<mutex> g(m);
        if(value <= balance){
            balance -= value;
            history.push_back(value);
            return true;
        }
        return false;
     }
};

int SpendMoney(Account& account){
    int total_spent  = 0;
    for(auto i = 0 ; i < 100000; ++i){
        if(account.Spend(1) == true){
            ++total_spent;
        }
    }
    return total_spent;
}

int main(){
    Account family_account{100000};
    
    future<int> husband = async(SpendMoney,ref(family_account));
    future<int> wife = async(SpendMoney,ref(family_account));
    future<int> son = async(SpendMoney,ref(family_account));
    future<int> daughter = async(SpendMoney,ref(family_account));
    
    int spent = husband.get() +  wife.get() + son.get() + daughter.get();
    cout << " Total spent :" << spent << endl << " Balance : " << family_account.balance << endl;
    
    return 0;
}