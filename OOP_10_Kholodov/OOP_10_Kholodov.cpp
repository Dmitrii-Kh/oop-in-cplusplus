#include <iostream>
#include "Sequence.h"
#include "Complex.h"
using namespace std;

int main()
{
	cout << boolalpha;

	Sequence<Complex> s0(10);
	cout << "\nSize : " << s0.size() << endl;
	cout << "Capacity : " << s0.capacity() << endl << endl;
	s0.add(4.2).add(5.3).add(6.4);


	cout << s0 << endl;
	cout << "Size : " << s0.size() << endl;
	cout << "Capacity : " << s0.capacity() << endl << endl;
	cout << "Contains 5.3 : " << s0.contains(5.3) << endl;
	cout << "Contains 5.4 : " << s0.contains(5.4) << endl;

	cout << "\nCut" << endl;
	s0.cut();
	cout << s0 << endl;
	cout << "Size : " << s0.size() << endl;
	cout << "Capacity : " << s0.capacity() << endl << endl;;
	s0.cut();
	cout << s0 << endl;
	cout << "Size : " << s0.size() << endl;
	cout << "Capacity : " << s0.capacity() << endl << endl;
	s0.cut();

	try {
		s0.cut();
	}
	catch (Sequence<Complex>::BadSeq& ex)
	{
		ex.diagnose();
	}
	cout << s0 << endl;
	cout << "Size : " << s0.size() << endl;
	cout << "Capacity : " << s0.capacity() << endl;
	cout << "Empty ? : " << s0.empty() << endl;
	cout << "Full ? : " << s0.full() << endl;
	s0.insert(4.1,0);
	cout << "\nInserted one more element" << endl;
	cout << "Empty ? : " << s0.empty() << endl;
	cout << "Full ? : " << s0.full() << endl << endl;
	s0.insert(2.1, 1);
	cout << s0 << endl;
	cout << "\nRemoving inside : ";
	s0.remove(1);
	cout << s0 << endl;

	cout << endl << endl;


	Sequence<double> s1(0);
	s1.add(1).add(2);
	cout << s1 << endl;
	cout << "Size : " << s1.size() << endl;
	cout << "Capacity : " << s1.capacity() << endl;
	s1.cut();
	cout << s1 << endl;
	cout << "Size : " << s1.size() << endl;
	cout << "Capacity : " << s1.capacity() << endl;

	try {
		cout << "\n1 element : " << s1[0] << endl;
		cout << "Trying to take 2nd element out of 1 : ";
		cout << "2 element : " << s1[1] << endl;
	}
	catch (Sequence<double>::BadSeq& ex)
	{
		ex.diagnose();
	}

	try {
		cout << "\nTrying to change 1 element : ";
		s1[0] = -13.2;
		cout << s1[0] << endl;
		cout << "Trying to change 2 element : ";
		s1[1] = 15.7;
		cout << s1[1] << endl;
	}
	catch (Sequence<double>::BadSeq& ex)
	{
		ex.diagnose();
	}


	s1.insert(14, 1);
	s1.insert(15.2, 2);
	cout << s1 << endl;

	cout << "\nInserting inside : ";
	s1.insert(17.1, 1);
	cout << s1 << endl;

	try {
		cout << "Trying to insert outside : ";
		s1.insert(-20.1, 8);
	}
	catch (Sequence<double>::BadSeq& ex)
	{
		ex.diagnose();
	}
	cout << "Size : " << s1.size() << endl;
	cout << "Capacity : " << s1.capacity() << endl;

	cout << "\nRemoving inside : ";
	s1.remove(1);
	cout << s1 << endl;

	cout << "Size : " << s1.size() << endl;
	cout << "Capacity : " << s1.capacity() << endl;

	try {
		cout << "Trying to remove outside : ";
		s1.remove(8);
	}
	catch (Sequence<double>::BadSeq& ex)
	{
		ex.diagnose();
	}

	s1.clear();
	cout << "\nClear" << endl;
	cout << "Size : " << s1.size() << endl;
	cout << "Capacity : " << s1.capacity() << endl << endl;

	cout << endl << endl;
	
	Sequence<char> s2;
	s2.add('a').add('b').add('c');
	cout << s2 << endl;
	cout << "\nCut" << endl;
	s2.cut();
	cout << s2 << endl;

	cout << "Inserted 'd' :" << endl;
	s2.insert('d', 1);
	cout << s2 << endl;

	cout << "Removed 'c' :" << endl;
	s2.remove(2);
	cout << s2 << endl;

	try {
		cout << "Trying to remove outside : ";
		s2.remove(4);
	}
	catch (Sequence<char>::BadSeq& ex)
	{
		ex.diagnose();
	}

	try {
		cout << "Trying to insert outside : ";
		s2.insert('g', 8);
	}
	catch (Sequence<char>::BadSeq& ex)
	{
		ex.diagnose();
	}

	cout << "Contains 'c' ? : " << s2.contains('c') << endl;

	cout << "Empty ? : " << s2.empty() << endl;
	cout << "Size : " << s2.size() << endl;
	cout << "Capacity : " << s2.capacity() << endl << endl;

	return 0;
}

