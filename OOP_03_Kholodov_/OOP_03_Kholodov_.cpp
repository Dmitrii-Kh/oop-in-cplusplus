#include "Triangle.h"
#include "T_Segment.h" 
#include <iostream>
using namespace std;

int main()
{
	Triangle t;

	cout << "\nApex A : " << t.apexA() << "; Apex B : " << t.apexB() << ";  Apex C : " << t.apexC() << endl << endl;
	cout << "Side A : " << t.side_a() << endl;
	cout << "Side B : " << t.side_b() << endl;
	cout << "Side C : " << t.side_c() << endl << endl;

	cout << "Length of side A : " << t.length_a() << endl;
	cout << "Length of side B : " << t.length_b() << endl;
	cout << "Length of side C : " << t.length_c() << endl << endl;

	cout << "\n========================= MEDIANS ===========================\n" << endl;

	cout << "\nMedian A : " << t.median_a() << endl << endl;
	cout << "\nMedian B : " << t.median_b() << endl << endl;
	cout << "\nMedian C : " << t.median_c() << endl << endl;

	cout << "\nMedian C length (exempli gratia) : " << t.median_c().length() << endl << endl;

	cout << "\nArea : " << t.area() << endl;
	cout << "Perimeter : " <<t.perimeter() << endl;
	

	cout << "\n====================== OTHER CONSTRUCTORS ========================\n" << endl;

	cout << "Copy-Constructor : " << endl;
	Triangle t1(t);

	cout << "\nSegment & Point Constructor : " << endl;
	Segment s(2,1,4,1);
	Point p(6, 6);
	Triangle t2(p, s);

	cout << "\nPoint Constructor : " << endl;
	Point p1;
	Point p2(3, 4);
	Point p3(0, 2);
	Triangle t3(p1,p2,p3);

	cout << "\nAssignment Operator : " << endl;
	Triangle tAssign = t3;
	cout << endl;

	Triangle tAssign2;
	tAssign2 = t2;
	cout << "Modified : " << tAssign2 << endl;

	cout << "\n======================== MODIFICATORS ===========================\n" << endl;

	cout << "\nBefore modification : "<< t1 << endl;
	cout << "Side A : " << t1.side_a() << endl;
	cout << "Side B : " << t1.side_b() << endl;
	cout << "Side C : " << t1.side_c() << endl;

	t1.apexA().x()=2;
	t1.apexA().y() = 2;

	t1.apexB().x() = 4;
	t1.apexB().y() = 2;

	t1.apexC().x() = 3;
	t1.apexC().y() = 4;

	cout << "\nModified :" << t1 << endl;
	cout << "Modified side A : " << t1.side_a() << endl;
	cout << "Modified side B : " << t1.side_b() << endl;
	cout << "Modified side C : " << t1.side_c() << endl;

	cout << "\nTotal amount of triangles created : " << Triangle::getAmount() << endl;
	cout << "\n============================ ***** ===============================\n" << endl;
	
	return 0;
}


