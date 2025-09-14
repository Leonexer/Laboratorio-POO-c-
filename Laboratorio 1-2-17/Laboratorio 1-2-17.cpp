#include <iostream>
#include <string>
#include <math.h>


int MaxComunMultiploRec(int a, int b) 
{
    if (b == 0) return a;
    return MaxComunMultiploRec(b, a % b);
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int numerator, int denominator);
    int getNumerator() { return numerator; }
    int getDenominator() { return denominator; }

    std::string toString();
    double toDouble();
    void printFraction();

    Fraction add(Fraction Adding);
    Fraction substract(Fraction Substrahend);
    Fraction multiply(Fraction Factor);
    Fraction divide(Fraction divisor);
    void reduce();
};

Fraction::Fraction() 
{
    this->denominator = 1;
    this->numerator = 0;
}

Fraction::Fraction(int numerator, int denominator)
    : numerator(numerator), denominator(denominator)
{
    if (denominator == 0) {
        this->denominator = 1;
    }
}

std::string Fraction::toString() 
{
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

double Fraction::toDouble() 
{
    return double(numerator) / denominator;
}

void Fraction::printFraction() 
{
    reduce();
    std::cout << toString() << " is "<< toDouble() << " in decimal" << std::endl << std::endl;
}

Fraction Fraction::add(Fraction adding)
{
    return Fraction((getNumerator() * adding.getDenominator() + adding.getNumerator() * getDenominator()), (getDenominator() * adding.getDenominator()));
}

Fraction Fraction::substract(Fraction substrahend)
{
    return Fraction((getNumerator() * substrahend.getDenominator() - substrahend.getNumerator() * getDenominator()), (getDenominator() * substrahend.getDenominator()));
}

Fraction Fraction::multiply(Fraction factor)
{
    return Fraction((getNumerator() * factor.getNumerator()), (getDenominator() * factor.getDenominator()));
}

Fraction Fraction::divide(Fraction dividend)
{
    return Fraction((getNumerator() * dividend.getDenominator()), (getDenominator() * dividend.getNumerator()));
}


void Fraction::reduce() {
    int divisor = MaxComunMultiploRec(abs(numerator), abs(denominator));
    numerator /= divisor;
    denominator /= divisor;
}

int main() {
    Fraction fraction[2];
    int numerator, denominator;
    char slash;
    std::string input;

    for (int i = 0;i < 2;i++)
    {
        std::cout << "Enter a fraction (for example : 3 / 4): ";
        if (std::cin >> numerator >> slash >> denominator && slash == '/')
        {
            fraction[i] = Fraction(numerator, denominator);
            fraction[i].printFraction();
        }
        else {
            std::cout << "Unrecognized input format, try something more like : '3 / 4' pls" << std::endl;
        }
    }

    std::cout << fraction[0].toString() << " plus " << fraction[1].toString() << std::endl;
    (fraction[0].add(fraction[1])).printFraction();

    std::cout << fraction[0].toString() << " minus " << fraction[1].toString() << std::endl;
    (fraction[0].substract(fraction[1])).printFraction();

    std::cout << fraction[0].toString() << " times " << fraction[1].toString() << std::endl;
    (fraction[0].multiply(fraction[1])).printFraction();

    std::cout << fraction[0].toString() << " by " << fraction[1].toString() << std::endl;
    (fraction[0].divide(fraction[1])).printFraction();

    return 0;
}