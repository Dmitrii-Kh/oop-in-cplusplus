#include "T_Segment.h"
#include <iostream>
using namespace std;
//#define NDEBUG
int Triangle::T_Segment::T_Segment::_freeID = 0;

//Segment::Segment(const double x1, const double y1,
//	const double x2, const double y2) : _a(x1, y1), _b(x2, y2), _myID(++_freeID) {
//#ifndef NDEBUG
//	cout << "Object " << *this << " created!" << endl;
//#endif
//	return;
//};

Triangle::T_Segment::T_Segment(const Point& start, const Point& end) : _a(start), _b(end), _myID(++_freeID) {
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
};

Triangle::T_Segment::T_Segment(const T_Segment& segToCopy) : _a(segToCopy._a), _b(segToCopy._b), _myID(++_freeID) {
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
};

Triangle::T_Segment::~T_Segment() {
#ifndef NDEBUG
	cout << "Object " << *this << " has been deleted!" << endl;
#endif
	return;
};

//Segment& Segment::operator=(const Segment& seg) {
//	_a = seg._a;
//	_b = seg._b;
//	return *this;
//};


ostream& operator<<(ostream& os, const Triangle::T_Segment& seg) {
	os << "T_Segment " << seg.getID() << ": [ start : " << seg.start() << "; end : " << seg.end() << " ]";
	return os;
};


double Triangle::T_Segment::length() const {
	double x = _b.x() - _a.x();
	double y = _b.y() - _a.y();
	return sqrt(x * x + y * y);
};


double Triangle::T_Segment::distance(const Point& p) const {
	double pointEnd = p.distToPoint(_b);
	double pointStart = p.distToPoint(_a);
	double startEnd = _a.distToPoint(_b);

	if (pointEnd >= sqrt(pointStart * pointStart + startEnd * startEnd)) return pointStart;
	if (pointStart >= sqrt(pointEnd * pointEnd + startEnd * startEnd)) return pointEnd;

	double halfPerimeter = 0.5 * (pointEnd + pointStart + startEnd);
	return 2 * sqrt(halfPerimeter * (halfPerimeter - pointEnd) * (halfPerimeter - pointStart) * (halfPerimeter - startEnd)) / startEnd;
};

//Heron formulà + (S = 0.5*basement*height)


double distance(const Triangle::T_Segment& s, const Point& p) {
	return s.distance(p);
};




