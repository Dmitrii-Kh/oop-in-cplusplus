#include <iostream>
#include "PointHeader.h"
using namespace std;

int main() {
	Point a(1, 1);
	Point b(2, 3);
	cout << a << endl << b << endl;
	Point zeroPoint;
	cout << "Default constructor : " << zeroPoint << endl;
	Point c(a);
	cout << "Copy-Constructor (new point(p1)): " << c << endl;
	Point assign = b;
	cout << "Assignment operator (new point = p2): " << assign << endl;

	assign.x() = 123;
	assign.y() = 321;
	cout << "Selector-modificator : " << assign << endl;
	/*const Point cPoint;
	cout << cPoint.x();   // селектор
	cPoint.x() = 1;*/     // значення атрибуту не є доступним для зміни

	cout << "\n" << a << " + " << b << " : " << a + b << endl;

	Point toAdd1(-3, 8);
	Point toAdd2(-2, 5);
	cout << "Another example of addition: " << toAdd1 << " + " << toAdd2 << " : " << toAdd1 + toAdd2 << endl;
	
	a += b;
	cout << "\nP1 += P2 : " << a << endl;

	toAdd1 += toAdd2;
	cout << "P7 += P8 : " << toAdd1 << endl;

	cout << "\nEqual / Not equal : " << endl;
	cout << boolalpha;
	c.x() = 3;
	c.y() = 4;
	cout << a << " == " << c << "(modified using modificators)" << " : " << (a == c) << endl;
	cout << a << " == " << b << " : " << (a == b) << endl;
	cout << a << " != " << b << " : " << (a != b) << endl;

	cout << "\nTotal amount of points created: " << Point::amount() << endl;

	return 0;
}

