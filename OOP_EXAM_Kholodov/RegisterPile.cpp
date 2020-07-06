#include "RegisterPile.h"

#include <cassert>

unsigned RegisterPile::get(ConstRegister r) const
{
	return this->*r;
}

void RegisterPile::set(Register r, const unsigned int value)
{
	this->*r = value;
}

void RegisterPile::swap(Register r1, Register r2)
{
	const unsigned int temp = this->*r1;
	this->*r1 = this->*r2;
	this->*r2 = temp;
}


std::ostream& operator<<(std::ostream& os, const RegisterPile& c)
{
	return c.show(os);
}


unsigned int doAssignAnd(RegisterPile& rp, RegisterPile::Register& r1,
	const RegisterPile::Register& r2)
{
	const unsigned int res = rp.*r1 &= rp.*r2;
	assert(res == rp.*r1);
	return res;
}

unsigned int doAssignOr(RegisterPile& rp, RegisterPile::Register& r1,
	const RegisterPile::Register& r2)
{
	const unsigned int res = rp.*r1 |= rp.*r2;
	assert(res == rp.*r1);
	return res;
}

unsigned int doAssignXor(RegisterPile& rp, RegisterPile::Register& r1,
	const RegisterPile::Register& r2)
{
	const unsigned int res = rp.*r1 ^= rp.*r2;
	assert(res == rp.*r1);
	return res;
}

unsigned int cycleShiftLeft(
	RegisterPile& c,
	RegisterPile::Register& r1,
	const RegisterPile::Register& r2)
{
	const unsigned int res = c.*r1 = (c.*r1 >> (32 - c.*r2)) | (c.*r1 << c.*r2);
	assert(res == c.*r1);
	return res;
}


unsigned int cycleShiftRight(
	RegisterPile& c,
	RegisterPile::Register& r1,
	const RegisterPile::Register& r2)
{
	const unsigned int res = c.*r1 = (c.*r1 << (32 - c.*r2)) | (c.*r1 >> c.*r2);
	assert(res == c.*r1);
	return res;
}


unsigned Calculator(RegisterPile& rp, RegisterPile::Register& r1, const RegisterPile::Register& r2, Operation op)
{
	const unsigned int res = op(rp, r1, r2);
	assert(res == rp.*r1);
	return res;
}
