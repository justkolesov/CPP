#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class SimpleVector{
public:
	SimpleVector() = default;
	explicit SimpleVector(size_t size){};
	SimpleVector(const SimpleVector& other);
	~SimpleVector();

	T& operator[](size_t index);
	T* begin();
	T* end();
	const T* begin() const;
	const T* end() const;

	size_t Size();
	size_t Capacity();
	void PushBack(const T& element);
private:
	T* data = nullptr;
	size_t size = 0 ;
	size_t capacity = 0;
};

template<class T>
SimpleVector<T>::SimpleVector(size_t size): data(new T[size]),size(size),capacity(size)
{}

template<class T>
SimpleVector<T>::SimpleVector(const T& other) : data(new T[other.capacity]),size(other.size),capacity(other.capacity)
{
	copy(other.begin(),other.end(),begin());
}

template<class T>
SimpleVector<T>::~SimpleVector(){ delete[] data;}

template<class T>
T& SimpleVector<T>::operator[](size_t index){
	return data + index;
}

template<class T>
size_t SimpleVector<T>::Size() const{
	return size;
}

template<class T>
size_t SimpleVector<T>::Capacity() const{
	return capacity;
}

template<class T>
void SimpleVector<T>::PushBack(const T& value){
	if(size >= capacity){
		auto new_capacity = (capacity == 0) ? 1 :  2 * capacity;
		T* new_data = new T[new_capacity];
		copy(begin(),end(),new_data);
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}
	data[size++] = value;
}

template<class T>
T* SimpleVector<T>::begin(){
	return data;
}

template<class T>
const T* SimpleVector<T>::begin() const{
	return data;
}

template<class T>
const T* SimpleVector<T>::end(){
	return data + size;
}

template<class T>
const T* SimpleVector<T>::end() const{
	return data + size;
}



int main(){
	return 0;
}