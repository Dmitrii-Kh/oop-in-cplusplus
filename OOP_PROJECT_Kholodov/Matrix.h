#pragma once
#include <iostream>
#include <cassert>
using namespace std;

//#define NDEBUG

template <class T>
class Matrix
{
public:
	class BadMatrix;
	explicit Matrix(const size_t rows = 2, const size_t cols = 2);
	Matrix(Matrix&& other) noexcept;
	Matrix(const Matrix&);

	~Matrix();

	size_t rows() const;
	size_t cols() const;

	const T& operator()(const size_t row, const size_t col) const;
	T& operator()(const size_t row, const size_t col);


	Matrix& operator=(const Matrix&);
	Matrix& operator=(Matrix&&) noexcept;

private:
	size_t _rows;
	size_t _cols;
	T** _allocator;
};


template<class T>
class Matrix<T>::BadMatrix
{
private:
	string _reason;
	size_t _index;
public:
	BadMatrix(string reason = "", size_t index = 0)
		:_reason(reason), _index(index)
	{
		return;
	};
	~BadMatrix() {};
	void diagnose() const
	{
		cout << _reason;
		if (_index != 0)
			cout << _index;
		cout << endl;
	}
};



template <class T>
Matrix<T>::Matrix(const size_t rows, const size_t cols) : _rows(rows), _cols(cols),
_allocator(new T* [_rows])
{
	if (_allocator == nullptr)
		throw BadMatrix("No more space in the system");

	for (size_t i = 0; i < _rows; ++i)
		_allocator[i] = new T[_cols];

	fill(*this);
#ifndef NDEBUG
	cout << "Matrix created!" << endl;
#endif
	return;
}

template <class T>
Matrix<T>::Matrix(Matrix&& other) noexcept : _rows(other.rows()), _cols(other.cols()), _allocator(other._allocator)
{
	other._allocator = nullptr;
	other._rows = 0;
	other._cols = 0;
#ifndef NDEBUG
	cout << "Matrix Moving Constructor!" << endl;
#endif
	return;
}


template <class T>
Matrix<T>::~Matrix()
{
	for (size_t i = 0; i < _rows; i++)
		delete[] _allocator[i];

	delete[] _allocator;
#ifndef NDEBUG
	cout << "Matrix deleted!" << endl;
#endif
}

template <class T>
size_t Matrix<T>::rows() const
{
	return _rows;
}

template <class T>
size_t Matrix<T>::cols() const
{
	return _cols;
}


template <class T>
const T& Matrix<T>::operator()(const size_t row, const size_t col) const
{
	if (row >= rows() || col >= cols())
		throw BadMatrix("Index out of bounds!");
	return _allocator[row][col];
}

template <class T>
T& Matrix<T>::operator()(const size_t row, const size_t col)
{
	if (row >= rows() || col >= cols())
		throw BadMatrix("Index out of bounds!");
	return _allocator[row][col];
}

template <class T>
Matrix<T>::Matrix(const Matrix& m) : _rows(m.rows()), _cols(m.cols()), _allocator(new T* [_rows])
{
	if (_allocator == nullptr)
		throw BadMatrix("No more space in the system");

	for (size_t i = 0; i < _rows; i++)
		_allocator[i] = new T[_cols];

	for (size_t i = 0; i < _rows; i++)
		for (size_t j = 0; j < _cols; j++)
			_allocator[i][j] = m._allocator[i][j];

#ifndef NDEBUG
	cout << "Matrix Copied!" << endl;
#endif
	return;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m)
{
#ifndef NDEBUG
	cout << "Assignment operator call" << endl;
#endif

	if (this == &m)
	{
#ifndef NDEBUG
		cout << "< Self-assignment >" << endl;
#endif
		return *this;
	}

	for (size_t i = 0; i < rows(); i++) //free memory
		delete[] _allocator[i];
	delete[] _allocator;

	_rows = m.rows();
	_cols = m.cols();
	_allocator = new T * [_rows];

	for (size_t i = 0; i < _rows; i++)
		_allocator[i] = new T[_cols];

	for (size_t i = 0; i < _rows; i++)
		for (size_t j = 0; j < _cols; j++)
			_allocator[i][j] = m._allocator[i][j];

	return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
{
	for (size_t i = 0; i < _rows; ++i)
		delete[] _allocator[i];

	delete[] _allocator;
	_allocator = other._allocator;
	_rows = other.rows();
	_cols = other.cols();
	other._allocator = nullptr;
	other._rows = 0;
	other._cols = 0;
#ifndef NDEBUG
	cout << "Matrix Moving Assignment!" << endl;
#endif
	return *this;
}


template <class T>
const Matrix<T> operator*(const Matrix<T>& m0, const Matrix<T>& m)
{
	assert(m0.cols() == m.rows());
	Matrix<T> res(m0.rows(), m.cols());
	for (size_t i = 0; i < m0.rows(); i++)
		for (size_t j = 0; j < m.cols(); j++)
			for (size_t k = 0; k < m0.cols(); k++)
				res(i, j) += m0(i, k) * m(k, j);

	return res;
}

template <class T>
const Matrix<T> operator+(const Matrix<T>& m0, const Matrix<T>& m)
{
	assert(m0.rows() == m.rows() && m0.cols() == m.cols());
	Matrix<T> res(m0.rows(), m0.cols());
	for (size_t i = 0; i < m0.rows(); ++i)
		for (size_t j = 0; j < m0.cols(); ++j)
			res(i, j) = m0(i, j) + m(i, j);

	return res;
}

template <class T>
const Matrix<T> operator-(const Matrix<T>& m0, const Matrix<T>& m)
{
	assert(m0.rows() == m.rows() && m0.cols() == m.cols());
	Matrix<T> res(m0.rows(), m0.cols());
	for (size_t i = 0; i < m0.rows(); ++i)
		for (size_t j = 0; j < m0.cols(); ++j)
			res(i, j) = m0(i, j) - m(i, j);

	return res;
}


template <class T>
const Matrix<T> operator*(const Matrix<T>& m0, const double d)
{
	Matrix<T> res(m0.rows(), m0.cols());
	for (size_t i = 0; i < m0.rows(); ++i)
		for (size_t j = 0; j < m0.cols(); ++j)
			res(i, j) = m0(i, j) * d;
	return res;
}

template <class T>
const Matrix<T> operator*(const double d, const Matrix<T>& m)
{
	Matrix<T> res(m.rows(), m.cols());
	for (size_t i = 0; i < m.rows(); ++i)
		for (size_t j = 0; j < m.cols(); ++j)
			res(i, j) = m(i, j) * d;
	return res;
}


template <class T>
ostream& operator<<(ostream& os, const Matrix<T>& m)
{
	for (size_t i = 0; i < m.rows(); ++i) {
		for (size_t j = 0; j < m.cols(); ++j)
			os << m(i, j) << " ";
		os << endl;
	}
	return os;
};


template <class T>
const Matrix<T> transpose(const Matrix<T>& m)
{
	assert(m.rows() == m.cols());
	Matrix<T> copy(m);
	for (size_t i = 0; i < m.rows(); ++i)
		for (size_t j = i; j < m.cols(); ++j)
			std::swap(copy(i, j), copy(j, i));

	return copy;
}


template <class T>
bool operator==(const Matrix<T>& m0, const Matrix<T>& m)
{
	assert(m0.rows() == m.rows() && m0.cols() == m.cols());

	bool res = true;
	for (size_t i = 0; i < m.rows(); ++i)
		for (size_t j = 0; j < m.cols(); ++j)
			res &= m0(i, j) == m(i, j);
	
	return res;
}

template <class T>
bool operator!=(const Matrix<T>& m0, const Matrix<T>& m)
{
	return !(m0 == m);
}


template <class T>
void fill(Matrix<T>& m)
{
	for (size_t i = 0; i < m.rows(); ++i)
		for (size_t j = 0; j < m.cols(); ++j)
			m(i, j) = 0;
}

