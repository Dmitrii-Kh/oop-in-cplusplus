#include "TrapeziumAxes.h"
#include "TrapeziumBase.h"
#include "SegmentRef.h"
#define NDEBUG


TrapeziumAxes::TrapeziumAxes(const double x1, const double y1,
	const double x2, const double y2, const double x3,
	const double y3, const double x4, const double y4) :
	_a(x1, y1), _b(x2, y2), _c(x3, y3), _d(x4, y4),
	_ab(nullptr), _bc(nullptr), _cd(nullptr), _da(nullptr),
	_nonParallel1(nullptr), _nonParallel2(nullptr),
	_parallel1(nullptr), _parallel2(nullptr),
	_middlePoint1(nullptr), _middlePoint2(nullptr),
	_middleLine(nullptr)
{
	if (!UpDownParallel() && !LeftRightParallel())
		throw BadTrapeziumAxes("NOT A TRAPEZIUM");

	if (UpDownParallel() && LeftRightParallel())
		throw BadTrapeziumAxes("NOT A TRAPEZIUM (SQUARE//PARALLELOGRAM)");

	if (checkCrossingX() || checkCrossingY())
		throw BadTrapeziumAxes("NOT A TRAPEZIUM(CROSSING SEGMENTS)");

#ifndef NDEBUG
	cout << "Object " << *this << " created by 8 coordinates!" << endl;
#endif
	return;
}

TrapeziumAxes::TrapeziumAxes(const Point& a, const Point& b, const Point& c, const Point& d) :
	_a(a), _b(b), _c(c), _d(d), _ab(nullptr),
	_bc(nullptr), _cd(nullptr), _da(nullptr),
	_nonParallel1(nullptr), _nonParallel2(nullptr),
	_parallel1(nullptr), _parallel2(nullptr),
	_middlePoint1(nullptr), _middlePoint2(nullptr),
	_middleLine(nullptr)
{
	if (!UpDownParallel() && !LeftRightParallel())
		throw BadTrapeziumAxes("NOT A TRAPEZIUM");

	if (UpDownParallel() && LeftRightParallel())
		throw BadTrapeziumAxes("NOT A TRAPEZIUM (SQUARE//PARALLELOGRAM)");

	if (checkCrossingX() || checkCrossingY())
		throw BadTrapeziumAxes("NOT A TRAPEZIUM(CROSSING SEGMENTS)");

#ifndef NDEBUG
	cout << "Object " << *this << " created by 4 points!" << endl;
#endif
	return;
}

TrapeziumAxes::TrapeziumAxes(const TrapeziumAxes& tr) :
	_a(tr._a), _b(tr._b), _c(tr._c), _d(tr._d),
	_ab(nullptr), _bc(nullptr), _cd(nullptr), _da(nullptr),
	_nonParallel1(nullptr), _nonParallel2(nullptr),
	_parallel1(nullptr), _parallel2(nullptr),
	_middlePoint1(nullptr), _middlePoint2(nullptr), _middleLine(nullptr)
{
#ifndef NDEBUG
	cout << "Object " << *this << " copied!" << endl;
#endif
	return;
}

TrapeziumAxes::TrapeziumAxes(const TrapeziumBase& tr) :
	_a(tr.apexD()), _b(tr.apexA()),
	_c(tr.apexB()), _d(tr.apexC()),
	_ab(nullptr), _bc(nullptr), _cd(nullptr), _da(nullptr),
	_nonParallel1(nullptr), _nonParallel2(nullptr),
	_parallel1(nullptr), _parallel2(nullptr),
	_middlePoint1(nullptr), _middlePoint2(nullptr), _middleLine(nullptr)
{
#ifndef NDEBUG
	cout << "Object " << *this << " copied from TrapeziumBase!" << endl;
#endif
	return;
}

TrapeziumAxes::~TrapeziumAxes()
{
	delete _ab;
	delete _bc;
	delete _cd;
	delete _da;

	delete _middleLine;
	delete _middlePoint1;
	delete _middlePoint2;

	_ab = _bc = _cd = _da = nullptr;
	_middlePoint2 = _middlePoint1 = nullptr;
	_nonParallel1 = _nonParallel2 = _parallel1 = _parallel2 = nullptr;
	_middleLine = nullptr;

#ifndef NDEBUG
	cout << "Object " << *this << " has been deleted!" << endl;
#endif
}

TrapeziumAxes& TrapeziumAxes::operator=(const TrapeziumAxes& tr)
{
	if (this == &tr) return *this;

	_a = tr._a;
	_b = tr._b;
	_c = tr._c;
	_d = tr._d;

	delete _ab;
	delete _bc;
	delete _cd;
	delete _da;

	delete _middleLine;
	delete _middlePoint1;
	delete _middlePoint2;

	_ab = _bc = _cd = _da = nullptr;
	_middleLine = nullptr;
	_middlePoint2 = _middlePoint1 = nullptr;
	_nonParallel1 = _nonParallel2 = _parallel1 = _parallel2 = nullptr;

#ifndef NDEBUG
	cout << "Copy assignment call!" << endl;
#endif
	return *this;
}

double TrapeziumAxes::perimeter() const
{
	return length_AB() + length_BC() + length_CD() + length_DA();
}

double TrapeziumAxes::area() const
{
	return middleLine().length() *
		(abs((_parallel1->endY() - _parallel1->startY()) * _parallel2->startX() - (_parallel1->endX() - _parallel1->startX()) * _parallel2->startY() +
			_parallel1->endX() * _parallel1->startY() - _parallel1->endY() * _parallel1->startX())
			/ _parallel1->length());
}

const Trapezium::SegmentRef& TrapeziumAxes::side_AB() const
{
	if (_ab == nullptr) _ab = new SegmentRef(apexA(), apexB());
	return *_ab;
}


const Trapezium::SegmentRef& TrapeziumAxes::side_BC() const
{
	if (_bc == nullptr) _bc = new SegmentRef(apexB(), apexC());
	return *_bc;
}


const Trapezium::SegmentRef& TrapeziumAxes::side_CD() const
{
	if (_cd == nullptr) _cd = new SegmentRef(apexC(), apexD());
	return *_cd;
}


const Trapezium::SegmentRef& TrapeziumAxes::side_DA() const
{
	if (_da == nullptr) _da = new SegmentRef(apexD(), apexA());
	return *_da;
}

double TrapeziumAxes::length_AB() const
{
	return side_AB().length();
}

double TrapeziumAxes::length_BC() const
{
	return side_BC().length();
}

double TrapeziumAxes::length_CD() const
{
	return side_CD().length();
}

double TrapeziumAxes::length_DA() const
{
	return side_DA().length();
}

const Trapezium::SegmentRef& TrapeziumAxes::middleLine() const
{
	if (_middleLine == nullptr)
		_middleLine = new SegmentRef(middlePoint1(), middlePoint2());
	return *_middleLine;
}

const TrapeziumAxes& TrapeziumAxes::rotateTrapezium(int angle)
{
	_a.rotatePoint(angle);
	_b.rotatePoint(angle);
	_c.rotatePoint(angle);
	_d.rotatePoint(angle);
	_middlePoint1->rotatePoint(angle);
	_middlePoint2->rotatePoint(angle);
	return *this;
}

const TrapeziumAxes& TrapeziumAxes::mirrorTrapezium(char axis)
{
	_a.mirrorPoint(axis);
	_b.mirrorPoint(axis);
	_c.mirrorPoint(axis);
	_d.mirrorPoint(axis);
	_middlePoint1->mirrorPoint(axis);
	_middlePoint2->mirrorPoint(axis);
	return *this;
}

const Trapezium::SegmentRef& TrapeziumAxes::parallel1() const
{
	if (_parallel1 == nullptr) nonParallel1();
	return *_parallel1;
}

const Trapezium::SegmentRef& TrapeziumAxes::parallel2() const
{
	if (_parallel2 == nullptr) nonParallel2();
	return *_parallel2;
}


const Trapezium::SegmentRef& TrapeziumAxes::nonParallel1() const
{
	if (_nonParallel1 == nullptr) {
		if (UpDownParallel())
		{
			side_AB();
			_nonParallel1 = _ab;
			side_BC();
			_parallel1 = _bc;
		}
		else
		{
			side_BC();
			_nonParallel1 = _bc;
			side_AB();
			_parallel1 = _ab;
		}
	}
	return *_nonParallel1;
}

const Trapezium::SegmentRef& TrapeziumAxes::nonParallel2() const
{
	if (_nonParallel2 == nullptr) {
		if (UpDownParallel())
		{
			side_CD();
			_nonParallel2 = _cd;
			side_DA();
			_parallel2 = _da;
		}
		else
		{
			side_DA();
			_nonParallel2 = _da;
			side_CD();
			_parallel2 = _cd;
		}
	}
	return *_nonParallel2;
}


const Point& TrapeziumAxes::middlePoint1() const
{
	if (_middlePoint1 == nullptr)
		_middlePoint1 = new Point(nonParallel1().middlePoint());
	return *_middlePoint1;
}

const Point& TrapeziumAxes::middlePoint2() const
{
	if (_middlePoint2 == nullptr)
		_middlePoint2 = new Point(nonParallel2().middlePoint());
	return *_middlePoint2;
}


bool TrapeziumAxes::LeftRightParallel() const
{
	return (_a.x() - _b.x()) * (_c.y() - _d.y()) == (_a.y() - _b.y()) * (_c.x() - _d.x());
}


bool TrapeziumAxes::UpDownParallel() const
{
	return (_a.x() - _d.x()) * (_b.y() - _c.y()) == (_a.y() - _d.y()) * (_b.x() - _c.x());
}


bool TrapeziumAxes::checkCrossingX() const
{
	return (parallel1().start().x() < parallel1().end().x() && parallel2().start().x() < parallel2().end().x()) || (parallel1().start().x() > parallel1().end().x() && parallel2().start().x() > parallel2().end().x());
}

bool TrapeziumAxes::checkCrossingY() const
{
	return (parallel1().start().y() < parallel1().end().y() && parallel2().start().y() < parallel2().end().y()) || (parallel1().start().y() > parallel1().end().y() && parallel2().start().y() > parallel2().end().y());
}

ostream& operator<<(ostream& os, const TrapeziumAxes& tr)
{
	os << "Trapezium Axes : [ A : " << tr.apexA() << "; B : " << tr.apexB() << "; C : " << tr.apexC() << "; D : " << tr.apexD() << " ]";
	return os;
}

