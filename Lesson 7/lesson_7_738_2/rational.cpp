#include "rational.h"

using namespace std;

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}
Rational::Rational(int whole_number)
{
    numerator = whole_number;
    denominator = 1;
}
Rational::Rational(int _numerator, int _denominator)
{
    numerator = _numerator;
    denominator = _denominator;
    this -> reduce();
}

ostream& operator <<(ostream& output, const Rational& rational)
{
    output << rational.numerator << "/" << rational.denominator;
    return output;
}
istream& operator>>(istream& input, Rational& rational)
{
    char trash;
    input >> rational.numerator >> trash >> rational.denominator;
    if (trash != '/')
    {
        cout << "Error: character \"" << trash << "\" not accepted in rational definition. Please use form X/Y.\n";
        exit(1);
    }
    rational.reduce();
    return input;
}
Rational operator+(const Rational& rational1, const Rational& rational2)
{
    int a = rational1.numerator;
    int b = rational1.denominator;
    int c = rational2.numerator;
    int d = rational2.denominator;
    Rational temp(a * d + b * c, b * d);
    temp.reduce();
    return temp;
}
Rational operator-(const Rational& rational1, const Rational& rational2)
{
    int a = rational1.numerator;
    int b = rational1.denominator;
    int c = rational2.numerator;
    int d = rational2.denominator;
    Rational temp(a * d - b * c, b * d);
    temp.reduce();
    return temp;
}
Rational operator/(const Rational& rational1, const Rational& rational2)
{
    int a = rational1.numerator;
    int b = rational1.denominator;
    int c = rational2.numerator;
    int d = rational2.denominator;
    Rational temp(a * d, b * c);
    temp.reduce();
    return temp;
}
Rational operator*(const Rational& rational1, const Rational& rational2)
{
    int a = rational1.numerator;
    int b = rational1.denominator;
    int c = rational2.numerator;
    int d = rational2.denominator;
    Rational temp(a * c, b * d);
    temp.reduce();
    return temp;
}
bool operator>(const Rational& rational1, const Rational& rational2)
{
    return rational1.numerator * rational2.denominator > rational2.numerator * rational1.denominator;
}
bool operator<(const Rational& rational1, const Rational& rational2)
{
    return rational1.numerator * rational2.denominator < rational2.numerator * rational1.denominator;
}
bool operator<=(const Rational& rational1, const Rational& rational2)
{
    return rational1.numerator * rational2.denominator <= rational2.numerator * rational1.denominator;
}
bool operator>=(const Rational& rational1, const Rational& rational2)
{
    return rational1.numerator * rational2.denominator >= rational2.numerator * rational1.denominator;
}
bool operator==(const Rational& rational1, const Rational& rational2)
{
    return rational1.numerator * rational2.denominator == rational2.numerator * rational1.denominator;
}

void Rational::reduce()
{
    if (denominator == 0)
    {
        cout << "Error: Invalid rational definition. Denominator cannot be zero.";
        exit(1);
    }
    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    int a = abs(numerator);
    int b = denominator;
    int temp;

    if (b > a)
    {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0)
        {
            temp = b;
            b = a % b;
            a = temp;
        }
    numerator /= a;
    denominator /= a;
}

int Rational::getDenominator()
{
    return denominator;
}
int Rational::getNumerator()
{
    return numerator;
}
