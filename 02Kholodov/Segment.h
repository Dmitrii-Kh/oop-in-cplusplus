#pragma once
#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include "Point.h"

class Segment
{
private:
	static int _freeID;
	const int _myID;

	Point _a;
	Point _b;

public:
	
	Segment(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0);

	
	Segment(const Point& start, const Point& end);

	Segment(const Segment&);

	~Segment();

	Segment& operator=(const Segment&);

	const Point& start() const { return _a; };
	const Point& end() const { return _b; };

	Point& start() { return _a; };
	Point& end() { return _b; };

	const double& startX() const { return _a.x(); };
	const double& startY() const { return _a.y(); };
	const double& endX() const { return _b.x(); };;
	const double& endY() const { return _b.y(); };;

	double& startX() { return _a.x(); };
	double& startY() { return _a.y(); };
	double& endX() { return _b.x(); };
	double& endY() { return _b.y(); };

	double length() const;

	double distance(const Point&) const;

	const int getID() const { return _myID;  };
};

ostream& operator<<(ostream&, const Segment&);

double distance(const Segment&, const Point&);
#endif