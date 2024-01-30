#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {

	std::vector<std::vector<int>> matrix;
	int size_rows, size_cols;

	void check_bounds(int row, int col) const {
		if (row < 0 || col < 0 || row >= size_rows || col >= size_cols)
			throw (std::out_of_range("out_of_range"));
	}

public:

	Matrix(void) {
		Reset(0, 0);
	}

	Matrix(int num_rows, int num_cols) {
		Reset(num_rows, num_cols);
	}

	void Reset(int num_rows, int num_cols) {
		if (num_rows < 0 || num_cols < 0)
			throw (std::out_of_range("out_of_range"));
		size_cols = num_cols;
		size_rows = num_rows;
		matrix.clear();
		if (size_cols == 0 || size_rows == 0) {
			size_cols = size_rows = 0;
			return ;
		}
		matrix.resize(num_rows);
		for (int i = 0; i < num_rows; ++i) {
			matrix[i].resize(size_cols, 0);
		}
	}
	

	int At(int row, int col) const {
		check_bounds(row, col);
		return (matrix[row][col]);
	}

	int &At(int row, int col) {
		check_bounds(row, col);
		return (matrix[row][col]);
	}

	int GetNumRows(void) const {
		return (size_rows);
	}

	int GetNumColumns(void) const {
		return (size_cols);
	}


};

ostream &operator<<(ostream &out, const Matrix &m) {
	const int num_rows = m.GetNumRows();
	const int num_cols = m.GetNumColumns();
	out << num_rows << ' ' << num_cols;
	for (int i = 0; i < num_rows; ++i) {
		out << std::endl;
		for (int j = 0; j < num_cols; ++j) {
			out << m.At(i, j) << ' ';
		}
	}
	return (out);
}

istream &operator>>(istream &in, Matrix &m) {
	int num_rows, num_cols;

	in >> num_rows >> num_cols;
	m.Reset(num_rows, num_cols);
	for (int i = 0; i < num_rows; ++i) {
		for (int j = 0; j < num_cols; ++j) {
			in >> m.At(i, j);
		}
	}
	return (in);
}

Matrix operator+(const Matrix &a, const Matrix &b) {
	if (a.GetNumRows() != b.GetNumRows() || a.GetNumColumns() != b.GetNumColumns()) {
		throw (std::invalid_argument("invalid_argument"));
	}

	Matrix ans(a.GetNumRows(), a.GetNumColumns());
	for (int i = 0; i < a.GetNumRows(); ++i) {
		for (int j = 0; j < a.GetNumColumns(); ++j) {
			ans.At(i, j) = a.At(i, j) + b.At(i, j);
		}
	}
	return (ans);
}

bool operator==(const Matrix &a, const Matrix &b) {
	if (a.GetNumRows() != b.GetNumRows() || a.GetNumColumns() != b.GetNumRows())
		return (false);
	for (int i = 0; i < a.GetNumRows(); ++i) {
		for (int j = 0; j < a.GetNumColumns(); ++j) {
			if (a.At(i, j) != b.At(i, j))
				return (false);
		}
	}
	return (true);
}

int main() {
    Matrix one(4,0);
    Matrix two(0,5);   
    cout << one + two << endl;
    return 0;
}
