#include <iostream> 
#include <string>
#include <math.h>


class Point2D {
public:
	Point2D(double x, double y);
	Point2D();
	std::string toString();

	double getX(){ return x; }
	double getY() { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }

	double distanceTo(Point2D that);
private:
	double x;
	double y;
};


Point2D::Point2D()
{
	this->x = 0;
	this->y = 0;
}

Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

std::string Point2D::toString()
{
	std::string PointString = std::to_string(x) + " , " + std::to_string(y);
	return PointString;
}

double Point2D:: distanceTo(Point2D that)
{
	double diffX = x - that.getX();
	if (diffX < 0) { diffX *= (-1); }

	double diffY = y - that.getY();
	if (diffY < 0) { diffY *= (-1); }

	return sqrt(pow(diffX, 2) + pow(diffY, 2));
}
int main() {
	Point2D Points[2];
	std::string input = " ";
	double pointX;
	double pointY;
	char comma;

	while (input != "exit")
	{
		for (int i = 0; i < 2;i++) {
			std::cout << "Please provide a point in (3,4) format: ";
			std::cin >> pointX >> comma >> pointY;

			if (comma == ',') 
			{
				Points[i] = Point2D(pointX, pointY);
			}

			std::cout << "Added point " << Points[i].toString() << std::endl;
		}
		std::cout << "The";
		std::cout << "The distance between point " << Points[0].toString() << " and point " << Points[1].toString() << " is " << Points[0].distanceTo(Points[1]) << std::endl;
	}
}
	

// implement Point2D methods