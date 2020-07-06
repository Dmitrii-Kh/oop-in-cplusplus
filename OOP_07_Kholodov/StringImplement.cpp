#include "String.h"
#define NDEBUG
#pragma warning(disable : 4996)

String::String() :_allocator(new char[1]), _len(0)
{
	_allocator[0] = '\0';
#ifndef NDEBUG
	cout << "'" << *this << "' created!" << endl;
#endif
	return;
}

String::String(const char* ps) {
	if (ps == 0)
		throw BadString("Attempt to use undefined pointer");

	_len = strlen(ps);
	_allocator = new char[_len + 1];
	strcpy(_allocator, ps);
#ifndef NDEBUG
	cout << "'" << *this << "' created!" << endl;
#endif
	return;
}

String::String(const char c) :_allocator(new char[2]), _len(1)
{
	_allocator[0] = c;
	_allocator[1] = '\0';
#ifndef NDEBUG
	cout << "'" << *this << "' created!" << endl;
#endif
	return;
}

String::String(const string& s) : _allocator(new char[s.length() + 1]), _len(s.length())
{
	strcpy(_allocator, s.c_str());
#ifndef NDEBUG
	cout << "'" << *this << "' created!" << endl;
#endif
	return;
}

String::String(const String& s, const unsigned int multiplier) :_len(s._len* multiplier), _allocator(new char[_len + 1]) {
	char* target = _allocator;

	for (unsigned int i = 0; i < multiplier; i++) {
		strcpy(target, s._allocator);
		target += s._len;
	}
#ifndef NDEBUG
	cout << "'" << *this << "' created!" << endl;
#endif
	return;
};

String::~String()
{
	delete[] _allocator;
	_allocator = nullptr;
#ifndef NDEBUG
	cout << "'" << *this << "' has been deleted!" << endl;
#endif
};

String& String::operator=(const String& s)
{
	if (this == &s)
		return *this;

	delete[] _allocator;
	_len = s._len;
	_allocator = new char[_len + 1];
	strcpy(_allocator, s._allocator);
	return *this;
};

String& String::operator=(const string& stl_s)
{
	delete[] _allocator;
	_len = stl_s.length();
	_allocator = new char[_len + 1];
	strcpy(_allocator, stl_s.c_str());
	//*this = String(stl_s);
	return *this;
};

String& String::operator=(const char* ps)
{
	/*if (ps == 0)
		return *this;
	delete[] _allocator;
	for (_len = 0; ps[_len]; _len++);
	_allocator = new char[_len + 1];
	strcpy(_allocator, ps);*/
	*this = String(ps);
	return *this;
}

String& String::operator=(const char c)
{
	delete[] _allocator;
	_len = 1;
	_allocator = new char[2];
	_allocator[0] = c;
	_allocator[1] = '\0';
	//*this = String(c);
	return *this;
}

char& String::operator[](const size_t i)
{
	if (_len <= i)
		throw BadIndex("Bad index: ", i);
	return _allocator[i];
};


const char String::operator[](const size_t i) const
{
	if (_len <= i)
		throw BadIndex("Bad index: ", i);
	return _allocator[i];
};




bool String::operator==(const String& s) const {
	bool equal = _len == s._len;
	for (unsigned int i = 0; (i < _len) && equal; i++)
		equal = *(_allocator + i) == *(s._allocator + i);
	return equal;
}

bool String::operator == (const string& s) const
{
	return *this == String(s);
}

bool String::operator == (const char* ps) const
{
	return *this == String(ps);
}

bool operator == (const string& stl, const String& s)
{
	return String(stl) == s;
}

bool operator == (const char* ps, const String& s)
{
	return String(ps) == s;
}




bool String::operator!=(const String& s) const
{
	return !(*this == s);
}

bool String::operator!=(const string& s) const
{
	return !(*this == s);
}

bool String::operator!=(const char* ps) const
{
	return !(*this == ps);
}

bool operator != (const string& stl, const String& s)
{
	return !(stl == s);
}

bool operator != (const char* ps, const String& s)
{
	return !(ps == s);
}




bool String::operator<(const String& s) const {
	bool res = true;
	unsigned int i = 0;

	while (res && (i < _len) && (i < s._len))
	{
		res = res && (*(_allocator + i) == *(s._allocator + i));
		i++;
	}
	if (res) return _len < s._len;
	i--;
	return *(_allocator + i) < *(s._allocator + i);
}

bool String::operator < (const string& s) const
{
	return *this < String(s);
};

bool String::operator < (const char* ps) const
{
	return *this < String(ps);
};

bool operator < (const string& stl, const String& s)
{
	return String(stl) < s;
}

bool operator < (const char* ps, const String& s)
{
	return String(ps) < s;
}




bool String::operator<=(const String& s) const
{
	if (*this == s) return true;
	return *this < s;
}

bool String::operator <= (const string& s) const {
	return *this <= String(s);
}

bool String::operator <= (const char* ps) const
{
	return *this <= String(ps);
}

bool operator <= (const string& stl, const String& s)
{
	return String(stl) <= s;
}

bool operator <= (const char* ps, const String& s)
{
	return String(ps) <= s;
}





bool String::operator > (const String& s) const
{
	return !(*this <= s);
}

bool String::operator > (const string& s) const
{
	return *this > String(s);
}

bool String::operator > (const char* ps) const
{
	return *this > String(ps);
}

bool operator > (const string& stl, const String& s)
{
	return String(stl) > s;
}

bool operator > (const char* ps, const String& s)
{
	return String(ps) > s;
}




bool String::operator >= (const String& s) const
{
	if (*this == s) return true;
	return *this > s;
}

bool String::operator >= (const string& s) const
{
	return *this >= String(s);
}

bool String::operator >= (const char* ps) const
{
	return *this >= String(ps);
}

bool operator >= (const string& stl, const String& s)
{
	return String(stl) >= s;
}

bool operator >= (const char* ps, const String& s)
{
	return String(ps) >= s;
};




String& String::operator+=(const String& s) {
	size_t len = _len + s._len;
	char* newAllocator = new char[len + 1];
	strcpy(newAllocator, _allocator);

	delete[] _allocator;
	_allocator = newAllocator;
	strcpy(_allocator + _len, s._allocator);

	_len = len;
	return *this;
}

String& String::operator+=(const char* ps) {
	if (ps == 0) return *this;
	size_t len = strlen(ps);
	char* newAllocator = new char[len + _len + 1];

	strcpy(newAllocator, _allocator);

	delete[] _allocator;
	_allocator = newAllocator;
	strcpy(_allocator + _len, ps);

	_len += len;
	return *this;
}

String& String::operator+=(const string& s)
{
	size_t len = _len + s.length();
	char* new_alloc = new char[len + 1];
	strcpy(new_alloc, _allocator);
	delete[] _allocator;
	_allocator = new_alloc;
	strcpy(_allocator + _len, s.c_str());
	_len = len;
	// return *this+=String(s);
	return *this;
};

const string& operator += (string& stl, const String& s)
{
	return stl += s.STL_string();
}



String String::operator+(const String& s) const
{
	String res(*this);
	return res += s;
}

String String::operator+(const string& s) const
{
	String res(*this);
	return res += s;
}

String String::operator+(const char* ps) const
{
	String res(*this);
	return res += ps;
}

const string operator + (const string& stl, const String& s)
{
	return stl + s.STL_string();
}



const string String::STL_string() const
{
	return string(_allocator);
};

const char* String::c_str() const
{
	return _allocator;
};

ostream& operator<<(ostream& os, const String& s)
{
	for (size_t i = 0; i < s.length(); i++) os << s[i];
	return os;
};