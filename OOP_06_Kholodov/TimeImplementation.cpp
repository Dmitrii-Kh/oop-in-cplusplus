#include "Time.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
using namespace std;

#pragma warning(disable : 4996)

const double Time::hourToDec = 1. / 3600.;

Time::Time(const unsigned int h, const unsigned int m, const unsigned int s) : _hours(h), _minutes(m), _seconds(s)
{
	normalizeTime();
#ifndef NDEBUG
	cout << *this << " created!" << endl;
#endif
	return;
}

Time::Time(const Time& t) : _hours(t._hours), _minutes(t._minutes), _seconds(t._seconds)
{
#ifndef NDEBUG
	cout << *this << " created!" << endl;
#endif
	return;
}

Time::~Time()
{
#ifndef NDEBUG
	cout << *this << " has been deleted!" << endl;
#endif
};

Time& Time::operator=(const Time& t)
{
	_hours = t._hours;
	_minutes = t._minutes;
	_seconds = t._seconds;

	return *this;
}

void Time::normalizeTime() {
	int t = static_cast<unsigned int>(*this);
	_hours = t / 60 / 60;
	_minutes = t / 60 % 60;
	_seconds = t % 60;
}

int& Time::hours()
{
	return _hours;
}

int& Time::minutes()
{
	return _minutes;
}

int& Time::seconds()
{
	return _seconds;
}

Time::operator unsigned int() const
{
	return _hours * 3600 + _minutes * 60 + _seconds;
}

Time::operator double() const
{
	double minutes = _minutes + 59. / _seconds;
	return _hours + 59. / minutes;
}


const Time& Time::operator++()
{
	++seconds();
	normalizeTime();
	return *this;
};

const Time Time::operator++(int)
{
	const Time res(*this);
	++* this;
	return res;
};


const Time& Time::operator--()
{
	--seconds();
	normalizeTime();
	return *this;
};

const Time Time::operator--(int)
{
	const Time res(*this);
	--* this;
	return res;
};


double operator+(const Time& t1, const Time& t2)
{
	return unsigned int(t1) * Time::hourToDec + unsigned int(t2) * Time::hourToDec;
};

double operator-(const Time& t1, const Time& t2)
{
	return unsigned int(t1) * Time::hourToDec - unsigned int(t2) * Time::hourToDec;
};


ostream& operator<<(ostream& os, const Time& t)
{
	os << "(" << t.hours() << ":" << t.minutes() << ":" << t.seconds() << ")";
	return os;
}

void Timer(const Date& d, const Time& t, Time& interval)
{
	if (t.hours() >= 24 || t.hours() < 0)
	{
		cout << "Invalid time format!" << endl;
		return;
	}

	time_t timer;
	time(&timer);
	struct tm* today = gmtime(&timer);


	if (today->tm_year + 1900 > d.year())
	{
		cout << "> Start year in past ! <" << endl;
		return;
	}
	else if ((today->tm_year + 1900 == d.year()) && ++today->tm_mon > d.month())
	{
		cout << "> Start month in past ! <" << endl;
		return;
	}
	else if (today->tm_year + 1900 == d.year() && today->tm_mon == d.month() && today->tm_mday > d.day())
	{
		cout << "> Start day in past ! <" << endl;
		return;
	}

	if (today->tm_year + 1900 == d.year() && today->tm_mon == d.month() && today->tm_mday == d.day())
	{
		Time now(today->tm_hour + 2, today->tm_min, today->tm_sec);
		if (now - t > 0)
		{
			cout << "> Start time in past ! <" << endl;
			return;
		}
	}
	
	--today->tm_mon; //should decrement it, because of incrementation in if-statement, line 144;

	cout << "\nTimer will start on : " << d << " | At : " << t << endl;
	
	while (today->tm_year + 1900 != d.year() ||
		++today->tm_mon != d.month() ||
		today->tm_mday != d.day() ||
		(today->tm_hour + 2) != t.hours() ||
		today->tm_min != t.minutes() ||
		today->tm_sec != t.seconds())
	{
		time(&timer);
		today = gmtime(&timer);

		this_thread::sleep_for(chrono::seconds(1));

	  /*cout << today->tm_sec << endl;
		cout << t.seconds() << endl;*/

	#ifndef NDEBUG
		cout << "...waiting for the timer to start..." << endl;
	#endif
	}

	cout << "\nThe timer has started!" << endl;
	cout << "Interval : " << static_cast<unsigned int>(interval) << " seconds" << endl;

	while (interval.hours() != 0 || interval.minutes() != 0 || interval.seconds() != 0) {
		--interval;

	#ifndef NDEBUG
		cout << interval << " left" << endl;
	#endif

		this_thread::sleep_for(chrono::seconds(1));
	}

	cout << "\007" << "\n> TIME IS UP <" << endl;
};