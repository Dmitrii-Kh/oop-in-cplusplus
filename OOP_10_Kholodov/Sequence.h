#pragma once
#include <cassert>
#include <iostream>
#include "Array.h"
using namespace std;

template <class Elem>
class Sequence {
public:
	class BadSeq;
	explicit Sequence(const size_t capacity = _default);
	~Sequence();
	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	bool full() const;
	Sequence& clear();
	const Elem& operator[](const size_t index) const;
	Elem& operator[](const  size_t index);
	Sequence& add(const Elem& elem);
	Sequence& insert(const Elem& elem, const  size_t index);
	Sequence& cut();
	Sequence& remove(const size_t index);
	bool contains(const Elem& elem);

	Sequence(const Sequence&) = delete;
	Sequence& operator=(const Sequence&) = delete;
private:
	size_t _size;
	static const size_t _default;
	Array<Elem>* _allocator;
	void reduce(const size_t times = 2);
	void enlarge(const size_t times = 2);
	Sequence& doinsert(const Elem& elem, const size_t index);
	Sequence& doremove(const size_t index);
};


template<class Elem>
class Sequence<Elem>::BadSeq
{
private:
	string _reason;
	size_t _index;
public:
	BadSeq(string reason = "", size_t index = 0)
		:_reason(reason), _index(index)
	{
		return;
	};
	~BadSeq() {};
	void diagnose() const
	{
		cout << _reason;
		if (_index != 0)
			cout << _index;
		cout << endl;
	}
};


template <class Elem>
const size_t Sequence<Elem>::_default = 10;


template <class Elem>
Sequence<Elem>::Sequence(const size_t capacity) : _size(0), _allocator(new Array<Elem>(capacity))
{
#ifndef NDEBUG
	cout << "Seq created!" << endl;
#endif
}

template <class Elem>
Sequence<Elem>::~Sequence()
{
	delete _allocator;
#ifndef NDEBUG
	cout << "Seq deleted!" << endl;
#endif
}

template <class Elem>
size_t Sequence<Elem>::capacity() const
{
	return _allocator->size();
}

template <class Elem>
size_t Sequence<Elem>::size() const
{
	return _size;
}

template <class Elem>
bool Sequence<Elem>::empty() const
{
	return size() == 0;
}

template <class Elem>
bool Sequence<Elem>::full() const
{
	return size() == capacity();
}

template <class Elem>
std::ostream& operator<<(std::ostream& os, const Sequence<Elem>& seq)
{
	os << "[";
	for (size_t i = 0; i < seq.size(); ++i)
		os << seq[i] << (i == seq.size() - 1 ? "]" : ", ");
	if (seq.empty()) os << "empty]";
	return os;
};

template <class Elem>
Sequence<Elem>& Sequence<Elem>::clear()
{
	_size = 0;
	return *this;
}

template <class Elem>
const Elem& Sequence<Elem>::operator[](const size_t index) const {
	if (empty())
		throw BadSeq("Try to manipulate the empty sequence");
	if (index >= _size)
		throw BadSeq("Try to access a non existing element of the sequence");
	return (*_allocator)[index];
}

template <class Elem>
Elem& Sequence<Elem>::operator[](const size_t index)
{
	if (empty())
		throw BadSeq("Try to manipulate the empty sequence");
	if (index >= _size)
		throw BadSeq("Try to access a non existing element of the sequence");
	return (*_allocator)[index];
}





template <class Elem>
void Sequence<Elem>::reduce(const size_t times)
{
	assert(capacity() >= times * size());
	Array<Elem>* newArray = new Array<Elem>(capacity() / times);
	for (size_t i = 0; i < size(); i++)
		(*newArray)[i] = (*_allocator)[i];

	delete _allocator;
	_allocator = newArray;
#ifndef NDEBUG
	cout << "Sequence reduced!" << endl;
#endif

}

template <class Elem>
void Sequence<Elem>::enlarge(const size_t times)
{
	Array<Elem>* newArray = new Array<Elem>(times * _default + capacity() + 1);
	for (size_t i = 0; i < size(); i++)
		(*newArray)[i] = (*_allocator)[i];

	delete _allocator;
	_allocator = newArray;
#ifndef NDEBUG
	cout << "Sequence enlarged!" << endl;
#endif
}





template <class Elem>
Sequence<Elem>& Sequence<Elem>::doinsert(const Elem& elem, const size_t index)
{
	assert(index <= _size);
	if (_size + 1 > capacity()) enlarge(); ++_size;

	for (size_t i = _size - 1; i > index; i--)
		(*_allocator)[i] = (*_allocator)[i - 1];

	(*_allocator)[index] = elem;
	return *this;
}

template <class Elem>
Sequence<Elem>& Sequence<Elem>::add(const Elem& elem)
{
	return doinsert(elem, _size);
}

template <class Elem>
Sequence<Elem>& Sequence<Elem>::insert(const Elem& elem, const size_t index)
{
	if (_size < index) throw BadSeq(
		"Try to insert after a non existing element of the sequence");
	return doinsert(elem, index);
}




template <class Elem>
Sequence<Elem>& Sequence<Elem>::doremove(const size_t index)
{
	assert(index <= _size);
	if (empty())
		throw BadSeq("Try to manipulate the empty sequence");
	--_size;
	for (size_t i = index; i < _size; ++i)
		(*_allocator)[i] = (*_allocator)[i+1];
	if (size() < capacity() / 2) reduce();
	return *this;
}


template <class Elem>
Sequence<Elem>& Sequence<Elem>::cut()
{
	return doremove(0);
}

template <class Elem>
Sequence<Elem>& Sequence<Elem>::remove(const size_t index)
{
	if ((_size < index) || (index == 0))
		throw BadSeq("Try to delete a non existing element of the sequence");
	return doremove(index);
}



template <class Elem>
bool Sequence<Elem>::contains(const Elem& elem)
{
	for (size_t i = 0; i < size(); i++)
		if ((*_allocator)[i] == elem) return true;
	return false;
}


