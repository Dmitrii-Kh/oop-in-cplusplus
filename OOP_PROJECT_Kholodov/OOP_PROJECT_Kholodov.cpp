#include <iostream>
#include "Matrix.h"
#include "Complex.h"
using namespace std;

int main()
{
	Matrix<double> m0;
	m0(0, 0) = 15;

	Matrix<double>m2(std::move(m0));
	cout << endl << m2 << endl;
	m2(1, 1) = 9;

	m0 = std::move(m2);
	cout << endl << m0 << endl;

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


	Matrix<Complex> mc(3, 3);
	mc(0, 0) = 2.2;
	mc(0, 0).im() = 2.2;

	mc(0, 1) = 3.3;
	mc(0, 2) = 4.4;

	mc(1, 0) = 5.5;
	mc(1, 0).im() = 5.5;

	mc(1, 1) = 6.6;
	mc(1, 1).im() = 6.6;

	mc(1, 2) = 7.7;
	mc(2, 0) = 8.8;
	mc(2, 1) = 9.9;
	mc(2, 2) = 10.10;
	mc(2, 2).im() = 10.10;

	cout << endl << "Complex Matrix : " << endl << mc << endl;
	cout << endl << "\nMatCompl * 2 : " << endl << mc * 2 << endl;
	cout << endl << "\n3.5 * MatCompl : " << endl << 3.5 * mc << endl;

	cout << "\n2.0 * (MatCompl + MatCompl) * 2.0" << endl << 2. * (mc + mc) * 2. << endl;
	cout << "\nMatCompl * 3 - 2 * MatCompl" << endl << (mc * 3) - (2 * mc) << endl;


	{

		Matrix<Complex> m01(4, 4);
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



		Matrix<Complex> m11(4, 4);


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
	}

	Matrix<Complex> mbad;
	
	try {
		cout << "\nTrying to put an element out of bounds : " << endl;
		mbad(3, 3) = 0;
	}
	catch (Matrix<Complex>::BadMatrix& ex)
	{
		ex.diagnose();
	}

	cout << "\nOriginal Matrix : \n" << mc;
	cout << "\nTransposed Matrix : \n" << transpose(mc) << endl;

	cout << boolalpha;
	cout << (mc == mc) << endl;
	cout << (mc == (transpose(mc))) << endl;
	cout << (mc != mc) << endl;
	cout << (mc != (transpose(mc))) << endl;

	return 0;
}

