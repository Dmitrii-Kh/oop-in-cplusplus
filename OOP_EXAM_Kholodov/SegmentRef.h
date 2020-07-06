#ifndef _SEGMENTREF_H_
#define _SEGMENTREF_H_
#include "Point.h"
#include "Trapezium.h"
#include "Segment.h"

class Trapezium::SegmentRef {
private:
	static int _freeID;
	const int _myID;
	const Point& _a;
	const Point& _b;
public:
	SegmentRef(const SegmentRef& seg);
	SegmentRef(const Segment& seg);

	SegmentRef(const Point& start, const Point& end);
	~SegmentRef();

	const Point& start() const { return _a; };
	const Point& end() const { return _b; };

	const double startX() const { return _a.x(); };
	const double startY() const { return _a.y(); };
	const double endX() const { return _b.x(); };
	const double endY() const { return _b.y(); };

	double length() const;
	double distance(const Point&) const;

	const int getID() const { return _myID; }
	SegmentRef& operator=(const SegmentRef&) = delete;
	Point middlePoint() const;

	//const SegmentRef rotateSegment(int angle) const;
	//const SegmentRef mirrorSegment(char axis) const;
};
//ostream& operator<<(ostream& os, const Trapezium::SegmentRef& seg);


inline double distance(const Trapezium::SegmentRef& s, const Point& p);
#endif