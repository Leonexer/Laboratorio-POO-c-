#include <iostream>
#include <string>
#include <sstream>
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

double FarmAnimal::getWaterConsumption() {return water_consumption;}

// ---- Derived animal classes ----
class Sheep : public FarmAnimal {
public:
    Sheep(double weight)
        : FarmAnimal(1.1 * (weight / 10.0)) {}
};

class Horse : public FarmAnimal {
public:
    Horse(double weight)
        : FarmAnimal(6.8 * (weight / 100.0)) {}
};

class Cow : public FarmAnimal {
public:
    Cow(double weight)
        : FarmAnimal(8.6 * (weight / 100.0)) {}
};

// ---- ConsumptionAccumulator ----
class ConsumptionAccumulator {
public:
    ConsumptionAccumulator();
    double getTotalConsumption();
    void addConsumption(FarmAnimal& animal);
private:
    double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() : total_consumption(0) {}

double ConsumptionAccumulator::getTotalConsumption() {
    return total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal& animal) {
    total_consumption += animal.getWaterConsumption();
}

// ---- Main ----
int main() {
    ConsumptionAccumulator accumulator;
    string line;

    while (true) {
        std::cout << "Enter your animal and its weight, for example: sheep 50" << endl;
        getline(cin, line);
        if (line.empty()) break; //Menú con getline que para al dejar una linea vacía

        stringstream ss(line);
        string type;
        double weight;

        ss >> type >> weight;
        if (type == "end") { break; }
        if (type == "sheep") {
            Sheep s(weight);
            accumulator.addConsumption(s);
            cout << "Your sheep will consume " << s.getWaterConsumption() << " liters of water per day" << endl;
        }
        else if (type == "horse") {
            Horse h(weight);
            accumulator.addConsumption(h);
            cout << "Your horse will consume " << h.getWaterConsumption() << " liters of water per day" << endl;
        }
        else if (type == "cow") {
            Cow c(weight);
            accumulator.addConsumption(c);
            cout << "Your cow will consume " << c.getWaterConsumption() << " liters of water per day" << endl;
        }
        else {
            cout << "Unknown animal: " << type << endl;
        }

        cout << "Your total liter consumption per day is: " << accumulator.getTotalConsumption() << endl << endl;
    }

    return 0;
}
