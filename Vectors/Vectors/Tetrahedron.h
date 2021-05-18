#include "Point.h"

class Tetrahedron {
public:
	bool is_point_valid();
	Tetrahedron(Point a, Point b, Point c, Point d);
	Point getA();
	Point getB();
	Point getC();
	Point getD();
	void setA(Point a);
	void setB(Point b);
	void setC(Point c);
	void setD(Point d);
	bool is_ortogonal();
	bool operator<(Point point);
	bool operator>(Point point);
private:
	Point A;
	Point B;
	Point C;
	Point D;
};