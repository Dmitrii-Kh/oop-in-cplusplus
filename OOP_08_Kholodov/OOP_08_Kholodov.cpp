#include <iostream>
#include "Screen.h"
using namespace std;

int main()
{
	const size_t size = 10;
	Screen demo(size, size);

	cout << "Empty screen created" << endl << endl;
	demo.show();

	for (size_t i = 0; i <= size; i++)
		demo.set('*').move(i, i);

	cout << "The screen filled" << endl << endl;

	for (int i = 0; i <= size; i++)
		demo.move(size - i - 1, i).set('*');

	demo.show();

	////////////////////////////////////////////////
	
	cout << "\nSCREEN" << endl << endl;

	const int height = 10;
	const int width = 20;
	
	Screen sc(width, height, "Hello, I am Screen");
	const char* chToSet = "Was it a cat I saw?";
	
	sc.move(3, 1);
	
	for (unsigned int i = 0; i < strlen(chToSet); ++i)
	{
		sc.set(chToSet[i]).move();
	}

	cout << sc << endl;

	for (unsigned int i = 0; i < strlen(chToSet); ++i)
	{
		cout << sc.back().get();
	}

	sc.home();
	cout << endl << endl;
	sc.set('*');
	
	for (int i = 0; i < 18; ++i)
	{
		sc.showCurrent().move();
	}
	sc.clear();
	doActionNonConst(sc, &Screen::move, 4);
	sc.show();


	cout << "\nCONST SCREEN" << endl << endl;

	const Screen scc(width, height, "Hello, I am Const Screen!");
	const char* chToSet2 = "Was it a cat I saw?";

	scc.move(3, 1);

	/*for (int i = 0; i < strlen(chToSet2); ++i)
	{
		scc.set(chToSet[i]).move();
	}*/

	cout << scc << endl;

	/*for (int i = 0; i < strlen(chToSet2); ++i)
	{
		cout << scc.back().get();
	}*/

	scc.home();
	//scc.set('*');

	/*for (int i = 0; i < 18; ++i)
	{
		scc.showCurrent().move();
	}*/
	//scc.clear();
	
	doActionConst(scc, &Screen::move, 4);
	scc.show();


	
	
	/*const NonConstAction menuNonConst[] = { &Screen::home, &Screen::move, &Screen::back, &Screen::clear};
	const ConstAction menuConst[] = { &Screen::home, &Screen::move, &Screen::back, &Screen::show};

	Screen v(20, 10);
	const Screen cv(20, 10);
	
	size_t  k, n; char ch;
	cout << "\nMenu Non Const" << endl;
	v.show();
	
	do {
		cout << "your action? (0-home : 1-move : 2-back : 3-clear : 4-moveToPoint : 5-set) :";
		cin >> k;
		if (k < 4) {
			cout << "multiplicity? : ";
			cin >> n;
			doActionNonConst(v, menuNonConst[k], n);
		}
			
		if(k==4)
		{
			cout << "Enter coordinates : ";
			int x, y;
			cout << "Enter X (row) : ";
			cin >> x;
			cout << "Enter Y (column) : ";
			cin >> y;
			v.move(x, y);
		}
		
		if (k == 5)
		{
			char chh;
			cout << "Enter character : ";
			cin >> chh;
			v.set(chh);
		}

		cout << "Repeat(y/n)? : ";
		cin >> ch;
		
	} while (ch == 'y');
	v.show();


	
	cout << "\nMenu Const" << endl;
	cv.show();

	do
	{
		cout << "your action? (0-home : 1-move : 2-back : 3-show : 4-moveToPoint) : ";
		cin >> k;
		
		if (k < 4) {
			cout << "multiplicity? : ";
			cin >> n;
			doActionConst(cv, menuConst[k], n);
		}
		
		if (k == 4)
		{
			cout << "Enter coordinates : ";
			int x, y;
			cout << "Enter X (row) : ";
			cin >> x;
			cout << "Enter Y (column) : ";
			cin >> y;
			cv.move(x, y);
		}

		cout << "Repeat(y/n)? : ";
		cin >> ch;
		
	} while (ch == 'y');
	cv.show();*/


	return 0;
}

