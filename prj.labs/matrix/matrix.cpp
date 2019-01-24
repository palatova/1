#include"matrix.h"
#include<iostream>
#include"stdexcept"
Matrix::Matrix(const int rows, const int columns) {
	//в конструкторе учитываем, что строки и столбцы не могут быть меньше нуля
	if ((rows < 0) || (columns < 0))
	{
		//throw std::invalid_argument("Please,No!!!");
		std::cout << "Rows or columns less than 0";
	}
	else {
		matrix_ = new double*[rows];
		count_columns_ = columns;
		count_rows_ = rows;
		for (int i = 0; i < rows; i++) {
			matrix_[i] = new double[count_columns_];
			for (int j = 0; j < count_columns_; j++) {
				matrix_[i][j] = 0;
			}
		}

	}


};

Matrix::Matrix(const Matrix& matr)
{
	 matrix_ = new double*[matr.count_rows_];
	 count_columns_ = matr.count_columns_;
	 count_rows_ = matr.count_rows_;
	for (int i = 0; i < count_rows_;i++) 
	{
      matrix_[i] = new double[matr.count_columns_];
		for (int j = 0; j < count_columns_; j++)
		{
			matrix_[i][j] = matr.matrix_[i][j];
        }

	}

};
//учесть все баги отрицательные индексы+ выходящие за границу матричных
int Matrix::At( int row, int column) {
if((row<0)||(row>count_rows_)||(column<0)||(count_columns_<column)) throw std::invalid_argument("!!");
	return matrix_[row][column];
}

Matrix& Matrix::operator=(Matrix& matr2) {
	if (this != &matr2) {
		if ((count_columns_ >= matr2.count_columns_) || (count_rows_ >= matr2.count_rows_))
		{
			for (int i = 0; i < count_rows_; i++)
			{
				matrix_[i] = new double[count_columns_];
				for (int j = 0; j < count_columns_; j++)
				{
					matrix_[i][j] = matr2.matrix_[i][j];
				}
			}
			count_columns_ = matr2.count_columns_;
			count_rows_ = matr2.count_rows_;
		}
		else {
			double** matr = new double*[matr2.count_rows_];

			for (int i = 0; i < count_rows_; i++)
			{
				matrix_[i] = new double[count_columns_];
				for (int j = 0; j < count_columns_; j++)
				{
					matr[i][j] = matr2.matrix_[i][j];
				}
			}
			for (int i = 0; i < count_rows_; i++) {
				delete[] matrix_[i];
			}
			delete[] matrix_;
			matrix_ = matr;
			delete[] matr;

		}
	}
	return *this;
}

	


Matrix::~Matrix()
{
	for (int i = 0; i < count_rows_; i++) {
		delete[] matrix_[i];
	}
	delete[] matrix_;
	count_columns_ = 0;
	count_rows_ = 0;
}
int Matrix::GetCountColumns() {
	return count_columns_;
}
int Matrix::GetCountRows() {
	return count_rows_;
}



