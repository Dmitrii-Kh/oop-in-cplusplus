#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	String a("I am first string! ");
	String b(a, 3);
	cout << "Multi-Constructor : " << endl;
	cout << b << endl << endl;

	cout << "Trying to create String object using nullptr : " << endl;
	const char* nullString = nullptr;

	try
	{
	  String testing(nullString);
	} catch(String::BadString e)
	{
		e.diagnose();
	}
	
	cout << "\n======================= INDEX OPERATOR TESTING =================================" << endl;
	try
	{
		cout << "\n'" << a << "' char at [0] : " << a[0] << endl;
		cout << "Trying to take a char at index 20 : ";
		cout << a << " char at [20] : " << a[20] << endl;
	}
	catch (String::BadIndex e)
	{
		e.diagnose();
	}

	try
	{
		a[0] = '*';
		cout << "\nTrying to modify a char at index 20 : ";
		a[20] = 's';
	}
	catch (String::BadIndex e)
	{
		e.diagnose();
	}

	cout << "Modified String object using index-operator : " << a << endl;
	

	cout << "\n======================= ASSIGNMENT OPERATOR TESTING =================================" << endl << endl;
	string ss = "I am STL_string";
	const char* ps = "I am C-string";
	char charA = 'A';
	
	String assign("assign");
	cout << assign << endl;
	
	assign = ss;
	cout << "now : " << assign << endl;
	assign = ps;
	cout << "now : " << assign << endl;
	assign = charA;
	cout << "now : " << assign << endl;

	cout << "\n======================= EQUAL/NOT EQUAL OPERATOR TESTING =================================" << endl << endl;
	String e1("aaa");
	String e2("aab");   
	String e3(e1);

	cout << boolalpha;

	cout << e1 << " == " << e2 << " : " << (e1 == e2) << endl;
	cout << e1 << " != " << e2 << " : " << (e1 != e2) << endl;

	cout << e1 << " == " << e3 << " : " << (e1 == e3) << endl;
	cout << e1 << " != " << e3 << " : " << (e1 != e3) << endl;

	cout << "\nMIXED OPERATIONS : " << endl;
	cout << e1 << " != " << ss << " : " << (e1 != ss) << endl;
	cout << ss << " != " << e1 << " : " << (ss != e1) << endl;

	cout << e1 << " == " << ps << " : " << (e1 == ps) << endl;
	cout << ps << " == " << e1 << " : " << (ps == e1) << endl;

	cout << "\n======================= >, >=, <=, < OPERATOR TESTING =================================" << endl << endl;

	String s11("Aba");
	String s12("Aac");
	
	string s13("Bc");
	auto * s14 = "Cc";
	
	String s15(s14);
	
	cout << s11 << " > " << s12 << " : " << (s11 > s12) << endl;
	cout << s11 << " < " << s12 << " : " << (s11 < s12) << endl;
	cout << s11 << " >= " << s12 << " : " << (s11 >= s12) << endl;
	cout << s11 << " <= " << s12 << " : " << (s11 <= s12) << endl;
	
	cout << "\nMIXED OPERATIONS : " << endl;
	cout << s15 << " <= " << s14 << " : " << (s15 <= s14) << endl;
	cout << s15 << " < " << s14 << " : " << (s15 < s14) << endl;
	cout << s14 << " <= " << s15 << " : " << (s14 <= s15) << endl;
	cout << s14 << " < " << s15 << " : " << (s14 < s15) << endl;
	
	cout << s13 << " >= " << s12 << " : " << (s13 >= s12) << endl;
	cout << s13 << " > " << s12 << " : " << (s13 > s12) << endl;
	cout << s12 << " >= " << s13 << " : " << (s12 >= s13) << endl;
	cout << s12 << " > " << s13 << " : " << (s12 > s13) << endl;

	cout << "\n======================= + / += OPERATOR TESTING =================================" << endl << endl;

	String s21("I am String to be concatinated!");
	String s22(s21);
	String s23("I am second String!");

	cout << s21 << " + " << s23 << " : " << (s21 + s23) << endl;

	s21 += s23;
	cout << "\nAssignment-Concatenation : "<< s21 << endl;

	s21.clear();
	s21 = s22;
	cout << "\nMIXED OPERATIONS : " << endl;
	cout << s21 << " + " << ps << " : " << (s21 + ps) << endl;
	cout << ps << " + " << s21 << " : " << (ps + s21) << endl;

	cout << s21 << " + " << ss << " : " << (s21 + ss) << endl;
	cout << ss << " + " << s21 << " : " << (ss + s21) << endl << endl;
	
	cout << s21 << " += " << ps << " : ";
	s21 += ps;
	cout << s21 << endl;
	s21.clear();
	s21 = s22;

	cout << s21 << " += " << ss << " : ";
	s21 += ss;
	cout << s21 << endl;

	cout << ss << " += " << s22 << " : ";
	ss += s22;
	cout << ss << endl;

	cout << s22 << " += " << charA << " : ";
	s22 += charA;
	cout << s22 << endl;

	cout << "Is  '" << s22 << "'  empty? : " << s22.isEmpty() << endl;
	s22.clear();
	cout << "Is  '" << s22 << "'  empty? : " << s22.isEmpty() << endl;
	cout << "\n============================================================================" << endl << endl;
	String asd("asd");
	const char* p = asd.c_str();
	cout << asd << endl;

	cout << p << endl;
	asd = p;
	cout << asd << endl;
	cout << p << endl;

}