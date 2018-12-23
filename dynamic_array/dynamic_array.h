#pragma once
#include <cstdio>
#include <iostream>
#include <sstream>
//���������- ����� ������������ �����
class DynArray {
public:
    DynArray() = default;
	//��������� �����������
	explicit DynArray(const int Size);
	//�����������
	DynArray(const DynArray& arr);
	//����������� �����������
	~DynArray();
	//����������
	DynArray operator[](int n);
	DynArray operator= (const DynArray& arr);
	int size(DynArray& arr);
	///����� swap
	void resize(DynArray& arr, const int newsize);

	//std::ostream& operator<<(std::ostream& lhs, DynArray& rhs);

private:
	int* data_;
	int p_size_{ 0 };
	int l_size_{ 0 };
};








