#include<iostream>
#include <sstream>
#include "dynamic_array.h"
int main() {
	using namespace std;
	DynArray arr1;
	DynArray arr2(5);
	DynArray arr3(arr2);
	cout << "Arr2 size:" << arr2.size()<< endl;
	arr2.resize(7);
	cout << "Arr2 resize:" << arr2.size() << endl;
	for (int i = 0; i < arr2.size(); i++) {
		cin >> arr2[i];
	}
	arr3 = arr2;
	cout << "size arr3 (= arr2): " << arr3.size() << endl;
	for (int i = 0; i < arr3.size(); i++) {
		cout << arr3[i]<< endl;
	}
	//судя по всему, конструктор работает
	cout << "Hi"<< endl;
	system("pause");
}



