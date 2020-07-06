#include "Date.h"
#include <iostream>
#include <ctime>
using namespace std;

#pragma warning(disable : 4996)

string Date::monthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
								"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
bool Date::defaultSet = false;
Date Date::defaultDate;
int Date::_freeID = 0;

Date::Date(int d, Month m, int y) : _id(++_freeID){
	fillDate(d, m, y);
	return;
};

Date::Date(int d, int m, int y) : _id(++_freeID) {
	fillDate(d, Month(m), y);
	return;
};

Date::Date(const Date& date) : _day(date.day()), _month(date.month()), _year(date.year()), _id(++_freeID)
{
#ifndef NDEBUG
	cout << *this << " copied!" << endl;
#endif
	return;
}

Date::~Date() {
#ifndef NDEBUG
	cout << *this << " has been deleted!" << endl;
#endif
};


void Date::verifyDate(int _day, int _month, int _year)
{
	int numberOfDays = 0;
	switch (_month) {
	case Feb: numberOfDays = 28 + leapYear(_year);
		break;
	case Apr: case Jun: case Sep: case Nov: numberOfDays = 30;
		break;
	case Jan: case Mar: case May: case Jul: case Aug: case Oct: case Dec: numberOfDays = 31;
		break;
	default: throw BadDate(_day, _month, _year);
	}

	if ((_day < 1) || (numberOfDays < _day) || (_year < 0))
		throw BadDate(_day, _month, _year);
}

void Date::setDay(int day)
{
	verifyDate(day, _month, _year);
	_day = day;
}

void Date::setMonth(int month)
{
	verifyDate(_day, month, _year);
	_month = month;
}

void Date::setDYear(int year)
{
	verifyDate(_day, _month, year);
	_year = year;
}

void Date::fillDate(int d, Month m, int y) {
	if (!defaultSet) {
		setDefault();
		#ifndef NDEBUG
			cout << "Data constructor _defaultDate: " << *this << endl;
		#endif
	}

	_day = d ? d : defaultDate._day;
	_month = m ? m : defaultDate._month;
	_year = y ? y: defaultDate._year; 

	verifyDate(_day, _month, _year);

#ifndef NDEBUG
	cout << "Data constructor: " << *this << " created!" << endl;
#endif
};

void Date::setDefault(int d, Month m, int y)
{
	defaultDate = Date(d, m, y);
	defaultSet = true;
};

void Date::setDefault()
{
	time_t timer;
	time(&timer); 
	struct tm * today = gmtime(&timer);
	
	defaultDate._day=today->tm_mday;
	defaultDate._month=++(today->tm_mon);
	defaultDate._year=today->tm_year+=1900;
	defaultSet = true;
};


void Date::showDefault() {
	cout << defaultDate << endl;
};

bool Date::leapYear(int year) {
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

ostream& operator<<(ostream& os, const Date& d) {
	os << "Date #" << d.getID() <<"  "<< d.day() << "/" << d.getMonthName() << "/" << d.year();
	return os;
};

ostream& operator<<(ostream& os, const Date::BadDate& bd) {
	os << ">BadDate<  Day : " << bd._day << " | Month : " << bd._month << " | Year : " << bd._year;
	return os;
};


void Date::valiDate()
{
	int numOfDays = 0;
	switch (_month) {
	case Feb: numOfDays = 28 + leapYear(_year);
		break;
	case Apr: case Jun: case Sep: case Nov: numOfDays = 30;
		break;
	case Jan: case Mar: case May: case Jul: case Aug: case Oct: case Dec: numOfDays = 31;
		break;
	}
	
	if (_day > numOfDays) {
		_day = 1;
		_month++;
	}
	if (_month > 12)
	{
		_month = 1;
		_year++;
	}

	if (_day < 1) {
		_month--;
		
		if (_month == 2) 
			_day = 28 + leapYear(_year);
		else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) 
			_day = 30;
		else 
			_day = 31;
	}
	
	if (_month < 1)
	{
		_month = 12;
		_year--;
	}
}

const Date& Date::operator++()
{
	_day++;
	valiDate();
	return *this;
};

const Date& Date::operator--()
{
	_day--;
	valiDate();
	return *this;
};

const Date Date::operator++(int)
{
	Date cpy = *this;
	++*this;
	return cpy;
};

const Date Date::operator--(int)
{
	Date cpy = *this;
	--* this;
	return cpy;
};

