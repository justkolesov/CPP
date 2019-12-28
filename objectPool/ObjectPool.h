#pragma once

#include<iostream>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<stdexcept>
#include<string>
#include<memory>

using namespace std;

template<class T>
class ObjectPool{
public:
	T* Allocate();
	T* TryAllocate();

	void  Deallocate(T* object);

	

private:
	queue<unique_ptr<T>> free;
	unordered_map<T*,unique_ptr<T>> allocated;
};

template<class T>
T* ObjectPool<T>::Allocate()
{
	if(free.empty())
	{
		free.push(make_unique(T));
	}
	unique_ptr<T> ptr = move(free.front());
	free.pop();
	T* ret = ptr.get()
    allocated[ret] = move(ptr);
	 
	return ret;
}

template<class T>
T* ObjectPool<T>::TryAllocate()
{
	if(free.empty())
	{
		return nullptr;
	}
	return Allocate();
}

template<class T>
void ObjectPool<T>::Deallocate(T* object)
{
    auto it = allocated.find(object);
	if(it == allocated.end())
	{
		throw invalid_argument(" exception ");
	}
	free.push(move(it->second));
	allocated.erase(it);
	 
}