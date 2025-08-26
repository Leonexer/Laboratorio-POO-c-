#include <iostream>
#include <string>

using namespace std;

class Square
{
public:
	Square(double side);

	void set_side(double side)
	{
		this->side = side;
		this->area = side * side;
	}

	void print()
	{
		cout << "Square: side = " << this->side << " area = " << this->area << endl;
	}

	// Your code here
private:
	double    side;
	double    area;
};

Square::Square(double side)
{
	set_side(side);
}


int main()
{
	Square s(4);


	s.print();

	s.set_side(2.0);
	s.print();

	s.set_side(-33.0);
	s.print();

	return 0;
}