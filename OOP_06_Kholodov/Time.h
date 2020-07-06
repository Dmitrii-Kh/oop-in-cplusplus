#pragma once
#include <iostream>
#include "Date.h"

//---------------------------------------
//1. Реалізувати клас Time
//
//2. Реалізувати таймер, який вмикається
//вибраного дня (клас Date) в заданий час
//і подає сигнал через заданий інтервал
//часу після вмикання
//---------------------------------------

//Task 6
//Developed at 05.03.2020
//by Dmytro Kholodov

class Time
{
private:
	int _hours;
	int _minutes;
	int _seconds;
	
	void normalizeTime();

public:
	static const double hourToDec;
	Time(const unsigned int h, const unsigned int m, const unsigned int s);
	Time(const Time&);
	~Time();

	Time& operator=(const Time&);
	operator unsigned int() const;
	operator double() const;

	int hours() const { return _hours; }
	int minutes() const { return _minutes; }
	int seconds() const { return _seconds; }

	int& hours();
	int& minutes();
	int& seconds();

	const Time& operator++();
	const Time operator++(int);
	const Time& operator--();
	const Time operator--(int);
};

double operator+ (const Time&, const Time&);
double operator- (const Time&, const Time&);

std::ostream& operator<<(std::ostream&, const Time&);

void Timer(const Date&, const Time&, Time&);