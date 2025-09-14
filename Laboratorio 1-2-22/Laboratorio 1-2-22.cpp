#include <iostream>

using namespace std;

class FarmAnimal {
public:
	FarmAnimal(double water_consumption);
	double getWaterConsumption();

private:
	double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption) {
	this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption() {
	return water_consumption;
}


class DummyAnimal : public FarmAnimal {
public:
	DummyAnimal();
};

DummyAnimal::DummyAnimal() :FarmAnimal(0.0)
{
}

int main() {
	DummyAnimal d;
	cout << "DummyAnimal water consumption: " << d.getWaterConsumption() << endl;
	return 0;
}