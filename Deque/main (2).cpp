#include <iostream>

using namespace std;
#include "Solve.h"
#include "Duration.h"
#include "Tests.h"
#include "Test_Runner.h"

int main()
{
    {
        LogDuration input("total");
        vector<int> v1 = {1,2,3};
        vector<int> v2 = {8,9,10};
        Deque<int> tr(v1,v2); 
        tr.PushBack(5);
        tr.PushFront(2);
        tr.PushFront(1);
        tr.PushBack(4);
        cout << tr.Size() << " " << tr[1] << " " << tr[3] << " " << tr[9] << endl;

    }
    return 0;
}
