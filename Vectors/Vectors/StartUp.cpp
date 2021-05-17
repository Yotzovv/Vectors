#include <iostream>
#include "Point.h"
#include "Line.h"
#include <vector>
#include "Vector.h"
#include "Triangle.h"
#include "Segment.h"

using namespace std;

int main()
{

	Point x(1, 0);
	Point y(1, 5);
	Point z(6, 0);

	Segment s1(x, y);
	Segment s2(y, z);
	Segment s3(z, x);

	double a = s1.find_segment_length();
	double b = s3.find_segment_length();
	double c = s2.find_segment_length();
	
	Triangle test = Triangle(x, y, z);
	test.get_triangle_type(x, y, z);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	/*double a{ 50.0 };
	double b{ 50.0000309449 };
	cout << boolalpha;
	if (a == b) {
		cout << "They're equal";
	}
	cout << "They're not equal";*/
}