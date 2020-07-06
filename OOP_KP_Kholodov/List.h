#pragma once
template <typename ListElem>
class List {
private:
	struct ListNode;
	ListNode* _start;
	ListNode* _end;
	mutable ListNode* _current;
	mutable bool _stop;
	size_t _amount;

	List(const List&);
	List& operator=(const List&);

public:
	List();
	~List();
	bool empty() const { return _amount == 0; }
	size_t amount() const { return _amount; }

	List& add(const ListElem&);
	bool find(const ListElem&);
	List& del();
	List& del_end();
	List& del(const ListElem&);

	const List& start() const;
	const List& next() const;
	bool stop() const { return _stop; }

	const ListElem& getElem() const { return *_current->_elem; }
	const ListElem& getLastElem() const { return *_end->_elem; }
};


template <typename ListElem> struct List<ListElem>::ListNode {
	const ListElem* _elem;
	ListNode* _prev;
	ListNode* _next;
	ListNode(const ListElem& elem, ListNode* next, ListNode* prev) :
		_elem(&elem), _next(next), _prev(prev) {}
};

template <typename ListElem> List<ListElem>::List() :
	_start(0), _end(0), _current(0), _amount(0), _stop(true)
{
	return;
}

template <typename ListElem> List<ListElem>::~List() {
	if (empty()) return;
	start();
	do
		del();
	while (!stop());
}


template <typename ListElem> bool List<ListElem>::find(const ListElem& anElem) {
	if (empty()) return false;
	start();
	do {
		if (getElem() == anElem) return true;
		next();
	} while (!stop());
	return false;
}

template <typename ListElem> List<ListElem>& List<ListElem>::del(const ListElem& anElem) {
	if (find(anElem))
		del();
	return *this;
}


template <typename ListElem> List<ListElem>& List<ListElem>::del() {
	ListNode* aPrev = _current->_prev;
	ListNode* aNext = _current->_next;

	delete _current;
	_amount--;
	_current = aNext;

	if (aPrev != 0) aPrev->_next = aNext;
	else
		_start = _current;

	if (aNext != 0) aNext->_prev = aPrev;
	else _end = _current;

	_stop = _current == 0;
	return *this;
}

template <typename ListElem> List<ListElem>& List<ListElem>::del_end()
{
	ListNode* prevLast = _end->_prev;
	delete _end;
	_end = prevLast;
	assert(prevLast != nullptr);
	prevLast->_next = nullptr;
	_amount--;
	_stop = _current == 0;
	return *this;
}

template <typename ListElem> List<ListElem>& List<ListElem>::add(const ListElem& anElem) {
	if (empty())
		_start = _end = _current = new ListNode(anElem, 0, 0);
	else {
		_current = new ListNode(anElem, _start, 0);
		_start->_prev = _current; _start = _current;
	}
	_amount++;
	return *this;
}


template <typename ListElem> const List<ListElem>& List<ListElem>::start() const
{
	_current = _start;
	_stop = _current == 0;
	return *this;
}

template <typename ListElem> const List<ListElem>& List<ListElem>::next() const {
	_current = _current->_next;
	_stop = _current == 0;
	return *this;
}