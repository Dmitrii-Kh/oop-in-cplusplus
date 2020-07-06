#pragma once
#include <cassert>

#include "Queue.h"
#include "Array.h"

template <typename T>
class AQueue : public Queue<T>
{
private:
	static const size_t _default; 
	static const size_t _boq;
	size_t _size;                 
	size_t _front;                
	size_t _back;
	Array<T> * _allocator;
	size_t plus1(const size_t x);
public:
	class BadAQueue; 
	
	explicit AQueue(const size_t size = _default);
	~AQueue();
	bool empty() const override;
	bool full() const override;
	const T& front() const override;
	void pop() override;
	void put(const T& value) override;
	size_t capacity() const override;
	size_t size() const override;
};

template<class T>
class AQueue<T>::BadAQueue
{
private:
	string _reason;
	size_t _index;
public:
	BadAQueue(string reason = "", size_t index = 0)
		:_reason(reason), _index(index)
	{
		return;
	};
	~BadAQueue() = default;
	void diagnose() const
	{
		cout << _reason;
		if (_index != 0)
			cout << _index;
		cout << endl;
	}
};


template<class T>
const size_t AQueue<T>::_boq = -1;

template<class T>
const size_t AQueue<T>::_default = 100;


template<class T>
AQueue<T>::AQueue(const size_t size): _size(0), _front(0), _back(_boq), _allocator(new Array<T>(size)){}

template <typename T>
AQueue<T>::~AQueue()
{
	delete _allocator;
}

template <typename T>
size_t AQueue<T>::capacity() const
{
	return _allocator->size();
}

template <typename T>
size_t AQueue<T>::size() const
{
	return _size;
}

template <typename T>
bool AQueue<T>::empty() const
{
	return _size == 0;
}

template <typename T>
bool AQueue<T>::full() const
{
	return _size == capacity();
}

template <typename T>
const T& AQueue<T>::front() const
{
	assert(!empty());
	return (*_allocator)[_front];
}

template <typename T>
size_t AQueue<T>::plus1(const size_t x)
{
	return x < capacity() - 1 ? x + 1 : 0;
}

template <typename T>
void AQueue<T>::pop()
{
	assert(!empty()); 
	_size--;
	_front=plus1(_front); 
}

template <typename T>
void AQueue<T>::put(const T& value)
{
	if (full())
	{
		throw BadAQueue("Queue is full!");
	}
	_size++;
	_back = plus1(_back);
	(*_allocator)[_back]=value;
}
