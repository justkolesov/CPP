#pragma once

#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

class LogDuration{
public:
    explicit LogDuration(const string& msg): start(steady_clock::now()),message(msg + " : ")
    {}
    ~LogDuration(){
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << message << duration_cast<milliseconds>(dur).count() << " ms" << endl;
    }
private:
    string message;
    steady_clock::time_point start;
};