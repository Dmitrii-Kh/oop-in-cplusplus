#pragma once
#pragma once
#pragma once
#include <iostream>
using namespace std;

template<class T>
class Array
{
private:
	size_t _size;
	T* _allocator;
public:
	class BadArray;

	explicit Array(const size_t n);
	Array(const Array&);
	~Array();

	size_t size() const;
	bool isEmpty() const;

	T& operator[] (size_t index);
	const T& operator[](size_t index) const;
	Array& operator=(const Array&);
};

template<class T>
class Array<T>::BadArray
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


template <class T>
Array<T>::Array(const size_t n) : _size(n), _allocator(new T[_size])
{
	if (_allocator == nullptr)
		throw BadArray("No more space in the system");
	return;
}


template <class T>
Array<T>::Array(const Array& a) : _size(a.size()), _allocator(new T[a.size()])
{
	for (size_t i = 0; i < _size; ++i)
	{
		_allocator[i] = a._allocator[i];
	}
	return;
}

template <class T>
Array<T>::~Array()
{
	delete[] _allocator;
	_allocator = nullptr;
}

template <class T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw BadArray("Index out of bounds : ", index);
	return _allocator[index];
}

template <class T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw BadArray("Index out of bounds : ", index);
	return _allocator[index];
}


template <class T>
Array<T>& Array<T>::operator=(const Array& arr)
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

template <class T>
bool operator==(const Array<T>& arr0, const Array<T>& arr1)
{
	bool res = true;
	if (arr0.size() != arr1.size()) return false;

	for (size_t i = 0; i < arr0.size(); ++i)
		res = res && (arr0[i] == arr1[i]);

	return res;
}

template <class T>
bool operator!=(const Array<T>& arr0, const Array<T>& arr1)
{
	return !(arr0 == arr1);
}

template <class T>
size_t Array<T>::size() const
{
	return _size;
}

template <class T>
bool Array<T>::isEmpty() const
{
	return _size == 0;
}

template <class T>
ostream& operator<<(ostream& os, const Array<T>& arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		os << arr[i] << " ";
	}
	return os;
}

