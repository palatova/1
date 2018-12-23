#pragma once
#include <cstdio>
#include <iostream>
#include <sstream>
//структуры- набор произвольных типов
class DynArray {
public:
    DynArray() = default;
	//дефолтный конструктор
	explicit DynArray(const int Size);
	//конструктор
	DynArray(const DynArray& arr);
	//конструктор копирования
	~DynArray();
	//деструктор
	DynArray operator[](int n);
	DynArray operator= (const DynArray& arr);
	int size(DynArray& arr);
	///метод swap
	void resize(DynArray& arr, const int newsize);

	//std::ostream& operator<<(std::ostream& lhs, DynArray& rhs);

private:
	int* data_;
	int p_size_{ 0 };
	int l_size_{ 0 };
};








