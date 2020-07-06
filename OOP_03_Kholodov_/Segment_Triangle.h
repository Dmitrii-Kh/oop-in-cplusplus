#pragma once
#include "triangle.h"
#include "point.h"
#ifndef _T_SEGMENT_H_
#define _T_SEGMENT_H_

class Triangle::T_Segment {
private:
	static int _freeID;
	const int _myID;
	const Point& _a;
	const Point& _b;
public:
	T_Segment(const T_Segment& seg); //?
	T_Segment(const Point& start, const Point& end);
	~T_Segment();
	const Point& start() const {
		return _a;
	};
	const Point& end() const {
		return _b;
	};
	const double startX() const {
		return _a.x();
	};
	const double startY() const {
		return _a.y();
	};
	const double endX() const {
		return _b.x();
	};
	const double endY() const {
		return _b.y();
	};
	double length() const;
	double distance(const Point&) const;
	const int getID() const { return _myID; }
	//Segment& operator=(const Segment&);
};

ostream& operator<<(ostream& os, const Triangle::T_Segment& seg);
#endif