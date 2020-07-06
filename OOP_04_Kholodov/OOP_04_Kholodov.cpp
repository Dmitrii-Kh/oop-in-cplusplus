#include <iostream>
#include "AComplex.h"
#include "TComplex.h"
using namespace std;

int main()
{
	AComplex b(2, -3);
	AComplex c(1, 4);
	TComplex bt(b);
	TComplex ct(c);

	/*cout << "Enter b : " << endl;
	cin >> b;
	cout << "Enter c : " << endl;
	cin >> c;
	*/

	cout << "============ ALGEBRAIC OPERATIONS USING TYPE CONVERSION ============" << endl;
	cout << "\nMULTIPLICATION" << endl;
	AComplex d = b * c;
	cout << b << " * " << c << "; Result : " << d << endl;
	cout << b  << " * " << c << "; Result (in TComplex form) : " << "Mod : " << d.mod() << "; Arg :" << d.arg() << endl;
	TComplex e = bt * ct;
	cout << bt << " * " << ct << "; Result : " << e << endl;
	cout << b << " * " << c << "; Result (in AComplex form) : " <<" Re : " << e.re() << "; Im : " << e.im() << endl;

	cout << "\nDIVISION" << endl;
	AComplex dd = b / c;
	cout << b << " / " << c << "; Result : " << dd << endl;
	cout << b << " / " << c << "; Result (in TComplex form) : " << "Mod : " << dd.mod() << "; Arg :" << dd.arg() << endl;
	TComplex ee = bt / ct;
	cout << bt << " / " << ct << "; Result : " << ee << endl;
	cout << b << " / " << c << "; Result (in AComplex form) : " << " Re : " << ee.re() << "; Im : " << ee.im() << endl;

	cout << "\nADDITION" << endl;
	cout << bt << " + " << ct << " Result : " << bt + ct << endl;

	cout << "\nMIXED ADDITION" << endl;
	cout << b << " + " << ct << " Result : " << b + ct << endl;
	
	cout << "\nSUBSTRACTION" << endl;
	cout << bt << " - " << ct << " Result : " << bt - ct << endl;

	cout << "\nMIXED SUBSTRACTION" << endl;
	cout << bt << " - " << c << " Result : " << bt - c << endl;

	TComplex mixedMult = b;
	cout << "\nASSIGNMENT MULTIPLICATION" << endl;
	cout << b << " *= " << c << endl;
	cout <<"\nResult : " << (b *= c) << endl;

	cout << "\nMIXED ASSIGNMENT MULTIPLICATION (TComplex *= AComplex)" << endl;
	cout << mixedMult << " *= " << c << endl;
	cout << "\nResult : " << (mixedMult *= c) << endl;

	AComplex mixedDiv = mixedMult;
	cout << "\nASSIGNMENT DIVISION" << endl;
	cout << b << " /= " << c << endl;
	cout <<"\nResult : " << (b /= c) << endl;

	cout << "\nMIXED ASSIGNMENT DIVISION (AComplex /= TComplex)" << endl;
	cout << mixedDiv << " /= " << ct << endl;
	cout << "\nResult : " << (mixedDiv /= ct) << endl;

	cout << "\nASSIGNMENT ADDITION" << endl;
	cout << bt << " += " << ct << endl;
	cout <<  "\nResult : " << (bt += ct) << endl;

	cout << "\nASSIGNMENT SUBSTRACTION" << endl;
	cout << bt << " -= " << ct << endl;
	cout << "\nResult : " << (bt -= ct) << endl;

	cout << "\nPOWER" << endl;
	b.re() = 2;
	b.im() = 2;
	cout << b << "^3; \nResult : " << power(b, 3) << endl;
	cout << "\n========================== EQUAL / NOT EQUAL ================================\n";

	AComplex toComp1(1, -4);
	AComplex toComp2(-3, 4.4);
	cout << boolalpha;
	cout << toComp1 << " == " << toComp2 << " ? " << (toComp1 == toComp2) << endl;
	cout << toComp1 << " != " << toComp2 << " ? " << (toComp1 != toComp2) << endl;


	toComp2.re() = 1;
	toComp2.im() = -4;
	cout << "\nMODIFIED second complex number : " << endl;
	cout << "Re : " <<toComp2.re() << endl;
	cout << "Im : " << toComp2.im() << endl;
	cout << toComp1 << " == " << toComp2 << " ? " << (toComp1 == toComp2) << endl;
	cout << toComp1 << " != " << toComp2 << " ? " << (toComp1 != toComp2) << endl;

	cout << endl;
	toComp2.re() = 2;
	toComp2.im() = 7;
	cout << toComp1 << " conjugated : " << toComp1.conj() << endl;
	cout << toComp2 << " conjugated : " << toComp2.conj() << endl;

	cout << "\nTComplex modificators : " << endl;
	TComplex tt(toComp1);
	tt.mod() = 7.07;
	tt.arg() = 0.79;
	cout << "(Modified) Mod : " << tt.mod() << "; Arg : " << tt.arg() << endl;
	cout << "(Modified) Re : " << tt.re() << "; Im : " << tt.im() << endl;

	cout << "\n==========================================================\n";


	//Copy-Constructor, Conversion-Constructor, Assignment operator are tested *indirectly*
	//in implementations of utilities, as well as some operators.

	return 0;
}

