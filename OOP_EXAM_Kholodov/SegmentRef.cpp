#include "SegmentRef.h"
#include <iostream>
using namespace std;

#define NDEBUG

int Trapezium::SegmentRef::SegmentRef::_freeID = 0;

Trapezium::SegmentRef::SegmentRef(const Point& start, const Point& end) : _a(start), _b(end), _myID(++_freeID) {
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
};

Trapezium::SegmentRef::SegmentRef(const SegmentRef& segToCopy) : _a(segToCopy._a), _b(segToCopy._b), _myID(++_freeID) {
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
}

Trapezium::SegmentRef::SegmentRef(const Segment& seg) : _a(seg.start()), _b(seg.end()), _myID(++_freeID)
{
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
};

Trapezium::SegmentRef::~SegmentRef() {
#ifndef NDEBUG
	cout << "Object " << *this << " has been deleted!" << endl;
#endif
	return;
};


ostream& operator<<(ostream& os, const Trapezium::SegmentRef& seg) {
	os << "Segment " << seg.getID() << ": [ start : " << seg.start() << "; end : " << seg.end() << " ]";
	return os;
};


double Trapezium::SegmentRef::length() const {
	double x = _b.x() - _a.x();
	double y = _b.y() - _a.y();
	return sqrt(x * x + y * y);
};


double Trapezium::SegmentRef::distance(const Point& p) const {
	double pointEnd = p.distToPoint(_b);
	double pointStart = p.distToPoint(_a);
	double startEnd = _a.distToPoint(_b);

	if (pointEnd >= sqrt(pointStart * pointStart + startEnd * startEnd)) return pointStart;
	if (pointStart >= sqrt(pointEnd * pointEnd + startEnd * startEnd)) return pointEnd;

	double halfPerimeter = 0.5 * (pointEnd + pointStart + startEnd);
	return 2 * sqrt(halfPerimeter * (halfPerimeter - pointEnd) * (halfPerimeter - pointStart) * (halfPerimeter - startEnd)) / startEnd;
};


inline double distance(const Trapezium::SegmentRef& s, const Point& p) {
	return s.distance(p);
};


Point Trapezium::SegmentRef::middlePoint() const
{
	double x = (start().x() + end().x()) * 0.5;
	double y = (start().y() + end().y()) * 0.5;
	return Point(x, y);
}


ostream& operator<<(ostream& os, const Trapezium& tr)
{
	os << "Trapezium Abstract : [ A : " << tr.apexA() << "; B : " << tr.apexB() << "; C : " << tr.apexC() << "; D : " << tr.apexD() << " ]";
	return os;
}
