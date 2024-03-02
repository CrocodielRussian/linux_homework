#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <utility>
class float_array{
	private:
		float* _data = nullptr;
		size_t _size = 0;
	public:
		float_array(const float_array& x):_data(new float[x._size]), _size(x._size){
			for(size_t i=0; i<_size; ++i)
				_data[i] = x._data[i];
		}
		float_array(float_array&& x):_data(x._data),_size(x._size){
			x._data = nullptr;
			x._size = 0;
		}
		float_array& operator=(const float_array& x){
			float_array tmp(x);
			swap(tmp);
			return *this;
		}
		float_array(){}
		~float_array(){
			delete[] _data;
		}
		float_array& operator=(const float_array&& x){
			float_array tmp(std::move(x));
			swap(tmp);
			return *this;
		}	
			
		void swap(float_array& x){
			std::swap(_data, x._data);
			std::swap(_size, x._size);
		}
};

int main(){
	float a[5] = {1.0, 2.0 , 3.0, 4.0, 5.0};
	float_array x = float_array(a);
	
	return 0;
}
