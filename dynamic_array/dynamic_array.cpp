#include<iostream>
#include<sstream>
#include "dynamic_array.h"

DynArray::DynArray(const int Size) {
	if (Size > 0) {
		p_size_ = Size;
		l_size_ = 0;
	 data_ = new int[Size];
	}
	else {
		std::cout << "Размер указан не верно";
	}
	for (int i = 0; i < Size; i++) {
		std::cout << data_[i] << "/t";
	}
}
//метод swap - меняет 2 конструктора копирования, если выбрасывается ошибка

int& DynArray::operator [](int n) {
	if (n < size) {
		return *(data_ + n);
	}
	else {
		std::cout << "Указываемый индекс больше длины массива";
	}
}

DynArray::DynArray(const DynArray& arr) {
	if (this != &arr) {
		p_size_ = arr.p_size_;
		l_size_ = arr.l_size_;
		data_ = new int[p_size_];

		for (int i = 0; i < l_size_; i++) {
			data_[i] = arr.data_[i];
		}
	}
}

DynArray::~DynArray() {
	delete[] data_;
}



/*DynArray(const DynArray& arr);
{
	if (size > 0)
	{
		arr.m_size = size;
		arr.m_DAR = new T[arr.m_size];
		//проверка, что массив пусой
		//либо при создании непустого, уничтожение первого и создание нового
	}
}
*/
/*void Write_massive(DynArray& arr)
{
	for (int i = 0; i < arr.m_size; i++)
	{
		printf("%d", arr.m_DAR[i]);
	}
}
*/
DynArray& size(DynArray& arr) {
	return arr.p_size;
};


void resize(DynArray& arr, const int newsize)
{
	if (newsize > 0)
	{
		if (newsize > arr.size)
		{
			int* p_DAR = new int[newsize];
			for (int i = 0; i < arr.size; i++)
			{
				p_DAR[i] = arr.data_[i];
			}
			//заполняем значениями старого массива часть нового массива
			for (int i = arr.size; i < newsize; i++)
			{
				p_DAR[i] = 0;
			}
			delete arr.data_;
			arr.data_ = p_DAR;
			arr.size = newsize;
		}
		else
		{
			if (newsize < arr.size)
			{
				arr.size = newsize;
			}
		}
	}
}
