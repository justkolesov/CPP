#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <sstream>


template<class K>
class Deque{
public:
    Deque(){}
    Deque(vector<K> front_front , vector<K> back_back) :  vector_front(front_front),vector_back(back_back)
    {
        
    }
    bool Empty() const
    {
        return (vector_front.empty()==true && vector_back.empty()==true) ? true : false;
    }
    
    
    size_t Size() const
    {
        return vector_front.size() + vector_back.size(); 
    }
    
    
    void At(size_t index) const
    {
        ostringstream os;
        os << " out of range";
        throw runtime_error(os.str());
    }
    
    
    void At(size_t index) 
    {
        
        ostringstream os;
        os << " out of range";
        throw runtime_error(os.str());
    }
    
    
    
    K& operator[](size_t index)
    {
        if(index < vector_front.size()){
            return vector_front[vector_front.size() - index - 1];
        }
        else if(index < vector_front.size() + vector_back.size()){
            return vector_back[index - vector_front.size()];
            
        }
        else{
            At(index);
        }
    }
    
    
    const K& operator[](size_t index) const
    {
        if(index < vector_front.size()){
            return vector_front[vector_front.size() - index - 1 ];
        }
        else if(index < vector_front.size() + vector_back.size()){
            return vector_back[index - vector_front.size()];
            
        }
        else{
            At(index);
        }
        
    }
    
    
    const K& front() const
    {
        return vector_front[vector_front.size()  - 1];
    
    }
    
    
    const K& back() const
    {
        return vector_back[vector_back.size() - 1];
    }
    
    
    K& front()
    {
        return vector_front[vector_front.size() - 1];
    }
    
    
    K& back()
    {
        return vector_back[vector_back.size() - 1];
    }
    
    
    void PushFront(K element)
    {
        vector_front.push_back(element);
    }
    
    
    void PushBack(K element)
    {
        vector_back.push_back(element);
    }
    
    
    ~Deque(){}
    
private:
    vector<K> vector_back;
    vector<K> vector_front;
    
};