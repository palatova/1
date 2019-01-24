#include<iostream>
#include<sstream>
#include "dynamic_array.h"

DynArray::DynArray(const int Size) {
	if (Size > 0) {
		size_ = Size;
	 data_ = new int[size_];
	}
	else {
		std::cout << "Size is not available";
	}
	for (int i = 0; i < Size; i++) {
		data_[i] = 0;
	}
}


int& DynArray::operator[](int index)const {
	if ((index > size_) ||(index<0)) {
		
		std::cout << "”казываемый индекс больше длины массива, либо номер элемента <0";
	}
	return data_[index];
}
DynArray& DynArray::operator=(const DynArray& Arr) {

		if (Arr.size_ > size_) 
		{
			int* newArr = new int[Arr.size_];
			delete data_;
			size_ = 0;
			data_ = newArr;
			size_ = Arr.size_;
			for (int i = 0; i < size_; i++)
			{
				data_[i] = Arr[i];
			}
			return *this;
		}
	
}
DynArray::DynArray(const DynArray& arr) {
	if (this != &arr) {

		for (int i = 0; i < size_; i++) {
		data_[i] = arr[i];
		}
	}
}

DynArray::~DynArray() {
	delete[] data_;
	data_ = nullptr;
	size_ = 0;
}



int DynArray::size() const{
	return size_;
};


void DynArray::resize(const int newsize)
{
	if (newsize < 0) throw std::invalid_argument("Unacceptable");
	else
	{
		int* arr = new int[newsize];
		if (newsize > size_)
		{
			
			for (int i = 0; i < size_; i++)
			{
				arr[i] = data_[i];
			}
			for (int i = size_; i < newsize; i++)
			{
				arr[i] = 0;
			}
			delete data_;
			size_ = newsize;
		}
		else
		{
			if (newsize < size_)
			{
				for (int i = 0; i < size_; i++)
				{
					arr[i] = data_[i];
				}
				delete[] data_;
				size_ = newsize;
			}
		}
		data_ = arr;
	}
}
