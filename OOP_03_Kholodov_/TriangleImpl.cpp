#include "Triangle.h"
#include "T_Segment.h" 

#include <iostream>
using namespace std;

int Triangle::_freeTID = 0;

Triangle::Triangle(const double x1, const double y1,
	const double x2, const double y2,
	const double x3, const double y3) : _a(x1,y1), _b(x2,y2), _c(x3,y3), _ab(0), _bc(0), _ca(0), _myTID(++_freeTID){
#ifndef NDEBUG
	cout << "Object" << *this << " created!" << endl;
#endif
	return;

};

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : _a(a), _b(b), _c(c), _ab(0), _bc(0), _ca(0), _myTID(++_freeTID){
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
};

Triangle::Triangle(const Point& a, const Segment& bc) : _a(a), _b(bc.start()), _c(bc.end()), _ab(0), _ca(0), _myTID(++_freeTID) { 
	_bc =  new T_Segment(_b,_c);
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
};

Triangle::Triangle(const Triangle& t) : _a(t.apexA()), _b(t.apexB()), _c(t.apexC()), _ab(0), _bc(0), _ca(0), _myTID(++_freeTID) {
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
};

Triangle::~Triangle() {
	delete _ab;
	delete _bc;
	delete _ca;
	_ab = _bc = _ca = 0;
#ifndef NDEBUG
	cout << "Object " << *this << " has been deleted!" << endl;
#endif
	return;
};


const Triangle::T_Segment& Triangle::side_a() const {
	if (_bc == 0) _bc = new T_Segment(apexB(), apexC());
	return *_bc;
};

const Triangle::T_Segment& Triangle::side_b() const {
	if (_ca == 0) _ca = new T_Segment(apexC(), apexA());
	return *_ca;
};

const Triangle::T_Segment& Triangle::side_c() const {
	if (_ab == 0) _ab = new T_Segment(apexA(), apexB());
	return *_ab;
};


double Triangle::length_a() const {
	return side_a().length();
};

double Triangle::length_b() const {
	return side_b().length();
};

double Triangle::length_c() const {
	return side_c().length();
};


double Triangle::perimeter() const {
	return side_a().length() + side_b().length() + side_c().length();
};

double Triangle::area() const {
	double hP = perimeter() * 0.5;
	return sqrt(hP * (hP - length_a()) * (hP - length_b()) * (hP - length_c()));
};

Triangle& Triangle::operator= (const Triangle& t) {
	if (this == &t) return *this;
	_a = t._a; _b = t._b; _c = t._c;
	delete _ab;
	delete _bc;
	delete _ca;
	_ab = _bc = _ca = 0;
	return *this;
};

const Segment Triangle::median_a() const {
	double x = 0.5 * (side_a().startX() + side_a().endX());
	double y = 0.5 * (side_a().startY() + side_a().endY());
	return Segment(apexA(), Point(x,y));
};

const Segment Triangle::median_b() const {
	double x = 0.5 * (side_b().startX() + side_b().endX());
	double y = 0.5 * (side_b().startY() + side_b().endY());
	return Segment(apexB(), Point(x, y));
};

const Segment Triangle::median_c() const {
	double x = 0.5 * (side_c().startX() + side_c().endX());
	double y = 0.5 * (side_c().startY() + side_c().endY());
	return Segment(apexC(), Point(x, y));
};


ostream& operator<<(ostream& os, const Triangle& t) {
	os << " Triangle #" << t.getID() << " [ " << t.apexA() << 
		",  " << t.apexB() <<
		",  " << t.apexC() << " ] ";
	return os;
};

