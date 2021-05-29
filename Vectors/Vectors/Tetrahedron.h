#include "Point.h"

class Tetrahedron : public Element {
public:
	bool is_point_valid();
	Tetrahedron();
	Tetrahedron(std::queue<std::string> cmds);
	Tetrahedron(Point a, Point b, Point c, Point d);
	Point getA();
	Point getB();
	Point getC();
	Point getD();
	void setA(Point a);
	void setB(Point b);
	void setC(Point c);
	void setD(Point d);
	bool is_tetrahedron_regular();
	bool is_ortogonal();
	double find_surrounding_surface();
	double get_volume();
	bool operator<(Point point);
	bool operator>(Point point);
	bool operator==(Point point);
	std::ostream& ins(std::ostream&) const;
	std::istream& ext(std::istream&);
	std::queue<std::string> _Commands;
private:
	Point A;
	Point B;
	Point C;
	Point D;
	bool is_tetrahedron_regular();
};