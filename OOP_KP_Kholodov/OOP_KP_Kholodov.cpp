#include <iostream>
#include "AQueue.h"
#include "LQueue.h"
#include "Complex.h"
using namespace std;

int main()
{
	cout << "Array-based Queue Testing (basic type)" << endl;
	AQueue<int> a(5);
	cout << "Capacity : " << a.capacity() << endl;

	cout << boolalpha;
	cout << "empty : " << a.empty() << endl;
	cout << "full : " << a.full() << endl;
	cout << a.size() << endl;

	a.put(1);
	cout << "empty : " << a.empty() << endl;
	cout << a.front() << endl;

	a.pop();
	cout << "empty : " << a.empty() << endl;

	for (int i = 0; i < 5; ++i)
	{
		a.put(i);
	}

	try
	{
		a.put(5);
	}
	catch (AQueue<int>::BadAQueue& ex)
	{
		ex.diagnose();
	}

	cout << "full after adding : " << a.full() << endl;
	cout << "size : " << a.size() << endl;

	cout << a.front() << endl;
	a.pop();
	cout << a.front() << endl;
	a.pop();
	cout << a.front() << endl;

	cout << "empty now : " << a.full() << endl;
	cout << "size : " << a.size() << endl;


	{
		cout << "\n\nArray-based Queue Testing (Complex numbers)" << endl;

		AQueue<Complex> a(5);
		cout << "Capacity : " << a.capacity() << endl;

		cout << boolalpha;
		cout << "empty : " << a.empty() << endl;
		cout << "full : " << a.full() << endl;
		cout << a.size() << endl;

		a.put(1);
		cout << "empty : " << a.empty() << endl;
		cout << a.front() << endl;

		a.pop();
		cout << "empty : " << a.empty() << endl;

		for (int i = 0; i < 5; ++i)
		{
			a.put(i);
		}

		try
		{
			a.put(5);
		}
		catch (AQueue<Complex>::BadAQueue& ex)
		{
			ex.diagnose();
		}

		cout << "full after adding : " << a.full() << endl;
		cout << "size : " << a.size() << endl;

		cout << a.front() << endl;
		a.pop();
		cout << a.front() << endl;

		cout << "empty now : " << a.full() << endl;
		cout << "size : " << a.size() << endl;
	}

	cout << endl;

	cout << "\n\nList-based Queue Testing (basic type)" << endl;

	LQueue<int> lq;

	cout << boolalpha;
	cout << "empty : " << lq.empty() << endl;
	cout << "full : " << lq.full() << endl;
	cout << lq.size() << endl;

	lq.put(1);
	cout << "empty : " << lq.empty() << endl;
	cout << lq.front() << endl;

	lq.put(2);
	lq.put(3);

	cout << "full after adding : " << lq.full() << endl;
	cout << "size : " << lq.size() << endl;
	cout << "Capacity : " << lq.capacity() << endl;

	cout << lq.front() << endl;
	lq.pop();
	cout << lq.front() << endl;
	lq.pop();

	cout << "empty now : " << lq.full() << endl;
	cout << "size : " << lq.size() << endl;


	cout << "\n\nList-based Queue Testing (Complex numbers)" << endl;
	{
		LQueue<Complex> lq;

		cout << boolalpha;
		cout << "empty : " << lq.empty() << endl;
		cout << "full : " << lq.full() << endl;
		cout << lq.size() << endl;

		lq.put(1);
		cout << "empty : " << lq.empty() << endl;
		cout << lq.front() << endl;

		for (int i = 0; i < 5; ++i)
		{
			lq.put(i);
		}

		cout << "full after adding : " << lq.full() << endl;
		cout << "size : " << lq.size() << endl;
		cout << "Capacity : " << lq.capacity() << endl;


		cout << lq.front() << endl;
		lq.pop();
		cout << lq.front() << endl;
		lq.pop();


		cout << "empty now! : " << lq.empty() << endl;
		cout << "size : " << lq.size() << endl;
	}

	
	cout << "\n\nArray-based Unlimited Queue Testing (Complex numbers)" << endl;

	UnlimArrayQueue<Complex> uq(1);
	uq.put(9);
	uq.put(10);
	cout << uq.size() << endl;

	cout << "Capacity : " << uq.capacity() << endl;

	cout << boolalpha;
	cout << "empty : " << uq.empty() << endl;
	cout << "full : " << uq.full() << endl;
	cout << uq.size() << endl;


	for (int i = 0; i < 5; ++i)
	{
		uq.put(i);
	}

	cout << "full after adding : " << uq.full() << endl;
	cout << "size : " << uq.size() << endl;

	cout << uq.front() << endl;
	uq.pop();
	cout << uq.front() << endl;
	uq.pop();
	cout << uq.front() << endl;
	uq.pop();
	cout << uq.front() << endl;

	cout << "full now : " << uq.full() << endl;
	cout << "size : " << uq.size() << endl;

	return 0;
}

