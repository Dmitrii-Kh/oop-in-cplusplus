#pragma once
#include <iostream>
using namespace std;

//Lab 04
//Developed by Dmytro Kholodov
//on 14.02.2020
//Version 1.0

// Complex numbers
// in cartesian (algebraic) form

class TComplex;
class AComplex
{
private:
	double _re, _im;
	static int _freeId;
	int _id;

public:
	AComplex(double re = 0, double im = 0);
	AComplex(const TComplex&);
	AComplex(const AComplex&);
	~AComplex();

	AComplex& operator= (const AComplex&);

	double& re() { return _re; };
	double& im() { return _im; };

	double re() const { return _re; };
	double im() const { return _im; };

	double mod() const { return sqrt(_re * _re + _im * _im); };
	double arg() const { return atan2(_im, _re); };

	const AComplex conj() const { return AComplex(_re, -_im); };

	const int getID() const { return _id; };
};

AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator-=(AComplex&, const AComplex&);
AComplex& operator*=(AComplex&, const AComplex&);
AComplex& operator/=(AComplex&, const AComplex&);

const AComplex operator+ (const AComplex&, const AComplex&);
const AComplex operator- (const AComplex&, const AComplex&);
const AComplex power(const AComplex&, unsigned int);

bool operator== (const AComplex&, const AComplex&);
bool operator!= (const AComplex&, const AComplex&);

ostream& operator<<(ostream&, const AComplex&);
istream& operator>>(istream&, AComplex&);
