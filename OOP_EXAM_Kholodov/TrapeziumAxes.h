#pragma once
#include "Point.h"
#include "Trapezium.h"

//#include "SegmentRef.h"

class TrapeziumBase;

//	APEX ORDER:
//	
//		B C
//    A	    D

class TrapeziumAxes : public Trapezium
{

private:
	Point _a, _b, _c, _d;
	mutable SegmentRef* _ab, * _bc, * _cd, * _da;
	mutable SegmentRef* _nonParallel1, * _nonParallel2;
	mutable SegmentRef* _parallel1, * _parallel2;
	mutable Point* _middlePoint1, * _middlePoint2;
	mutable SegmentRef* _middleLine;


	bool UpDownParallel() const;
	bool LeftRightParallel() const;
	bool checkCrossingX() const;
	bool checkCrossingY() const;


	const SegmentRef& nonParallel1() const;
	const SegmentRef& nonParallel2() const;

	const Point& middlePoint1() const;
	const Point& middlePoint2() const;

public:
	class BadTrapeziumAxes;

	TrapeziumAxes(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 1,
		const double x3 = 2, const double y3 = 1,
		const double x4 = 3, const double y4 = 0);
	TrapeziumAxes(const Point& a, const Point& b, const Point& c, const Point& d);
	TrapeziumAxes(const TrapeziumAxes&);
	explicit TrapeziumAxes(const TrapeziumBase&);

	~TrapeziumAxes();

	TrapeziumAxes& operator=(const TrapeziumAxes&);


	double perimeter() const override;
	double area() const override;

	const Point& apexA() const override { return _a; };
	const Point& apexB() const override { return _b; };
	const Point& apexC() const override { return _c; };
	const Point& apexD() const override { return _d; };


	const SegmentRef& side_AB() const override;
	const SegmentRef& side_BC() const override;
	const SegmentRef& side_CD() const override;
	const SegmentRef& side_DA() const override;



	double length_AB() const;
	double length_BC() const;
	double length_CD() const;
	double length_DA() const;


	const SegmentRef& middleLine() const override;
	const TrapeziumAxes& rotateTrapezium(int angle) override;
	const TrapeziumAxes& mirrorTrapezium(char axis) override;

	//required to be public by convert-constructor
	const SegmentRef& parallel1() const;
	const SegmentRef& parallel2() const;
};

ostream& operator<<(ostream&, const TrapeziumAxes&);


class TrapeziumAxes::BadTrapeziumAxes
{
private:
	string _reason;
	size_t _index;
public:
	BadTrapeziumAxes(string reason = "", size_t index = 0)
		:_reason(reason), _index(index)
	{
		return;
	};
	~BadTrapeziumAxes() {};
	void diagnose() const
	{
		cout << _reason;
		if (_index != 0)
			cout << _index;
		cout << endl;
	}
};