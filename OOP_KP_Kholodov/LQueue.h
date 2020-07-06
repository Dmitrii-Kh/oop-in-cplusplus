#pragma once
#include <cassert>

#include "List.h"
#include "Queue.h"
#include "UnlimArrayQueue.h"

template <typename T>
class LQueue : public Queue<T>
{
private:
	List<T> _qList;
public:
	explicit LQueue() = default;
	~LQueue() = default;
	bool empty() const override;
	bool full() const override;
	const T& front() const override;
	void pop() override;
	void put(const T& value) override;
	size_t capacity() const override;
	size_t size() const override;
};


template <typename T>
bool LQueue<T>::empty() const
{
	return _qList.empty();
}

template <typename T>
bool LQueue<T>::full() const
{
	return false;
}

template <typename T>
size_t LQueue<T>::capacity() const
{
	return _qList.amount();
}

template <typename T>
size_t LQueue<T>::size() const
{
	return _qList.amount();
}

template <typename T>
const T& LQueue<T>::front() const
{
	assert(!empty());
	return _qList.getLastElem();
}

template <typename T>
void LQueue<T>::pop()
{
	assert(!empty());
	_qList.del_end();
}

template <typename T>
void LQueue<T>::put(const T& value)
{
	_qList.add(value);
}
