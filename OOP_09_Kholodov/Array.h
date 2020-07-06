#pragma once
#include <iostream>
using namespace std;

#define NDEBUG

template<size_t n, class T>
class Array
{
private:
	size_t _size;
	T* _allocator;
public:
	class BadArray;

	explicit Array();
	Array(const Array&);
	Array(Array&& source); 
	~Array();
	size_t size() const;
	T& operator[] (size_t index);
	const T& operator[](size_t index) const;
	Array& operator=(const Array&);
	Array& operator=(Array&& source);
};

template<size_t n, class T>
class Array<n, T>::BadArray
{
private:
	string _reason;
	size_t _index;
public:
	BadArray(string reason = "", size_t index = 0)
		:_reason(reason), _index(index)
	{
		return;
	};
	~BadArray() {};
	void diagnose() const
	{
		cout << _reason;
		if (_index != 0)
			cout << _index;
		cout << endl;
	}
};


template <size_t n, class T>
Array<n, T>::Array() : _size(n), _allocator(new T[_size])
{
	if (_allocator == nullptr)
		throw BadArray("No more space in the system");
	fill(*this);
	return;
}


template <size_t n, class T>
Array<n, T>::Array(const Array& a) : _size(a.size()), _allocator(new T[a.size()])
{
#ifndef NDEBUG
	cout << "I am Copy-constructor!" << endl;
#endif
	for (size_t i = 0; i < _size; ++i)
	{
		_allocator[i] = a._allocator[i];
	}
	return;
}

template <size_t n, class T>
Array<n, T>::Array(Array&& source) : _size(source.size()), _allocator(source._allocator)
{
#ifndef NDEBUG
	cout << "I am Moving constructor!" << endl;
#endif
	source._allocator = nullptr;
	return;
}

template <size_t n, class T>
Array<n, T>::~Array()
{
	delete[] _allocator;
	_allocator = nullptr;
}


template <size_t n, class T>
T& Array<n, T>::operator[](size_t index)
{
	if (index >= _size)
		throw BadArray("Index out of bounds : ", index);
	return _allocator[index];
}

template <size_t n, class T>
const T& Array<n, T>::operator[](size_t index) const
{
	if (index >= _size)
		throw BadArray("Index out of bounds : ", index);
	return _allocator[index];
}


template <size_t n, class T>
Array<n, T>& Array<n, T>::operator=(const Array& arr)
{
	if (this == &arr) return *this;

	delete[] _allocator;
	_allocator = new T[arr.size()]();

	for (size_t i = 0; i < arr.size(); ++i)
	{
		_allocator[i] = arr._allocator[i];
	}
	return *this;
}

template <size_t n, class T>
Array<n, T>& Array<n, T>::operator=(Array&& source)
{
#ifndef NDEBUG
	cout << "I am Moving assignment!" << endl;
#endif

	if (this == &source) return *this;
	_allocator = source._allocator;
	source._allocator = nullptr;
	return *this;
}

template <size_t n, class T>
bool operator==(const Array<n, T>& arr0, const Array<n, T>& arr1)
{
	bool res = true;
	if (arr0.size() != arr1.size()) return false;

	for (size_t i = 0; i < arr0.size(); ++i)
		res = res && (arr0[i] == arr1[i]);

	return res;
}

template <size_t n, class T>
bool operator!=(const Array<n, T>& arr0, const Array<n, T>& arr1)
{
	return !(arr0 == arr1);
}

template <size_t n, class T>
size_t Array<n, T>::size() const
{
	return _size;
}


template <size_t n, class T>
ostream& operator<<(ostream& os, const Array<n, T>& arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		os << arr[i] << " ";
	}
	return os;
}


template <size_t n, class T>
const T operator*(const Array<n, T>& arr0, const Array<n, T>& arr1)
{
	T res = 0;
	for (size_t i = 0; i < arr0.size(); ++i)
		res += arr0[i] * arr1[i];
	return res;
}

template <size_t n, class T>
const Array<n, T> operator+(const Array<n, T>& arr0, const Array<n, T>& arr1)
{
	Array<n, T> res;
	for (size_t i = 0; i < arr0.size(); ++i)
		res[i] = arr0[i] + arr1[i];
	return res;
}

template <size_t n, class T>
const Array<n, T> operator*(const Array<n, T>& arr0, double x)
{
	Array<n, T> res;
	for (size_t i = 0; i < arr0.size(); ++i)
		res[i] = arr0[i] * x;
	return res;
}


template <size_t n, class T>
const Array<n, T> operator*(double x, const Array<n, T>& arr0)
{
	Array<n, T> res;
	for (size_t i = 0; i < arr0.size(); ++i)
		res[i] = x * arr0[i];
	return res;
}

template<size_t n, class T>
void fill(Array<n, T>& a)
{
	for (size_t i = 0; i < a.size(); ++i)
		a[i] = 0;
}

template<size_t n, class T>
Array<n, T> create()
{
	Array<n, T> a;
	return a;
}