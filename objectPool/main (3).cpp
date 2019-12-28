#include "ObjectPool.h"

#include<iostream>

using namespace std;

int counter = 0;

struct Counted{
    Counted(){
        ++counter;
    }
    ~Counted(){
        --counter;
    }
};

void run()
{
    ObjectPool<Counted> pool;
    cout << "counter before loop " << counter << endl;
    try{
        for(int i = 0;i < 1000;++i)
        {
            cout << "Allocating object#" << i << endl;
            pool.Allocate();
        }
        cout << "counter after loop " << counter << endl;
    }
    catch(const bad_alloc& e)
    {
        cout << e.what() << endl;
    }
}

int main(){
    run();
    cout << "counter before exit " << counter << endl;
    return 0;
}