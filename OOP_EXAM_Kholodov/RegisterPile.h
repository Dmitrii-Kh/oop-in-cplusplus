#pragma once
#include <ostream>

class RegisterPile
{
private:
	unsigned int _a;
	unsigned int _b;
	unsigned int _x;
	unsigned int _y;

public:
	typedef unsigned int RegisterPile ::* Register;
	typedef const unsigned int RegisterPile ::* ConstRegister;

	RegisterPile(const unsigned int a = 0xAAAAAAAA,
		const unsigned int b = 0xBBBBBBBB,
		const unsigned int x = 0xDDDDDD01,
		const unsigned int y = 0xCCCCCC01) :_a(a), _b(b), _x(x), _y(y) {}

	ConstRegister reg_a() const { return &RegisterPile::_a; }
	Register reg_a() { return &RegisterPile::_a; }

	ConstRegister reg_b() const { return &RegisterPile::_b; }
	Register reg_b() { return &RegisterPile::_b; }

	ConstRegister reg_x() const { return &RegisterPile::_x; }
	Register reg_x() { return &RegisterPile::_x; }

	ConstRegister reg_y() const { return &RegisterPile::_y; }
	Register reg_y() { return &RegisterPile::_y; }

	unsigned int get(ConstRegister r) const;
	void set(Register r, const unsigned int value);

	void swap(Register r1, Register r2);


	std::ostream& show(std::ostream& os) const
	{
		return os << '(' << _a << ',' << _b << ',' << _x << ',' << _y << ')';
	}
};

std::ostream& operator<<(std::ostream& os, const RegisterPile& c);


typedef unsigned int (* const Operation) (RegisterPile& rp, RegisterPile::Register& r1,
	const RegisterPile::Register& r2);

unsigned int Calculator(RegisterPile& rp, RegisterPile::Register& r1,
	const RegisterPile::Register& r2, Operation op);


unsigned int doAssignAnd(RegisterPile& rp, RegisterPile::Register& r1,
	const RegisterPile::Register& r2);

unsigned int doAssignOr(RegisterPile& rp, RegisterPile::Register& r1,
	const RegisterPile::Register& r2);

unsigned int doAssignXor(RegisterPile& rp, RegisterPile::Register& r1,
	const RegisterPile::Register& r2);

unsigned int cycleShiftRight(RegisterPile& c, RegisterPile::Register& r1,
	const RegisterPile::Register& r2);

unsigned int cycleShiftLeft(RegisterPile& c, RegisterPile::Register& r1,
	const RegisterPile::Register& r2);