#include "Point.h"

class Triangle {
public:
	Triangle(Point x, Point y, Point z);
	Point getX();
	Point getY();
	Point getZ();
	void setX(Point x);
	void setY(Point y);
	void setZ(Point z);
	Point get_centroid(Point x, Point y, Point z); // medicentyr
	double get_area();
	double get_area(Point x, Point y, Point z);
	double get_perimeter();
	bool is_point_valid();
	double get_mid_side(double a, double b, double c);
	bool is_triangle_iscoleses(Point x, Point y, Point z); // ravnobedren
	bool is_triangle_equilateral(Point x, Point y, Point z); // ravnostranen
	bool is_triangle_right(Point x, Point y, Point z);
	bool is_triangle_acute(Point x, Point y, Point z);
	bool is_triangle_obtuse(Point x, Point y, Point z);
	void get_triangle_type(Point x, Point y, Point z); // dali e ostrougulen, tupougulen ili pravougulen
	bool operator<(Point point);
	bool operator>(Point point);
	bool operator==(Point point);
private:
	Point X;
	Point Y;
	Point Z;
};