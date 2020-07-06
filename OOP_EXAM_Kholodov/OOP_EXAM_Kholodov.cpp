#include <iostream>
#include "Segment.h"
#include  "TrapeziumAxes.h"
#include "Trapezium.h"
#include  "Matrix.h"
#include "RegisterPile.h"
#include "TrapeziumBase.h"
using namespace std;


int main()
{
	cout << "\n============================= TASK 1 =============================" << endl;

	RegisterPile rp(0,1,1,1);

	cout << "Register Pile : " << rp << endl;
	RegisterPile::Register ra(rp.reg_a());
	RegisterPile::Register rb(rp.reg_b());
	RegisterPile::Register rx(rp.reg_x());
	RegisterPile::Register ry(rp.reg_y());


	cout << "\nRegister a : " << rp.get(ra) << endl;
	rp.swap(ra, rb);
	cout << "\nSwapped Register Pile (a, b) : " << rp << endl;

	rp.set(rx, 2);
	rp.set(ry, 4);

	cout << "\nRegister x : " << rp.get(rx) << endl;
	cout << "\nRegister y : " << rp.get(ry) << endl;
	rp.swap(rx, ry);
	cout << "\nSwapped Register Pile (x, y) : " << rp << endl;

	rp.swap(ra, ry);
	cout << "\nSwapped Register Pile (a, y) : " << rp << endl;
	rp.set(ra, 1);



	cout << "\n============================= TASK 2 =============================" << endl;


	cout << "\nRegister Pile : " << rp << endl;
	
	cout << "Assignment | : " << Calculator(rp, ra, rb, doAssignOr) << endl;
	cout << "\nCurrent Register Pile : " << rp << endl;

	cout << "Assignment & : " << Calculator(rp, ra, rb, doAssignAnd) << endl;
	cout << "\nCurrent Register Pile : " << rp << endl;
	
	rp.set(ra, 1);
	cout << "\nModified Register Pile : " << rp << endl;
	
	cout << "Assignment ^ (XOR) : " << Calculator(rp, ra, rb, doAssignXor) << endl;
	cout << "\nCurrent Register Pile : " << rp << endl;

	rp.set(rb, 4);
	rp.set(ra, 2);

	cout << "\nModified Register Pile : " << rp << endl;
	cout << "Cycle Shift Left : " << Calculator(rp, ra, rb, cycleShiftLeft) << endl;
	cout << "\nCurrent Register Pile : " << rp << endl;

	rp.set(rb, 2);
	rp.set(ra, 1);
	cout << "\nModified Register Pile : " << rp << endl;
	cout << "Cycle Shift Right (result in register _b) : " << Calculator(rp, rb, ra, cycleShiftRight) << endl;
	cout << "\nCurrent Register Pile : " << rp << endl;

	rp.set(rb, 2);
	rp.set(ra, 29);
	cout << "\nModified Register Pile : " << rp << endl;
	cout << "Cycle Shift Right (result in register _b) : " << Calculator(rp, rb, ra, cycleShiftRight) << endl;
	cout << "\nCurrent Register Pile : " << rp << endl;
	
	cout << "\n============================= TASK 3 =============================" << endl;

	Matrix<double> m0;
	m0(0, 0) = 15;

	Matrix<double>m2(std::move(m0));
	cout << "Matrix created by moving constructor : " << endl << m2 << endl;
	m2(1, 1) = 9;

	m0 = std::move(m2);
	cout << "Matrix created by moving assignment : " << endl << m0 << endl;

	try {
		cout << "Trying to take an element out of bounds : " << endl;
		cout << m0(0, 3);
	}
	catch (Matrix<double>::BadMatrix& ex)
	{
		ex.diagnose();
	}


	Matrix<double> m;
	m(0, 0) = 1;
	m(0, 1) = 4.2;
	m(1, 0) = -3.7;
	m(1, 1) = 2.5;

	Matrix<double> m1;
	m1(0, 0) = 3;
	m1(0, 1) = -2;
	m1(1, 0) = 2.2;
	m1(1, 1) = 7.3;

	cout << endl << "MATRIX m : " << endl << m << endl;
	cout << "MATRIX m1 : " << endl << m1 << endl;


	Matrix<double> m3;
	m3 = (m1 + m);
	cout << endl << "m + m1 : " << endl << m3 << endl;

	m3 = (m1 - m);
	cout << "m1 - m : " << endl << m3 << endl;

	Matrix<double> mb(3, 2);
	mb(0, 0) = 1;
	mb(0, 1) = 4;
	mb(1, 0) = 2;
	mb(1, 1) = 3;
	mb(2, 0) = 4;
	mb(2, 1) = 5;
	cout << "MATRIX B :" << endl << mb << endl;

	Matrix<double> ma(2, 3);
	ma(0, 0) = 4;
	ma(0, 1) = 5;
	ma(0, 2) = 6;
	ma(1, 0) = 4;
	ma(1, 1) = 6;
	ma(1, 2) = 7;
	cout << "MATRIX A : " << endl << ma << endl;

	cout << endl << "B * A : " << endl << mb * ma << endl;


	Matrix<double> m01(4, 4);
	m01(0, 0) = 4.4;
	m01(0, 1) = 1.2;
	m01(0, 2) = 5;
	m01(0, 3) = 7;
	
	m01(1, 0) = 4;
	m01(1, 1) = -4.5;
	m01(1, 2) = -7;
	m01(1, 3) = -1;

	m01(2, 0) = -8;
	m01(2, 1) = 12;
	m01(2, 2) = 1;
	m01(2, 3) = 0;

	m01(3, 0) = 6;
	m01(3, 1) = 3.4;
	m01(3, 2) = -3.5;
	m01(3, 3) = 4.5;



	Matrix<double> m11(4, 4);


	m11(0, 0) = 3;
	m11(0, 1) = 3;
	m11(0, 2) = 2.2;
	m11(0, 3) = -5.6;

	m11(1, 0) = -7;
	m11(1, 1) = -2;
	m11(1, 2) = -6;
	m11(1, 3) = 5.6;

	m11(2, 0) = -1.2;
	m11(2, 1) = -5.8;
	m11(2, 2) = 11;
	m11(2, 3) = 9;

	m11(3, 0) = 1.2;
	m11(3, 1) = 7.6;
	m11(3, 2) = -7.2;
	m11(3, 3) = 3.4;

	cout << endl << "M0 : " << endl << m01 << endl;
	cout << endl << "M1 : " << endl << m11 << endl;

	cout << endl << "M0 * M1 : " << endl << m01 * m11 << endl;


	cout << "\n============================= TASK 4 =============================" << endl;

	Point a(1, -1);
	cout << a.mirrorPoint('x') << endl;
	cout << a.rotatePoint(180) << endl;
	cout << a.mirrorPoint('y') << endl;
	cout << a.mirrorPoint('x') << endl;
	cout << a.rotatePoint(-90) << endl;



	cout << "\n============================= TASK 5 =============================" << endl;

	Segment s(1, 1, 2, 2);
	cout << "MIRROR SEG " << s.mirrorSegment('x') << endl;
	cout << "ROTATE SEG " << s.rotateSegment(180) << endl;
	cout << "MIRROR SEG " << s.mirrorSegment('y') << endl;
	cout << "LENGTH : " << s.length() << endl;

	cout << "\n============================= TASK 6 (+TASK 9) =============================" << endl;


	TrapeziumAxes task6(0, 0, 1, 1, 3, 1, 4, 0);

	cout << task6 << endl;
	cout << "\nPERIMETER : " << task6.perimeter() << endl;
	cout << "AREA : " << task6.area() << endl;
	cout << "MIDDLE LINE : " << task6.middleLine() << endl;

	task6.rotateTrapezium(180);
	task6.mirrorTrapezium('x');

	cout << endl << "ROTATED(180) & MIRRORED(X) : " << endl << task6 << endl;
	cout << "PERIMETER : " << task6.perimeter() << endl;
	cout << "AREA : " << task6.area() << endl;
	cout << "MIDDLE LINE : " << task6.middleLine() << endl;

	cout << "\nSIDE AB :" << task6.side_AB() << endl;
	cout << "SIDE BC :" << task6.side_BC() << endl;
	cout << "SIDE CD :" << task6.side_CD() << endl;
	cout << "SIDE DA :" << task6.side_DA() << endl;

	cout << endl << "MIRRORED(Y) : " << endl;
	task6.mirrorTrapezium('y');
	cout << task6 << endl;


	cout << endl;
	try {
		TrapeziumAxes a(1, 0, 0, 1, 0, 3, 1.2, 4); //not parallel
	}
	catch (TrapeziumAxes::BadTrapeziumAxes & ex)
	{
		ex.diagnose();
	}

	try {
		TrapeziumAxes a(0, 0, 4, 0, 1, 1, 2, 1); //wrong axes order, as a result - crossed segments between bases
	}
	catch (TrapeziumAxes::BadTrapeziumAxes & ex)
	{
		ex.diagnose();
	}

	try {
		TrapeziumAxes a(0, 0, 0, 1, 1, 1, 1, 0); //square
	}
	catch (TrapeziumAxes::BadTrapeziumAxes & ex)
	{
		ex.diagnose();
	}


	cout << "\n============================= TASK 7 (+TASK 9) =============================" << endl;

	TrapeziumBase trb(1, 1, 2, 1, 3, 0, 0, 0);
	cout << trb << endl;
	cout << "AREA : " << trb.area() << endl;
	cout << "PERIMETER : " << trb.perimeter() << endl;
	cout << "MIDDLE LINE : " << trb.middleLine() << endl;
	trb.rotateTrapezium(180);
	trb.mirrorTrapezium('x');
	cout << endl << "ROTATED(180) & MIRRORED(X) : " << endl << trb << endl;
	cout << "AREA : " << trb.area() << endl;
	cout << "PERIMETER : " << trb.perimeter() << endl;
	cout << "MIDDLE LINE : " << trb.middleLine() << endl;


	cout << "\nSIDE AB :" << trb.side_AB() << endl;
	cout << "SIDE BC :" << trb.side_BC() << endl;
	cout << "SIDE CD :" << trb.side_CD() << endl;
	cout << "SIDE DA :" << trb.side_DA() << endl;

	cout << "\nAPEX A :" << trb.apexA() << endl;
	cout << "APEX B :" << trb.apexB() << endl;
	cout << "APEX C :" << trb.apexC() << endl;
	cout << "APEX D :" << trb.apexD() << endl;

	cout << endl << "MIRRORED(Y) : " << endl;
	trb.mirrorTrapezium('y');
	cout << trb << endl << endl;

	try {
		TrapeziumBase a(1,1,2,1,3,-0.4,0,0); //not parallel bases
	}
	catch (TrapeziumBase::BadTrapeziumBase& ex)
	{
		ex.diagnose();
	}

	
	Segment base1(2, 1, 1, 1);
	Segment base2(3, 0, 0, 0);
	try {
		TrapeziumBase a(base1, base2); //wrong axes order
	}
	catch (TrapeziumBase::BadTrapeziumBase & ex)
	{
		ex.diagnose();
	}

	Segment base3(0, 0, 0, 1);
	Segment base4(1, 1, 1, 0);
	try {
		TrapeziumBase a(base3, base4); //square
	}
	catch (TrapeziumBase::BadTrapeziumBase & ex)
	{
		ex.diagnose();
	}

	cout << endl << endl;



	cout << "\n============================= TASK 8 =============================" << endl;

	try {
		TrapeziumAxes a(1, 0, 0, 1, 0, 2, 1, 3);
		cout << "Trapezium Axes : \n" << a << endl;
		cout << "MIDDLE " << a.middleLine() << endl;
		cout << "AREA " << a.area() << endl;
		cout << "PERIMETER " << a.perimeter() << endl;
		TrapeziumBase tr(a);
		cout << "Trapezium Axes converted into Trapezium Base : \n" << tr << endl;
		cout << "MIDDLE " << tr.middleLine() << endl;
		cout << "AREA " << tr.area() << endl;
		cout << "PERIMETER " << tr.perimeter() << endl;
		TrapeziumAxes tra(tr);
		cout << "Trapezium Base converted into Trapezium Axes back : \n" << tra << endl;
		cout << "MIDDLE " << tra.middleLine() << endl;
		cout << "AREA " << tra.area() << endl;
		cout << "PERIMETER " << tra.perimeter() << endl;

	} catch(TrapeziumAxes::BadTrapeziumAxes& ex)
	{
		ex.diagnose();
	}

	cout << endl << endl;
	
	try {
		TrapeziumAxes a(1, 1, 1, 3, 3, 3, 5, 1);
		cout << "Trapezium Axes : \n" << a << endl;
		cout << "MIDDLE " << a.middleLine() << endl;
		cout << "AREA " << a.area() << endl;
		cout << "PERIMETER " << a.perimeter() << endl;
		TrapeziumBase tr(a);
		cout << "Trapezium Axes converted into Trapezium Base : \n" << tr << endl;
		cout << "MIDDLE " << tr.middleLine() << endl;
		cout << "AREA " << tr.area() << endl;
		cout << "PERIMETER " << tr.perimeter() << endl;
		TrapeziumAxes tra(tr);
		cout << "Trapezium Base converted into Trapezium Axes back : \n" << tra << endl;
		cout << "MIDDLE " << tra.middleLine() << endl;
		cout << "AREA " << tra.area() << endl;
		cout << "PERIMETER " << tra.perimeter() << endl;
		TrapeziumAxes copy(tra);
		cout << "Trapezium Axes created by Copy-Constructor : \n" << copy << endl;
	}
	catch (TrapeziumAxes::BadTrapeziumAxes & ex)
	{
		ex.diagnose();
	}

	cout << endl << endl;


	try {
		TrapeziumBase a(1,-2,1,-1,2,0,2,-2);
		cout << "Trapezium Base : \n" << a << endl;
		cout << "MIDDLE " << a.middleLine() << endl;
		cout << "AREA " << a.area() << endl;
		cout << "PERIMETER " << a.perimeter() << endl;
		TrapeziumAxes tr(a);
		cout << "Trapezium Base converted into Trapezium Axes : \n" << tr << endl;
		cout << "MIDDLE " << tr.middleLine() << endl;
		cout << "AREA " << tr.area() << endl;
		cout << "PERIMETER " << tr.perimeter() << endl;
		TrapeziumBase tra(tr);
		cout << "Trapezium Axes converted into Trapezium Base back : \n" << tra << endl;
		cout << "MIDDLE " << tra.middleLine() << endl;
		cout << "AREA " << tra.area() << endl;
		cout << "PERIMETER " << tra.perimeter() << endl;
	}
	catch (TrapeziumBase::BadTrapeziumBase& ex)
	{
		ex.diagnose();
	}

	cout << endl << endl;


	try {
		TrapeziumBase a(0, 1, 0, 2, 1, 3, 1, 0);
		cout << "Trapezium Base : \n" << a << endl;
		cout << "MIDDLE " << a.middleLine() << endl;
		cout << "AREA " << a.area() << endl;
		cout << "PERIMETER " << a.perimeter() << endl;
		TrapeziumAxes tr(a);
		cout << "Trapezium Base converted into Trapezium Axes : \n" << tr << endl;
		cout << "MIDDLE " << tr.middleLine() << endl;
		cout << "AREA " << tr.area() << endl;
		cout << "PERIMETER " << tr.perimeter() << endl;
		TrapeziumBase tra(tr);
		cout << "Trapezium Axes converted into Trapezium Base back : \n" << tra << endl;
		cout << "MIDDLE " << tra.middleLine() << endl;
		cout << "AREA " << tra.area() << endl;
		cout << "PERIMETER " << tra.perimeter() << endl;
		TrapeziumBase copy(tra);
		cout << "Trapezium Base created by Copy-Constructor : \n" << copy << endl;
	}
	catch (TrapeziumBase::BadTrapeziumBase & ex)
	{
		ex.diagnose();
	}

	cout << endl << endl;

	




	return 0;
}
