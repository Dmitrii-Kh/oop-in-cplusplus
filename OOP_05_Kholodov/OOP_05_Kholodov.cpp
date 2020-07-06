#include "Date.h"
#include <iostream>
using namespace std;


int main()
{
	Date defaultConstructor;
	try {
		Date aa(1, 1, 2020);
		Date b(15, 15, 2020);
	}
	catch (Date::BadDate bd) {
		cout << bd << endl;
	}

	try {
		Date c(29, 2, 2021);
	}
	catch (Date::BadDate bd) {
		cout << bd << endl;
	}
	
	Date a(29, 2, 2020);
	cout << "\n=============== INCREMENTS/DECREMENTS ===============" << endl;
	cout << "date++ " << a++ << endl;
	cout << "++date " << ++a << endl;
	cout << "Result of both increments : " << a << endl;
	cout << "\n--date " << --a << endl;
	cout << "date-- " << a-- << endl;
	cout << "Result of both decrements : " << a << endl;

	cout << "\n=============== MODIFIERS ===============" << endl;
	Date b(a);
	
	try {
		b.setDay(-1);
		b.setDay(22);
	}catch(Date::BadDate bd) {
		cout << bd << endl;
	}

	try {
		b.setMonth(14);
		b.setMonth(1);
	}
	catch (Date::BadDate bd) {
		cout << bd << endl;
	}
	
	try {
		b.setDYear(-1);
		b.setDYear(20);
	}
	catch (Date::BadDate bd) {
		cout << bd << endl;
	}
	
	cout << "MODIFIED DATE : " << b << endl;

	cout << "\n=============== MODIFYING DEFAULT DATE ===============" << endl;

	try {
		Date::setDefault(-1, Date::Month(1), -1);
	}
	catch (Date::BadDate bd) {
		cout << bd << endl;
	}
	Date::setDefault(21, Date::Month(6), 2000);
	cout << "MODIFIED Default date : ";
	Date::showDefault();
	
	cout << "\n===================== ****** ====================" << endl;
	
}
