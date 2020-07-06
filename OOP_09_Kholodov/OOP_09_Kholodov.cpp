#include <iostream>
#include "Array.h"
#include "Complex.h"
using namespace std;

int main()
{
	Array<5, double> a;
	for (int i = 0; i < 5; ++i)
	{
		a[i] = i;
	}
	cout  << "'a' arr : "<< a << endl;

	Array<5, double> b(a);

	cout << boolalpha;
	cout << "'b' arr : " <<b << endl;
	cout << "\na == b : "<< (a == b) << endl;
	cout << "a != b : " << (a != b) << endl;


	Array<5, double> c;
	for (int i = 0; i < 5; ++i)
	{
		c[i] = i * i;
	}
	
	cout << "\nc : " << c << endl;
	cout << "\na == c : " << (a == c) << endl;
	cout << "a != c : " << (a != c) << endl;
	
	a = c;
	cout << "\na arr after assignment : " << a << endl;

	try
	{
		cout << "\nTrying to take a 5th element out of 5 : " << endl;
		cout << a[4] << endl;
		cout << "\nTrying to take a 6th element out of 5 : " << endl;
		cout << a[5] << endl;
	}
	catch (Array<5, double>::BadArray& ex)
	{
		ex.diagnose();
	}

	try
	{
		cout << "\nTrying to change a 10th element out of 5 : " << endl;
		a[9] = 10;
	}
	catch (Array<5, double>::BadArray& ex)
	{
		ex.diagnose();
	}
	
	cout << "\nb : " << b << endl;
	cout << "a : " << a << endl;
	
	cout << "res a * b : " << a * b << endl;
	cout << "res a * 2 : " << a * 2 << endl;
	cout << "res 2 * b : " << 2 * b << endl;
	cout << "res a + b : " << a + b << endl;

	cout << "size of 'a' arr: " << a.size() << endl;

	Array<8, Complex> carr;
	
	carr[1].re() = 1;
	carr[1].im() = 7;

	carr[2].re() = 3;
	carr[2].im() = 5;

	carr[6].re() = 6;
	carr[6].im() = 3;

	cout << "\nfirst Complex arr : "<< endl << carr << endl;

	Array<8, Complex> carr2(carr);
	
	carr2[0].re() = 2;
	carr2[0].im() = 2;

	carr2[1].re() = -1;
	carr2[1].im() = -4;
	
	carr2[3].re() = 4;
	carr2[3].im() = 3;
	
	cout << "second Complex arr : " << endl << carr2 << endl;

	cout << "\ncarr == carr2 : " << (carr == carr2) << endl;
	cout << "carr != carr2 : " << (carr != carr2) << endl;
	
	cout << "\ncarr + carr2 : " << carr + carr2 << endl;
	cout << "\ncarr * carr2 : " << carr * carr2 << endl;
	cout << "\ncarr * 3 : " << carr * 3 << endl;
	cout << "\n2.5 * carr2 : " << 2.5 * carr2 << endl;

	cout << "size of first arr : " << carr.size() << endl;

	cout << endl << "Array to be tested : " << carr << endl;
	try
	{
		cout << "\nTrying to take a 2nd element out of 8 : " << endl;
		cout << carr[1] << endl;
		cout << "\nTrying to take a 9th element out of 8 : " << endl;
		cout << carr[8] << endl;
	}
	catch (Array<8, Complex>::BadArray& ex)
	{
		ex.diagnose();
	}

	try
	{
		cout << "\nTrying to change the 3rd element : " << endl;
		carr[2].re() = 12;
		carr[2].im() = 14;
		cout << carr[2] << endl;
		
		cout << "\nTrying to change the 12th element : " << endl;
		carr[11].re() = 12;
	}
	catch (Array<8, Complex>::BadArray& ex)
	{
		ex.diagnose();
	}

	const Array<8, Complex> carr3;
	carr = carr3;
	cout << "\nfirst Complex array after assignment : " << carr << endl;

	cout << "\nMoving constructor and assignment testing" << endl;
	cout << "Array before assignment : " << carr2 << endl;
	carr2 = create<8, Complex>();
	cout << "Array after assignment : " << carr2 << endl;

	return 0;
}