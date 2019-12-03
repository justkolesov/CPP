#include <iostream>
#include <algorithm>



using namespace std;

template<class T>
class SimpleVector{
public:
	SimpleVector = default; //  default constructor
	explicit SimpleVector(size_t size); // explicit constructor
	~SimpleVector(); // destructor

	SimpleVector(const SimpleVector& other); // copy constructor
	SimpleVector(SimpleVector&& other); // forwarding construction

	void operator=(const SimpleVector& other); // operator of the accesing for lvalue reference
	void operator=(SimpleVector&& other); // operator of the accesing for rvalue reference

	T& operator[](size_t index); // operator []
	size_t Size(); 
	size_t Capacity();
	
	T* begin(); // technique for unconst vector
	T* end(); // technique for unconst vector
	const T* begin() const; // technique for const vector and returns const pointer
	const T* end() const; // technique for const vector and returns const pointer 

	void PushBack(const T& element); // PushBack by copying
	void PushBack(T&& element);// PushBack by forwarding
	void Clear(); // clearing of our object
private:
	T* data = nullptr;;
	size_t size = 0;
	size_t capacity = 0;
};

template<class T>
SimpleVector<T>::SimpleVector(size_t size) : data(new T[size]), size(size) , capacity(size)
{}

template<class T>
SimpleVector<T>::~SimpleVector(){
	delete[] data;
}

template<class T>
SimpleVector<T>::SimpleVector(const SimpleVector& other): data(new T[other.size]),size(other.size),capacity(other.capacity)
{
	copy(begin(other),end(other),begin());
}

template<class T>
SimpleVector<T>::SimpleVector(SimpleVector<T>&& other) : data(other.data),size(other.size),capacity(other.capacity)
{
	other.data = nullptr;
	other.size = other.capacity = 0;
}

template<class T>
void SimpleVector<T>::operator=(SimpleVector<T>& other)
{
	delete[] data;
	SimpleVector* data = new T[other.capacity];
	size = other.size;
	capacity = other.capacity;
	copy(begin(other),end(other),begin());
}

template<class T>
void SimpleVector<T>::operator=	(SimpleVector<T>&& other)
{
	delete[] data;
	data = other.data;
	size = other.size;
	capacity = other.capacity;
	other.data = nullptr;
	other.size = other.capacity = 0;
}

template<class T>
T& SimpleVector<T>::operator[](size_t index)
{
	return data + index;
}

template<class  T>
size_t SimpleVector<T>::Size(){
	return size;
}

template<class T>
size_t SimpleVector<T>::Capacity(){
	return capacity;
}

template<class T>
T* SimpleVector<T>::begin()
{
	return data;
}

template<class T>
T* SimpleVector<T>::end()
{
	return data + size;
}

template<class T>
const T* SimpleVector<T>::begin() const
{
	return data;
}

template<class T>
const T* SimpleVector<T>::end() const 
{
	return data + size;
}


template<class T>
void SimpleVector<T>::PushBack(const T& element)
{
	if(size >= capacity){
		size_t new_capacity = (capacity == 0) ? 1 : 2 * capacity;
		T* new_data = new T[new_capacity];
		copy(begin(),end(),new_data);
		delete data;
		data = new_data;
		capacity = new_capacity;

	}
	data[size++] = element;
}

template <typename T>
void SimpleVector<T>::PushBack(T value) {
  ExpandIfNeeded();
  data[size++] = move(value);
}

template <typename T>
void SimpleVector<T>::ExpandIfNeeded() {
  if (size >= capacity) {
    auto new_cap = capacity == 0 ? 1 : 2 * capacity;
    auto new_data = new T[new_cap];
    // используем перемещение
    move(begin(), end(), new_data);
    delete[] data;
    data = new_data;
    capacity = new_cap;
  }
}


int main(){
	return 0;
}