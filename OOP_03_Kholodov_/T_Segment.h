#pragma once
#include "Triangle.h"
#include "Point.h"
#ifndef _T_SEGMENT_H_
#define _T_SEGMENT_H_

//Lab Task 3
//Developed by Dmytro Kholodov
//on 6.02.2020
//Version 2.0

class Triangle::T_Segment {
private:
	static int _freeID;
	const int _myID;
	const Point& _a;
	const Point& _b;
public:
	T_Segment(const T_Segment& seg); 
	T_Segment(const Point& start, const Point& end);
	~T_Segment();

	const Point& start() const { return _a; };
	const Point& end() const { return _b; };

	const double startX() const { return _a.x(); };
	const double startY() const { return _a.y(); };
	const double endX() const {	return _b.x(); };
	const double endY() const {	return _b.y(); };

	double length() const;
	double distance(const Point&) const;

	const int getID() const { return _myID; }
	T_Segment& operator=(const T_Segment&) = delete;
	Point middlePoint() const
};
ostream& operator<<(ostream& os, const Triangle::T_Segment& seg);

inline double distance(const Triangle::T_Segment& s, const Point& p);
#endif