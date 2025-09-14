#include <iostream> 
#include <string>
#include <math.h>


class Point2D {
public:
	Point2D(double x, double y);
	Point2D();
	std::string toString();

	double getX() { return x; }
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
	std::string Wasa = std::to_string(x) + " , " + std::to_string(y);
	return Wasa;
}

double Point2D::distanceTo(Point2D that)
{
	double diffX = x - that.getX();
	if (diffX < 0) { diffX *= (-1); }

	double diffY = y - that.getY();
	if (diffY < 0) { diffY *= (-1); }

	return sqrt(pow(diffX, 2) + pow(diffY, 2));
}

class Line2D {
public:
	Line2D(Point2D, Point2D);
	double getSlope() { return slope; }
	double getYIntersect() { return yIntersect; }
	Point2D getPointA() { return pointA; }
	Point2D getPointB() { return pointB; }
	std::string toString();


private:
	Point2D pointA;
	Point2D pointB;
	double slope;
	double yIntersect;
};

Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	this->pointA = pointA;
	this->pointB = pointB;
	slope = ((pointB.getY() - pointA.getY()) / (pointB.getX() - pointA.getX()));
	yIntersect = (pointA.getY() - slope * pointA.getX());
}

std::string Line2D::toString() {
	return "Line2D -> PointA(" + pointA.toString() +
		"), PointB(" + getPointB().toString() +
		"), slope = " + std::to_string(slope) +
		", yIntersect = " + std::to_string(yIntersect);
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

		Line2D LineAB(Points[0], Points[1]);
		std::cout << "The distance between point " << Points[0].toString() << " and point " << Points[1].toString() << " is " << Points[0].distanceTo(Points[1]) << std::endl;
		
		std::cout << "Line ecuation: Y = " << LineAB.getSlope() << "x +" << LineAB.getYIntersect()<< std::endl;
		
		std::cout << LineAB.toString() << std::endl;

	}
}


// implement Point2D methods