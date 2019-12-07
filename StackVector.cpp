#include <iostream>
#include <array>
#include <stdexcept>

using namespace  std;

template<class T,size_t N>
class StackVector{
public:
	explicit StackVector(size_t a_size = 0): size(a_size)
	{
		if(size > N){
			throw invalid_argument("Too much");
		}
	}

	auto begin(){return data.begin();}
	auto end(){return data.begin() + size;}
	auto begin() const{return data.begin();}
	auto end() const{return data.begin() + size;}
	
	const T& operator[](size_t index) const{
		return data[index];
	}
	T& operator[](size_t index){
		return data[index];
	}
	
	size_t Size() const{
		return size;
	}

	size_t Capacity() const{
		return N;
	}

	void PushBack(const T& element)
	{
		if(size >= N)
		{
			throw overflow_error("overlow");
		}
		else
		{
			data[size++] = element;
		}
	}

	

	T& PopBack()
	{
		if(size == 0){
			throw underflow_error("undeflow");
		}
		else{
			--size;
			return data[size];
		}
	}
private:
	size_t size = 0;
	array<T,N> data;
};

int main(){
    StackVector<int,16> array_;
    array_.PushBack(3);
    //array_.PushBack(2);
    //array_.PushBack(5);
    //array_.PushBack(7);
    //array_.PushBack(9);
    cout << array_.PopBack();
	return 0;
}