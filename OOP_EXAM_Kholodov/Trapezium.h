#pragma once


class Trapezium
{
public:
	class SegmentRef;
	Trapezium() = default;
	virtual ~Trapezium() = default;
	
	virtual const Point& apexA() const = 0;
	virtual const Point& apexB() const = 0;
	virtual const Point& apexC() const = 0;
	virtual const Point& apexD() const = 0;


	virtual const SegmentRef& side_AB() const = 0;
	virtual const SegmentRef& side_BC() const = 0;
	virtual const SegmentRef& side_CD() const = 0;
	virtual const SegmentRef& side_DA() const = 0;

	virtual double perimeter() const = 0;
	virtual double area() const = 0;

	virtual const SegmentRef& middleLine() const = 0;

	virtual const Trapezium& rotateTrapezium(int angle) = 0;
	virtual const Trapezium& mirrorTrapezium(char axis) = 0;
};

ostream& operator<<(ostream&, const Trapezium&);
ostream& operator<<(ostream& os, const Trapezium::SegmentRef& seg);
