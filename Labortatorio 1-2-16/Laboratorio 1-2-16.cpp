#include <iostream>
#include <string>
#include <math.h>

class Fraction {
public:
    Fraction(int numerator, int denominator);
    std::string toString();
    double toDouble();
private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator)
    : numerator(numerator), denominator(denominator)
{
    if (denominator == 0) {
        this->denominator = 1;
    }
}

std::string Fraction::toString() {
    std::string result = (numerator * denominator > 0) ? "" : "-";
    int wholes = abs(numerator) / abs(denominator);
    int parts = abs(numerator) % abs(denominator);

    if (parts == 0 && wholes == 0) {
        result = "0";
    }
    else {
        if (wholes > 0) {
            result += std::to_string(wholes);
        }
        if (wholes > 0 && parts > 0) {
            result += ' ';
        }
        if (parts > 0) {
            result += std::to_string(abs(parts)) + '/'
                + std::to_string(abs(denominator));
        }
    }
    return result;
}

double Fraction::toDouble() {
    return double (numerator) / denominator;
}

int main() {
    int numerator, denominator;
    char slash;
    std::string input;

        std::cout << "Enter a fraction (for example : 3 / 4): ";
        if (std::cin >> numerator >> slash >> denominator && slash == '/') {
            Fraction fraction(numerator, denominator);
            std::cout << fraction.toString() << " is "
                << fraction.toDouble() << " in decimal" << std::endl;
        }
        else {
            std::cout << "Unrecognized input format, try something more like : '3 / 4' pls" << std::endl;
        }

    return 0;
}
