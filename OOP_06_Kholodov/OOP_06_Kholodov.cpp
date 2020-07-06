#include "Time.h"
#include <ctime>
#include <iostream>
using namespace std;

#pragma warning(disable : 4996)

int main()
{
	
	cout << "\n================= +operator & setters =================" << endl;

	Time t2(0, 59, 60);
	Time t3(t2);
	t3.minutes() = 30;
	cout << "Modified Time object : " << t3 << endl;
	
	cout << t2 << " + " << t3 << " : " << t2 + t3 << endl;

	t2.hours() = 2;
	cout << "\nModified Time object : " << t2 << endl;

	cout << t2 << " + " << t3 << " : " << t2 + t3 << endl;

	cout << "\n================= More setters & getters ===================" << endl;

	Time t4 = t2;
	t4.minutes() = 59;
	t4.seconds() = 59;
	cout << "Modified object : " << endl;
	cout << t4 << " hours : " << t4.hours() << endl;
	cout << t4 << " minutes : " << t4.minutes() << endl;
	cout << t4 << " seconds : " << t4.seconds() << endl;
	
	cout << "\n=================== Increments & Decrements ================" << endl;
	cout << "++" << t4 << " : ";
	cout << ++t4 << endl;

	cout << t4 << "++" << " : ";
	cout << t4++ << endl;

	cout << "Previous object after both increments : " << t4 << endl;

	cout << "\n--" << t4 << " : ";
	cout << --t4 << endl;

	cout << t4 << "--" << " : ";
	cout << t4-- << endl;

	cout << "Previous object after both decrements : " << t4 << endl;
	
	cout << "\n=================== TIMER TESTING ===================" << endl;
	time_t timer;
	time(&timer);
	struct tm* today = gmtime(&timer);

	Date d(today->tm_mday, ++today->tm_mon, today->tm_year + 1900);
	Time t(today->tm_hour + 2, today->tm_min, today->tm_sec + 3);   //timer starts in 3 seconds 
	Time interval(0, 0, 5);

	Timer(d, t, interval);

	cout << "\n============================================================" << endl;
	return 0;
}

