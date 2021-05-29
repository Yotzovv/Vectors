#include "Point.h"

class Triangle : public Point {
public:
	Triangle();
	Triangle(Point x, Point y, Point z);
	Triangle(std::queue<std::string> cmds);
	Point getX();
	Point getY();
	Point getZ();
	void setX(Point x);
	void setY(Point y);
	void setZ(Point z);
	Point get_incenter(Point x, Point y, Point z); // medicentyr
	Point get_incenter(); // medicentyr
	double get_area();
	double get_area(Point x, Point y, Point z);
	double get_perimeter();
	bool is_point_valid();
	double get_mid_side(double a, double b, double c);
	bool is_triangle_isosceles(); // ravnobedren
	bool is_triangle_equilateral(); // ravnostranen
	bool is_triangle_right(Point x, Point y, Point z);
	bool is_triangle_acute();
	bool is_triangle_obtuse(Point x, Point y, Point z);
	void get_triangle_type(Point x, Point y, Point z); // dali e ostrougulen, tupougulen ili pravougulen
	void get_triangle_type(); // dali e ostrougulen, tupougulen ili pravougulen
	bool operator<(Point point);
	bool operator>(Point point);
	bool operator==(Point point);
	std::ostream& ins(std::ostream&) const;
	std::istream& ext(std::istream&);
private:
	Point X;
	Point Y;
	Point Z;
};