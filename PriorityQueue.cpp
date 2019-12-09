#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <sstream>

using namespace std;

template<class T>
class PriorityQueue{
public:
	PriorityQueue(const size_t& heap_size = 0) : size(heap_size){} //constructor
	

	static const size_t MAX_SIZE = 100;
	struct Element // element of array
	{
		T value;
		size_t priority;
		Element(const T& value ,const size_t& priority = 0)
		{
			this->value = value;
			this->priority = priority;
		}
	};
	
	size_t size;
	vector<Element> heap_array{MAX_SIZE};

	void swap(const T& first,const T& second)// swap by move-semantics
	{
		T tmp = move(first);
		first = move(second);
		second = move(tmp);
	}

	void up(size_t index) 
	{
		while(index != 0 && heap_array[index].priority > heap_array[(index - 1)/2].priority){
			swap(heap_array[index],heap_array[(index - 1)/2]);
			index = (index - 1)/2;
		}
	}

	void down(size_t index)
	{
		while(index < size/2)
		{
			size_t max_index = 2*index + 1;
			if(max_index + 1 < size && heap_array[max_index + 1].priority > heap_array[max_index].priority){
				max_index = 2*index + 2;
			}
			if(heap_array[max_index].priority > heap_array[index].priority){
				swap(heap_array[max_index],heap_array[index]);
				index = max_index;
			}
		}
	}

	void enqueue(const T& value,const size_t& priority)
	{
		if(size + 1 == MAX_SIZE){
			ostringstream os; 
			os << "heap_array is crowded";
			throw overflow_error(os.str());
		}
		heap_array[size++] = Element(value,priority);
		up(size - 1);
	}

	T& dequeue()
	{

		if(size == 0){
			ostringstream os;
			os << "heap_array is empty";
			throw underflow_error(os.str());
		}
		swap(heap_array[0],heap_array[--size]);
		down(0);
		return heap_array[size];
	}

	bool IsEmpty(){
		return size == 0;
	}

};



 