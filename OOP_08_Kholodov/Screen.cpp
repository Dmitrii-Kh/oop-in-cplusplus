#include "Screen.h"

const size_t Screen::maxHeight = 24;
const size_t Screen::maxWidth = 80;
const char Screen::_filler = '.';

Screen::Screen(const size_t  m, const size_t  n, const char* s) :
	_width(m > maxWidth ? maxWidth : m),
	_height(n > maxHeight ? maxHeight : n),
	_wContent(new char[_height * _width + 1]),
	_cursor(0)
{
	size_t lens = s == 0 ? 0 : strlen(s);
	size_t len = lens > _height* _width ? _height * _width : lens;

	_wContent[_height * _width] = '\0';
	size_t k = 0;

	if (s != 0)
		for (; k < len; k++)
			*(_wContent + k) = *s++;
	for (; k < _height * _width; k++)
		*(_wContent + k) = _filler;
}

Screen::~Screen()
{
	delete[] _wContent;
}

const Screen& Screen::move() const
{
	if ((++_cursor) >= _width * _height) _cursor = 0;
	return *this;
}

Screen& Screen::move()
{
	if ((++_cursor) >= _width * _height) _cursor = 0;
	return *this;
}

const Screen& Screen::back() const
{
	if (--_cursor < 0) _cursor = 0;
	return *this;
}

Screen& Screen::back()
{
	if (--_cursor < 0) _cursor = 0;
	return *this;
}

const Screen& Screen::show() const
{
	size_t  cursor = _cursor;
	cout << "\ncursor=" << _cursor << endl<<endl;
	home();
	
	for (size_t i = 0; i < _height; i++) {
		for (size_t j = 0; j < _width; j++)
		{
			cout << get();
			move();
		}
		cout << endl;
	}
	_cursor = cursor;
	return *this;
}


Screen& Screen::show()
{
	size_t  cursor = _cursor;
	cout << "\ncursor=" << _cursor << endl <<endl;
	home();

	for (size_t i = 0; i < _height; i++) {
		for (size_t j = 0; j < _width; j++)
		{
			cout << get();
			move();
		}
		cout << endl;
	}
	_cursor = cursor;
	return *this;
}


const Screen& Screen::move(const size_t  i, const size_t  j) const
{ 
	if((i>=_height)||(j>=_width)) _cursor=0;
	else _cursor=_width*i+j;
	return *this;
}


Screen& Screen::move(const size_t  i, const size_t  j) 
{
	if ((i >= _height) || (j >= _width)) _cursor = 0;
	else _cursor = _width * i + j;
	return *this;
}

Screen& Screen::clear() 
{
	for (size_t  i = 0; i < _height * _width; i++)
		*(_wContent + i) = _filler;
	_cursor = 0;
	return *this;
}

char Screen::get() const
{
	return *(_wContent + _cursor);
}


Screen& Screen::set(char a)
{
	*(_wContent + _cursor) = a;
	return *this;
}

void doActionConst(const Screen& s, const ConstAction act, const size_t n)
{
	for (size_t  i = 0; i < n; i++) (s.*act)();
}

void doActionNonConst(Screen& s, NonConstAction act, const size_t n)
{
	for(size_t  i=0; i<n; i++) (s.*act)();
}


ostream& operator<<(ostream& os, const Screen& s)
{
	s.show();
	return os;
}

const Screen& Screen::showCurrent()
{
	cout << get();
	return *this;
}
