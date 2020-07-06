#include "TComplex.h"
#include "AComplex.h"
#include <iostream>

int TComplex::_freeId = 0;

TComplex::TComplex(double ro, double phi) : _ro(ro), _phi(phi), _id(++_freeId) {
#ifndef NDEBUG
	cout << "TComplex #" << _id << " " << *this << " created!" << endl;
#endif 
	return;
};

TComplex::TComplex(const TComplex& tc) : _ro(tc.mod()), _phi(tc.arg()), _id(++_freeId) {
#ifndef NDEBUG
	cout << "TComplex #" << _id << " " << *this << " created!" << endl;
#endif 
	return;
};

TComplex::TComplex(const AComplex& ac) : _ro(ac.mod()), _phi(ac.arg()), _id(++_freeId) {
#ifndef NDEBUG
	cout << "TComplex #" << _id << " " << *this << " created!" << endl;
#endif 
	return;
};

TComplex::~TComplex() {
#ifndef NDEBUG
	cout << "TComplex #" << _id << " " << *this << " has been deleted!" << endl;
#endif 
	return;
};


TComplex& TComplex::operator= (const TComplex& t) {
	mod() = t.mod();
	arg() = t.arg();
	return *this;
};

TComplex& operator+=(TComplex& a, const TComplex& b) {
	return a = a + b;
};


TComplex& operator-=(TComplex& a, const TComplex& b) {
	return a = a - b;
};


TComplex& operator*=(TComplex& a, const TComplex& b) {
	a.mod() *= b.mod();
	a.arg() += b.arg();
	return a;
};

TComplex& operator/=(TComplex& a, const TComplex& b) {
	a.mod() /= b.mod();
	a.arg() -= b.arg();
	return a;
};

const TComplex power(const TComplex& a, unsigned int n) {;
	double mod = pow(a.mod(), n);
	double arg = a.arg() * n;
	return TComplex(mod, arg);
};

const TComplex  operator* (const TComplex& a, const TComplex& b) {
	return TComplex(a.mod() * b.mod(), a.arg() + b.arg());
};

const TComplex  operator/ (const TComplex& a, const TComplex& b) {
	return TComplex(a.mod() / b.mod(), a.arg() - b.arg());
};

ostream& operator<<(ostream& os, const TComplex& tc) {
	os << "(ro : " << tc.mod() << "; phi : " << tc.arg() << ")";
	return os;
};

istream& operator>>(istream& is, TComplex& tc) {
	cout << "Mod : ";
	is >> tc.mod();
	cout << " Arg : ";
	is >> tc.arg();
	return is;
};