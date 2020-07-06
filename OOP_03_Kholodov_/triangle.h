#pragma once
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include "Point.h"
#include "Segment.h"
//#include "T_Segment.h" //crashes all

//Lab Task 3
//Developed by Dmytro Kholodov
//on 6.02.2020
//Version 1.0

class Triangle {

public:
	class T_Segment;
	Triangle(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0,
		const double x3 = 0, const double y3 = 1);
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Point& a, const Segment& bc);
	Triangle(const Triangle&);
	~Triangle();

	Triangle& operator= (const Triangle& t);

	double perimeter() const;
	double area() const;

	const Point& apexA() const { return _a;};
	const Point& apexB() const { return _b;};
	const Point& apexC() const { return _c;};

	Point& apexA() { return _a; };
	Point& apexB() { return _b; };
	Point& apexC() { return _c; };

	const Triangle::T_Segment& side_a() const;
	const Triangle::T_Segment& side_b() const;
	const Triangle::T_Segment& side_c() const;

	double length_a() const;
	double length_b() const;
	double length_c() const;

	const Segment median_a() const;
	const Segment median_b() const;
	const Segment median_c() const;

	const int getID() const { return _myTID; };
	static int getAmount() { return _freeTID; };

private:
	static int _freeTID;
	const int _myTID;
	Point _a;
	Point _b;
	Point _c;
	mutable T_Segment* _ab, * _bc, * _ca;
};

ostream& operator<<(ostream& os, const Triangle& t);

#endif