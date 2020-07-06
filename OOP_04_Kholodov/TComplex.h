#pragma once
#include <iostream>
#include <cmath>
using namespace std;

//Lab 04
//Developed by Dmytro Kholodov
//on 14.02.2020
//Version 1.0

// Complex numbers
// in polar form

class AComplex;
class TComplex
{
private:
	double _ro, _phi;
	static int _freeId;
	int _id;

public:
	TComplex(double ro = 0, double phi = 0);
	TComplex(const TComplex&);
	TComplex(const AComplex&);
	~TComplex();

	TComplex& operator= (const TComplex&);

	double& mod() { return _ro; };
	double& arg() { return _phi; };

	double mod() const { return _ro; };
	double arg() const { return _phi; };

	double re() const { return _ro*cos(_phi); };
	double im() const { return _ro*sin(_phi); };

};

TComplex& operator+=(TComplex& a, const TComplex& b);
TComplex& operator-=(TComplex& a, const TComplex& b);
TComplex& operator*=(TComplex& a, const TComplex& b);
TComplex& operator/=(TComplex& a, const TComplex& b);

const TComplex  operator* (const TComplex&, const TComplex&);
const TComplex  operator/ (const TComplex&, const TComplex&);
const TComplex  power(const TComplex&, unsigned int);

ostream& operator<<(ostream&, const TComplex&);
istream& operator>>(istream&, TComplex&);