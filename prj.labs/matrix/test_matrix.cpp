#include"matrix.h"
#include <iostream>
int main() {
	Matrix matr1(2,6);
	Matrix matr9(matr1);
    using namespace std;
	cout << matr9.GetCountColumns() << "  " << matr9.GetCountRows()<<endl;
	//cout << matr1.At(1,2)<< endl;
	matr9 = matr1;
	
	std::cout << matr1.GetCountColumns()<<" "<< matr1.GetCountRows() <<endl;
	std::cout << matr9.At(1,1) << " " ;

}