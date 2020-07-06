#include <iostream>
#include "Segment.h"
using namespace std;

int main()
{
	cout << "Default constructor : " << endl;
	Segment sDefault;
	cout << endl;
	cout << "Length of " << sDefault << " : " << sDefault.length() << endl;
	cout << endl;

	cout << "Coordinates constructor : " << endl;
	Segment sCoord(1, 1, 4, 4);
	cout << endl;
	cout << "Length of " << sCoord << " : " << sCoord.length() << endl;
	cout << endl;

	cout << "Start-End points constructor : " << endl;
	Point pStart(-2, -2);
	Point pEnd(8, 8);
	Segment sPoints(pStart, pEnd);
	cout << endl;
	cout << "Length of " << sPoints << " : " << sPoints.length() << endl;
	cout << endl;

	cout << "Copy-Constructor  ( newSegment(Segment 2) ): " << endl;
	Segment sCopy(sCoord);
	cout << endl;

	cout << "Assignment operator ( newSegment = Segment 1 ) : " << endl;
	Segment sAssign = sDefault;
	cout << endl;

	Segment smSegment(-5, 5, 6, 8);
	cout << "\nSelectors-Modificators : " << endl;
	cout << smSegment << endl;
	cout << "Starting point : " << smSegment.start() << endl;
	cout << "Starting point X coordinate : " << smSegment.startX() << endl;
	cout << "Starting point Y coordinate : " << smSegment.startY() << endl;
	cout << "Ending point : " << smSegment.end() << endl;
	cout << "Ending point X coordinate : " << smSegment.endX() << endl;
	cout << "Ending point Y coordinate : " << smSegment.endY() << endl;

	smSegment.startX() = -6;
	cout << "Starting point X coordinate (modified) : " << smSegment.startX() << endl;
	smSegment.endY() = 5;
	cout << "Ending point Y coordinate (modified) : " << smSegment.endY() << endl;

	const Segment segConst;
	cout << "Constant Segment ID : " << segConst.getID() << endl;
	//segConst.startX() = 5;
	cout << "Constant Segment starting point : " << segConst.start() << endl;
	cout << endl;

	cout << "Length of " << smSegment << " : " << smSegment.length() << endl;

	Point destination(1, 0);
	cout << "Distance FROM :  " << smSegment << "  TO  " << destination << " : " << smSegment.distance(destination) << endl;
	cout << "OPTIONAL Distance FROM :  " << smSegment << "  TO  " << destination << " : " << distance(smSegment, destination) << endl;
	cout << endl;

	Segment pythagorian(0, 3, 4, 0);
	cout << "Length of " << pythagorian << " : " << pythagorian.length() << endl;
	cout << endl;

	Point destination2(5, -1);
	cout << "Distance FROM :  " << pythagorian << "  TO  " << destination2 << " : " << pythagorian.distance(destination2) << endl;
	cout << "OPTIONAL Distance FROM :  " << pythagorian << "  TO  " << destination2 << " : " << distance(pythagorian, destination2) << endl;
	cout << endl;

	cout << "Distance FROM :  " << sDefault << "  TO  " << smSegment.end() << " : " << sDefault.distance(smSegment.end()) << endl;
	cout << "OPTIONAL Distance FROM :  " << sDefault << "  TO  " << smSegment.end() << " : " << distance(sDefault, smSegment.end()) << endl;
	cout << endl;

	return 0;
}
