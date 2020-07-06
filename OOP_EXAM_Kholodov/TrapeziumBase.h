#pragma once
#include "Segment.h" //basic segment (points composition)
#include "Trapezium.h" //abstract class

class TrapeziumAxes;

//	APEX ORDER:
//		
//		A B
//    D	    C

class TrapeziumBase: public Trapezium
{
private:
	Segment _baseUp, _baseDown;
	mutable SegmentRef *_left, * _right;
	mutable SegmentRef* _baseUpRef, * _baseDownRef;
	mutable Point* _middlePoint1, * _middlePoint2;
	mutable SegmentRef* _middleLine;


	const Point& middlePoint1() const;
	const Point& middlePoint2() const;

	bool UpDownParallel() const;
	bool LeftRightParallel() const;
	bool checkCrossingX() const;
	bool checkCrossingY() const;

public:
	class BadTrapeziumBase;

	TrapeziumBase(const double x1 = 1, const double y1 = 1,
		const double x2 = 2, const double y2 = 1,
		const double x3 = 3, const double y3 = 0,
		const double x4 = 0, const double y4 = 0);
	TrapeziumBase(const Segment& baseUp, const Segment& baseDown);
	TrapeziumBase(const TrapeziumBase&);
	explicit TrapeziumBase(const TrapeziumAxes&);
	~TrapeziumBase();
	TrapeziumBase& operator=(const TrapeziumBase&);

	const Point& apexA() const override { return _baseUp.start(); };
	const Point& apexB() const override { return _baseUp.end(); };
	const Point& apexC() const override { return _baseDown.start(); };
	const Point& apexD() const override { return _baseDown.end(); };


	const SegmentRef& side_AB() const override; //baseUp
	const SegmentRef& side_BC() const override; //right
	const SegmentRef& side_CD() const override; //baseDown
	const SegmentRef& side_DA() const override; //left

	double length_AB() const;
	double length_BC() const;
	double length_CD() const;
	double length_DA() const;
	
	const SegmentRef& middleLine() const override;

	double perimeter() const override;
	double area() const override;

	const TrapeziumBase& rotateTrapezium(int angle) override;
	const TrapeziumBase& mirrorTrapezium(char axis) override;
};

ostream& operator<<(ostream&, const TrapeziumBase&);

class TrapeziumBase::BadTrapeziumBase
{
private:
	string _reason;
	size_t _index;
public:
	BadTrapeziumBase(string reason = "", size_t index = 0)
		:_reason(reason), _index(index)
	{
		return;
	};
	~BadTrapeziumBase() {};
	void diagnose() const
	{
		cout << _reason;
		if (_index != 0)
			cout << _index;
		cout << endl;
	}
};