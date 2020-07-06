#include "Point.h"
using namespace std;
//#define NDEBUG
int Point::freeID = 0;

Point::Point(double x, double y) : _x(x), _y(y), pointID(++freeID) {
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
};

Point::Point(const Point& u) : _x(u._x), _y(u._y), pointID(++freeID) {
#ifndef NDEBUG
	cout << "Object " << *this << " created!" << endl;
#endif
	return;
};

Point::~Point() {
#ifndef NDEBUG
	cout << "Object " << *this << " has been deleted!" << endl;
#endif
	return;
}

Point& Point::operator=(const Point& u) {
	_x = u._x;
	_y = u._y;
	return *this;
}

ostream& operator<<(ostream& os, const Point& u) {
	os << "Point " << u.getID() << ": (" << u.x() << ";" << u.y() << ")";
	return os;
};

const Point operator+ (const Point& u, const Point& v) {
	return Point(u.x() + v.x(), u.y() + v.y());
};

Point& operator+=(Point& res, const Point& add) {
	res.x() += add.x();
	res.y() += add.y();
	return res;
};

bool operator==(const Point& u, const Point& v) {
	return u.x() == v.x() && u.y() == v.y();
};

bool operator!=(const Point& u, const Point& v) {
	return !(u == v);
};

const double Point::distToPoint(const Point& p) const{
	double x = p._x - _x;
	double y = p._y - _y;
	return sqrt(x * x + y * y);
}