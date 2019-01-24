#ifndef MATRIX_H
#define MATRIX_H
class Matrix {
public:
	explicit Matrix() = default;
	explicit Matrix(const int rows, const int columns);
	Matrix(const Matrix& matr);
	~Matrix();
	Matrix operator+=(Matrix& matr2);
	Matrix operator-=(Matrix& matr2);
	Matrix& operator=(Matrix& matr2);
	int At(int row, int column);
	int GetCountRows();
	int GetCountColumns();
private:
	double** matrix_{ nullptr };
	int count_rows_{ 0 };
	int count_columns_{ 0 };

};

#endif MATRIX_H







