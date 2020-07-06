#include <iostream>
#include "AComplex.h"
#include "TComplex.h"
#include <cmath>

int AComplex::_freeId = 0;

AComplex::AComplex(double re, double im) : _re(re), _im(im), _id(++_freeId){
#ifndef NDEBUG
	cout << "AComplex #" << _id  << " "<< *this << " created!" << endl;
#endif 
	return;
};

AComplex::AComplex(const TComplex& tc) : _re(tc.re()), _im(tc.im()), _id(++_freeId) {
#ifndef NDEBUG
	cout << "AComplex #" << _id << " " << *this << " created!" << endl;
#endif 
	return;
};

AComplex::AComplex(const AComplex& ac) : _re(ac.re()), _im(ac.im()), _id(++_freeId) {
#ifndef NDEBUG
	cout << "AComplex #" << _id << " " << *this << " created!" << endl;
#endif 
	return;
};

AComplex::~AComplex() {
#ifndef NDEBUG
	cout << "AComplex #" << _id << " " << *this << " has been deleted!" << endl;
#endif 
	return;
};


AComplex& AComplex::operator= (const AComplex& ac) {
	re() = ac.re();
	im() = ac.im();
	return *this;
};

ostream& operator<<(ostream& os, const AComplex& ac) {
	os << "(re : " << ac.re() << "; im: " << ac.im()  << ")";
	return os;
};

AComplex& operator+=(AComplex& a, const AComplex& b) {
	a.re() += b.re();
	a.im() += b.im();
	return a;
};

AComplex& operator-=(AComplex& a, const AComplex& b) {
	a.re() -= b.re();
	a.im() -= b.im();
	return a;
};

AComplex& operator*=(AComplex& a, const AComplex& b) {
	return a = a * b;
};

AComplex& operator/=(AComplex& a, const AComplex& b) {
	return a = a / b;
};

const AComplex operator+ (const AComplex& a, const AComplex& b) {
	return AComplex(a.re() + b.re(), a.im() + b.im());
};

const AComplex operator- (const AComplex& a, const AComplex& b) {
	return AComplex(a.re() - b.re(), a.im() - b.im());
};

bool operator== (const AComplex& a, const AComplex& b) {
	return (a.re() == b.re()) & (a.im() == b.im());
};

bool operator!= (const AComplex& a, const AComplex& b) {
	return !(a == b);
};

const AComplex power(const AComplex& a, unsigned int n) {
	TComplex cpy(a);
	return power(cpy, n);
};

istream& operator>>(istream& is, AComplex& a) {
	cout << "Re : ";
	is >> a.re();
	cout << "; Im : ";
	is >> a.im();
	return is;
};
