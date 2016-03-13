//file name: lesson6_695_2.cpp
//last changed: 3/13/2016
//student: Shane Kirkley

//description: Defines a class rational that uses rational numbers as objects, with operator overloading.

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational();
    Rational(int whole_number);
    Rational(int _numerator, int _denominator);
        // constructors. Default: 0/1, One parameter: number/1
    friend ostream& operator<<(ostream& output, const Rational& rational);
    friend istream& operator>>(istream& input, Rational& rational);
    friend Rational operator+(const Rational& rational1, const Rational& rational2);
    friend Rational operator-(const Rational& rational1, const Rational& rational2);
    friend Rational operator/(const Rational& rational1, const Rational& rational2);
    friend Rational operator*(const Rational& rational1, const Rational& rational2);
    friend bool operator>(const Rational& rational1, const Rational& rational2);
    friend bool operator<(const Rational& rational1, const Rational& rational2);
    friend bool operator<=(const Rational& rational1, const Rational& rational2);
    friend bool operator>=(const Rational& rational1, const Rational& rational2);
    friend bool operator==(const Rational& rational1, const Rational& rational2);
        // operator overloaders
    void reduce();
        // reduces/simplifies a rational using gcd, moves negatives to the numerator.
    int getNumerator();
    int getDenominator();
};

   //---- Main function
int main()
{
    char quit;
    do
    {
        Rational test1,test2;
        cout << "Enter first test rational number in form X/Y.\n";
        cin >> test1;
        cout << "Enter second test rational number in form X/Y.\n";
        cin >> test2;
        cout << "~~ beginning rational number operator test ~~" << endl << endl;
        cout << "addition: " << test1 << " + " << test2 << " = " << test1 + test2 << "." << endl;
        cout << "subtraction: " << test1 << " - " << test2 << " = " << test1 - test2 << "." << endl;
        cout << "multiplication: " << test1 << " * " << test2 << " = " << test1 * test2 << "." << endl;
        cout << "division: " << test1 << " / " << test2 << " = " << test1 / test2 << "." << endl;
        if (test1 >= test2)
        {
            cout << test1 << " >= " << test2 << endl;
        }
        if (test1 <= test2)
        {
            cout << test1 << " <= " << test2 << endl;
        }
        if (test1 < test2)
        {
            cout << test1 << " < " << test2 << endl;
        }
        if (test1 > test2)
        {
            cout << test1 << " > " << test2 << endl;
        }
        if (test1 == test2)
        {
            cout << test1 << " == " << test2 << endl << endl;
        }
        cout << "test complete. Enter Y/y to test again, anything else quits.\n";
        cin >> quit;
    }
    while (toupper(quit) == 'Y');
}

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
