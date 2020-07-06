#pragma once
#include <iostream>
using namespace std;


class Screen
{
public:
	Screen(const size_t, const size_t, const char* pc = nullptr);
	~Screen();

	const Screen& home() const {_cursor = 0; return *this; }
	Screen& home() { _cursor = 0; return *this; }

	const Screen& move() const;
	Screen& move();

	const Screen& back() const;
	Screen& back();

	const Screen& show() const;
	Screen& show();

	const Screen& move(const size_t, const size_t) const;
	Screen& move(const size_t, const size_t);

	Screen& clear();

	const Screen& showCurrent(); 

	char get() const;
	Screen& set(char);

private:
	static const size_t maxHeight;
	static const size_t maxWidth;
	static const char _filler;

	int _height;
	int _width;
	char* _wContent;
	mutable int _cursor;

	Screen(const Screen&);
	Screen& operator= (const Screen&);
};

ostream& operator<<(ostream&, const Screen&);

typedef const Screen& (Screen::* const ConstAction) () const;
typedef Screen& (Screen::* const NonConstAction) ();

void doActionConst(const Screen& s, const ConstAction act, const size_t n);
void doActionNonConst(Screen& s, NonConstAction act, const size_t n);