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
private:
	Point X;
	Point Y;
	Point Z;
	bool is_point_valid();
};