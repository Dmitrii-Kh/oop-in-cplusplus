#include "TrapeziumBase.h"
#include "TrapeziumAxes.h"
#include "SegmentRef.h"
#define NDEBUG

TrapeziumBase::TrapeziumBase(const double x1, const double y1, const double x2, const double y2, const double x3,
	const double y3, const double x4, const double y4) : _baseUp(x1, y1, x2, y2),
	_baseDown(x3, y3, x4, y4),
	_left(new SegmentRef(_baseUp.start(), _baseDown.end())),
	_right(new SegmentRef(_baseUp.end(), _baseDown.start())),
	_baseUpRef(nullptr), _baseDownRef(nullptr),
	_middlePoint1(nullptr),
	_middlePoint2(nullptr),
	_middleLine(nullptr)
{
	if (!UpDownParallel())
		throw BadTrapeziumBase("NOT A TRAPEZIUM");

	if (UpDownParallel() && LeftRightParallel())
		throw BadTrapeziumBase("NOT A TRAPEZIUM (SQUARE//PARALLELOGRAM)");
		
	if (checkCrossingX() || checkCrossingY())
		throw BadTrapeziumBase("NOT A TRAPEZIUM (CROSSING SEGMENTS)");

	
#ifndef NDEBUG
	cout << "Object " << *this << " created by 8 base points!" << endl;
#endif
	return;
}

TrapeziumBase::TrapeziumBase(const Segment& baseUp, const Segment& baseDown) :
	_baseUp(baseUp), _baseDown(baseDown),
	_left(new SegmentRef(_baseUp.start(), _baseDown.end())),
	_right(new SegmentRef(_baseUp.end(), _baseDown.start())),
	_baseUpRef(nullptr), _baseDownRef(nullptr),
	_middlePoint1(nullptr),
	_middlePoint2(nullptr),
	_middleLine(nullptr)
{
	if (!UpDownParallel())
		throw BadTrapeziumBase("NOT A TRAPEZIUM");

	if (UpDownParallel() && LeftRightParallel())
		throw BadTrapeziumBase("NOT A TRAPEZIUM (SQUARE//PARALLELOGRAM)");

	if (checkCrossingX() || checkCrossingY())
		throw BadTrapeziumBase("NOT A TRAPEZIUM (CROSSING SEGMENTS)");

	
#ifndef NDEBUG
	cout << "Object " << *this << " created by 2 base segments!" << endl;
#endif
	return;
}

TrapeziumBase::TrapeziumBase(const TrapeziumBase& tr) : _baseUp(tr._baseUp), _baseDown(tr._baseDown),
_left(new SegmentRef(_baseUp.start(), _baseDown.end())),
_right(new SegmentRef(_baseUp.end(), _baseDown.start())),
_baseUpRef(nullptr), _baseDownRef(nullptr),
_middlePoint1(nullptr), _middlePoint2(nullptr),
_middleLine(nullptr)
{
#ifndef NDEBUG
	cout << "Object " << *this << " copied!" << endl;
#endif
	return;
}

TrapeziumBase::TrapeziumBase(const TrapeziumAxes& tr) :
	_baseUp(tr.parallel1().start(), tr.parallel1().end()),
	_baseDown(tr.parallel2().start(), tr.parallel2().end()),
	_left(new SegmentRef(_baseUp.start(), _baseDown.end())),
	_right(new SegmentRef(_baseUp.end(), _baseDown.start())),
	_baseUpRef(nullptr), _baseDownRef(nullptr),
	_middlePoint1(nullptr), _middlePoint2(nullptr),
	_middleLine(nullptr)
{
#ifndef NDEBUG
	cout << "Object " << *this << " copied from TrapeziumAxes!" << endl;
#endif
	return;
}

TrapeziumBase::~TrapeziumBase()
{
	delete _left;
	delete _right;
	delete _baseUpRef;
	delete _baseDownRef;
	delete _middleLine;
	delete _middlePoint1;
	delete _middlePoint2;

	_left = _right = _baseUpRef = _baseDownRef = nullptr;
	_middlePoint1 = _middlePoint2 = nullptr;
	_middleLine = nullptr;

#ifndef NDEBUG
	cout << "Object " << *this << " has been deleted!" << endl;
#endif
}

TrapeziumBase& TrapeziumBase::operator=(const TrapeziumBase& tr)
{
	if (this == &tr) return *this;

	_baseUp = tr._baseUp;
	_baseDown = tr._baseDown;

	delete _left;
	delete _right;
	delete _baseUpRef;
	delete _baseDownRef;
	delete _middleLine;
	delete _middlePoint1;
	delete _middlePoint2;

	_baseUpRef = _baseDownRef = nullptr;
	_middlePoint1 = _middlePoint2 = nullptr;
	_middleLine = nullptr;


	_left = new SegmentRef(_baseUp.start(), _baseDown.start());
	_right = new SegmentRef(_baseUp.end(), _baseDown.end());

#ifndef NDEBUG
	cout << "Copy assignment call!" << endl;
#endif
	return *this;
}

const Trapezium::SegmentRef& TrapeziumBase::side_AB() const
{
	if (_baseUpRef == nullptr)
		_baseUpRef = new SegmentRef(_baseUp);
	return *_baseUpRef;
}

const Trapezium::SegmentRef& TrapeziumBase::side_BC() const
{
	return *_right;
}

const Trapezium::SegmentRef& TrapeziumBase::side_CD() const
{
	if (_baseDownRef == nullptr)
		_baseDownRef = new SegmentRef(_baseDown);
	return *_baseDownRef;
}

const Trapezium::SegmentRef& TrapeziumBase::side_DA() const
{
	return *_left;
}

double TrapeziumBase::length_AB() const
{
	return side_AB().length();
}

double TrapeziumBase::length_BC() const
{
	return side_BC().length();
}

double TrapeziumBase::length_CD() const
{
	return side_CD().length();
}

double TrapeziumBase::length_DA() const
{
	return side_DA().length();
}


const Point& TrapeziumBase::middlePoint1() const
{
	if (_middlePoint1 == nullptr)
		_middlePoint1 = new Point(side_DA().middlePoint());
	return *_middlePoint1;
}

const Point& TrapeziumBase::middlePoint2() const
{
	if (_middlePoint2 == nullptr)
		_middlePoint2 = new Point(side_BC().middlePoint());
	return *_middlePoint2;
}


const Trapezium::SegmentRef& TrapeziumBase::middleLine() const
{
	if (_middleLine == nullptr)
		_middleLine = new SegmentRef(middlePoint1(), middlePoint2());
	return *_middleLine;
}

double TrapeziumBase::perimeter() const
{
	return length_AB() + length_BC() + length_CD() + length_DA();
}

double TrapeziumBase::area() const
{
	return middleLine().length() * (abs((_baseUp.endY() - _baseUp.startY()) * _baseDown.startX() - (_baseUp.endX() - _baseUp.startX()) * _baseDown.startY() +
		_baseUp.endX() * _baseUp.startY() - _baseUp.endY() * _baseUp.startX())
		/ _baseUp.length());
}

const TrapeziumBase& TrapeziumBase::rotateTrapezium(int angle)
{
	_baseUp.rotateSegment(angle);
	_baseDown.rotateSegment(angle);
	_middlePoint1->rotatePoint(angle);
	_middlePoint2->rotatePoint(angle);
	return *this;
}

const TrapeziumBase& TrapeziumBase::mirrorTrapezium(char axis)
{
	_baseUp.mirrorSegment(axis);
	_baseDown.mirrorSegment(axis);
	_middlePoint1->mirrorPoint(axis);
	_middlePoint2->mirrorPoint(axis);
	return *this;
}

ostream& operator<<(ostream& os, const TrapeziumBase& tr)
{
	os << "Trapezium Base : [ A : " << tr.apexA() << "; B : " << tr.apexB() << "; C : " << tr.apexC() << "; D : " << tr.apexD() << " ]";
	return os;
}


bool TrapeziumBase::UpDownParallel() const
{
	return (apexD().x() - apexC().x()) * (apexA().y() - apexB().y()) == (apexD().y() - apexC().y()) * (apexA().x() - apexB().x());
}

bool TrapeziumBase::LeftRightParallel() const
{
	return (apexD().x() - apexA().x()) * (apexB().y() - apexC().y()) == (apexD().y() - apexA().y()) * (apexB().x() - apexC().x());

}

bool TrapeziumBase::checkCrossingX() const
{
	return (_baseUp.start().x() < _baseUp.end().x() && _baseDown.start().x() < _baseDown.end().x()) || (_baseUp.start().x() > _baseUp.end().x() && _baseDown.start().x() > _baseDown.end().x());
}

bool TrapeziumBase::checkCrossingY() const
{
	return (_baseUp.start().y() < _baseUp.end().y() && _baseDown.start().y() < _baseDown.end().y()) || (_baseUp.start().y() > _baseUp.end().y() && _baseDown.start().y() > _baseDown.end().y());
}
