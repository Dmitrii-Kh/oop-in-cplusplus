#pragma once
#include <cassert>
#include "Queue.h"
#include "Array.h"

template <typename T>
class UnlimArrayQueue : public Queue<T>
{
private:
	static const size_t _default;
	static const size_t _boq;
	size_t _size;
	size_t _front;
	size_t _back;
	Array<T>* _allocator;
	size_t plus1(const size_t x);
	void enlarge(const size_t times = 2);
public:

	explicit UnlimArrayQueue(const size_t size = _default);
	~UnlimArrayQueue();
	bool empty() const override;
	bool full() const override;
	const T& front() const override;
	void pop() override;
	void put(const T& value) override;
	size_t capacity() const override;
	size_t size() const override;
};


template<class T>
const size_t UnlimArrayQueue<T>::_boq = -1;

template<class T>
const size_t UnlimArrayQueue<T>::_default = 100;


template<class T>
UnlimArrayQueue<T>::UnlimArrayQueue(const size_t size) : _size(0), _front(0), _back(_boq), _allocator(new Array<T>(size)) {}

template <typename T>
UnlimArrayQueue<T>::~UnlimArrayQueue()
{
	delete _allocator;
}

template <typename T>
size_t UnlimArrayQueue<T>::capacity() const
{
	return _allocator->size();
}

template <typename T>
size_t UnlimArrayQueue<T>::size() const
{
	return _size;
}

template <typename T>
bool UnlimArrayQueue<T>::empty() const
{
	return _size == 0;
}

template <typename T>
bool UnlimArrayQueue<T>::full() const
{
	return _size == capacity();
}

template <typename T>
const T& UnlimArrayQueue<T>::front() const
{
	assert(!empty());
	return (*_allocator)[_front];
}

template <typename T>
size_t UnlimArrayQueue<T>::plus1(const size_t x)
{
	return x < capacity() - 1 ? x + 1 : 0;
}

template <typename T>
void UnlimArrayQueue<T>::pop()
{
	assert(!empty());
	_size--;
	_front = plus1(_front);
}

template <typename T>
void UnlimArrayQueue<T>::put(const T& value)
{
	if (full())
	{
		enlarge();
		cout << "Space Enlarged successfully!" << endl;
	}
	
	_size++;
	_back = plus1(_back);
	(*_allocator)[_back] = value;
}

template <typename T>
void UnlimArrayQueue<T>::enlarge(const size_t times)
{
	Array<T>* newArray = new Array<T>(times * _default + capacity() + 1);
	for (size_t i = 0; i < _size; i++)
		(*newArray)[i] = (*_allocator)[i];
	delete _allocator; 
	_allocator = newArray;
}







