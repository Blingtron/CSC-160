#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Rational
{
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

    private:
    int numerator;
    int denominator;
};

#endif // RATIONAL_H

