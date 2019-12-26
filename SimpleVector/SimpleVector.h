#pragma once
#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

template<class T>
class SimpleVector{
public:
	SimpleVector() = default;
	explicit SimpleVector(size_t a_size);
	~SimpleVector();

	SimpleVector(const SimpleVector& other);
	SimpleVector(SimpleVector&& other);

	SimpleVector<T>& operator=(const SimpleVector& other);
	SimpleVector<T>& operator=(SimpleVector&& other);

	T& operator[](size_t index);
	size_t Size() const;
	size_t Capacity();

	T*begin();
	T*end();
	const T* begin() const;
	const T* end() const;

	void PushBack(const T& element);
	void PushBack(T element);
	void Clear();

private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	
	void ExpandIfNeed();
};

template<class T>
SimpleVector<T>::SimpleVector(size_t a_size): data(new T[a_size]),size(a_size),capacity(a_size)
{
    cout << this << endl;
}

template<class T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data;
}

template<class T>
SimpleVector<T>::SimpleVector(const SimpleVector& other):data(new T[other.size]),size(other.size),capacity(other.capacity)
{
	copy(begin(other),end(other),begin());
}

template<class T>
SimpleVector<T>::SimpleVector(SimpleVector&& other):data(other.data),size(other.size),capacity(other.capacity)
{
	other.data = nullptr;
	other.size = other.capcity = 0;	
}

template<class T>
T* SimpleVector<T>::begin()
{
	return data;
}

template<class T>
const T* SimpleVector<T>::begin() const
{
	return data;
}

template<class T>
T* SimpleVector<T>::end()
{
	return data + size;
}

template<class T>
const T* SimpleVector<T>::end() const
{
	return data + size;
}

template<class T>
SimpleVector<T>& SimpleVector<T>::operator=(const SimpleVector<T>& other)
{
    if(this != &other){
	    delete[] data;
	    data = new T[other.capacity];
	    size = other.size;
	    capacity = other.capacity;
	    copy(other.begin(),other.end(),begin());
    }
    
    return *this;

}

template<class T>
SimpleVector<T>& SimpleVector<T>::operator=(SimpleVector<T>&& other)
{
    if(this != &other){
	    delete[] data;
	    data = other.data;
	    
	    size = other.size;
	    capacity = other.capacity;
	    
	    other.data = nullptr;
	    other.size = other.capacity = 0;
    }
    
    return *this;
}

template<class T>
T& SimpleVector<T>::operator[](size_t index)
{
	return data[index];
}

template<class T>
size_t SimpleVector<T>::Size() const
{
	return size;
}

template<class T>
size_t SimpleVector<T>::Capacity()
{
	return capacity;
}

 


template<class T>
void SimpleVector<T>::PushBack(const T& element)
{
	if(size >= capacity){
		size_t new_capacity  = (capacity == 0) ? 1 : 2*capacity;
		capacity = move(new_capacity);
		T* new_data = new T[2*capacity];
		copy(begin(),end(),new_data);
		delete[] data;
		data = move(new_data);
	}
	data[size++] = element;
}

template<class T>
void SimpleVector<T>::ExpandIfNeed()
{
	if(size >= capacity){
		auto new_capacity = (capacity == 0) ? 1 : 2*capacity;
		capacity = move(new_capacity);
		T* new_data = new T[new_capacity];
		move(begin(),end(),new_data);
		delete[] data;
		data = move(new_data);
	}
}


template<class T>
void SimpleVector<T>::PushBack(T element)
{
	ExpandIfNeed();
	data[size++] = move(element);
}

template<class T>
void SimpleVector<T>::Clear()
{
	delete[] data;
	data = new T[0];
	size = capacity = 0;
}

