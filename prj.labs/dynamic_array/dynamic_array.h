#pragma once
#include <cstdio>
#include <iostream>
#include <sstream>
class DynArray {
public:
    DynArray() = default;
	
	explicit DynArray(const int Size);

	DynArray(const DynArray& arr);
	~DynArray();
	int& operator[](int index)const;
	DynArray& operator= (const DynArray& Arr);
	int size() const;
	void resize(const int newsize);


private:
	int* data_{ nullptr };
	int size_{ 0 };
};








