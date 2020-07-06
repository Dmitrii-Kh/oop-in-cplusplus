#pragma once
#include <iostream>
using namespace std;

//Task 7
//Developed by Dmytro Kholodov
//on 14.03.2020


class String
{
private:
	size_t _len;
	char* _allocator;

public:
	class BadString;
	class BadIndex;
	String();
	explicit String(const char*);
	String(const char);
	explicit String(const string&);
	String(const String& s, const unsigned int multiplier = 1);

	~String();

	String& operator=(const String&);
	String& operator=(const string&);  
	String& operator=(const char*);
	String& operator=(const char);

	const string STL_string() const;
	const char* c_str() const;
	size_t length() const { return _len; };

	bool isEmpty() const { return _len == 0; };
	void clear() { *this = String(); };

	char& operator[](const size_t);
	const char operator[](const size_t) const;

	bool operator == (const String&) const;
	bool operator == (const string&) const;
	bool operator == (const char*) const;

	bool operator != (const String&) const;
	bool operator != (const string&) const;
	bool operator != (const char*) const;

	bool operator < (const String&) const;
	bool operator < (const string&) const;
	bool operator < (const char*) const;

	bool operator <= (const String&) const;
	bool operator <= (const string&) const;
	bool operator <= (const char*) const;

	bool operator > (const String&) const;
	bool operator > (const string&) const;
	bool operator > (const char*) const;

	bool operator >= (const String&) const;
	bool operator >= (const string&) const;
	bool operator >= (const char*) const;

	String operator+(const String&) const;
	String operator+(const string&) const;
	String operator+(const char*) const;

	String& operator+=(const char*);
	String& operator+=(const String&);
	String& operator+=(const string&);   
};

ostream& operator<<(ostream&, const String&);

class String::BadString {

private:
	const string _reason;
	const size_t _index;

public:
	BadString(string reason = "Bad String", const size_t index = 0) : _reason(reason), _index(index)
	{
		return;
	}
	~BadString() {}

	void diagnose() const
	{
		cerr << _reason << endl;
		if (_index != 0)
			cerr << ' ' << _index << endl;
	}
};

class String::BadIndex {

private:
	const string _reason;
	const size_t _index;

public:
	BadIndex(string reason = "Bad Index", const size_t index = 0) : _reason(reason), _index(index)
	{
		return;
	}
	~BadIndex() {}

	void diagnose() const
	{
		cerr << _reason;
		if (_index != 0)
			cerr << ' ' << _index << endl;
	}
};


bool operator == (const string&, const String&);
bool operator == (const char*, const String&);

bool operator != (const string&, const String&);
bool operator != (const char*, const String&);

bool operator < (const string&, const String&);
bool operator < (const char*, const String&);

bool operator <= (const string&, const String&);
bool operator <= (const char*, const String&);

bool operator > (const string&, const String&);
bool operator > (const char*, const String&);

bool operator >= (const string&, const String&);
bool operator >= (const char*, const String&);

const string operator + (const string&, const String&);
const string& operator += (string&, const String&);
