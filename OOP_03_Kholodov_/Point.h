#pragma once
#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
using namespace std;

//*******************************************
//Every point posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a point created or resp. deleted
//*******************************************
//Lab Task 1
//Developed by Dmytro Kholodov
//on 18.01.2020
//Version 1.0
//*******************************************

class Point
{
private:
	static int freeID;
	const int pointID;
	double _x;
	double _y;
public:
	Point(double x = 0, double y = 0);
	Point(const Point& u);
	~Point();
	Point& operator=(const Point& u);
	double& x() { return _x; };
	double& y() { return _y; };
	const double& x()const { return _x; };
	const double& y()const { return _y; };
	const int getID() const { return pointID; };
	static int amount() { return freeID; };
	const double distToPoint(const Point& p) const;
};

ostream& operator<<(ostream&, const Point&);

const Point operator+ (const Point& u, const Point& v);
Point& operator+=(Point&, const Point&);
bool operator==(const Point& u, const Point& v);
bool operator!=(const Point& u, const Point& v);

#endif