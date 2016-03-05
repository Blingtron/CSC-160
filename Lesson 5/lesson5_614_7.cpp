//file name: lesson5_614_7.cpp
//last changed: 3/5/2016
//student: Shane Kirkley

//description: Defines a class rational that uses rational numbers as objects, with functions that do operations and stuff.
//              includes a repeatable user-input testing main function.

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class rational
{
public:
    // constructors
    rational(int a, int b);
    rational(int a);
    rational();

    void input(istream& instream);
        // gets rational number from specified input stream.
    void output(ostream& outstream);
        // outputs rational number to specified output stream.
    rational value();
        // returns the rational
    bool less(rational x);
        // returns true if the rational is less than the passed in rational x.
    bool eq(rational x);
        // returns true if the rational is equal to the passed in rational x.
    rational neg();
        // returns the negative of the rational.
    void reduce();
        // reduces fraction completely using greatest common denominator.
    rational add(rational x, bool reduce);
        // adds the rationals and returns the resulting rational, reduced if bool reduce is true.
    rational sub(rational x, bool reduce);
        // subtracts x from the rational and returns the resulting rational, reduced if bool reduce is true.
    rational mul(rational x, bool reduce);
        // multiplies the rationals and returns the resulting rational, reduced if bool reduce is true.
    rational div(rational x, bool reduce);
        // divides the rational by x, and returns the resulting rational, reduced if bool reduce is true.

private:
    int numerator;
    int denominator;
};

// main function
int main()
{
    rational test1;
    rational test2;
    rational sum, difference, product, quotient, negative;
    char quit, reduce_input;
    bool reduce_choice;

    do
    {
        cout << "Enter the first test rational in form X/Y." << endl;
        test1.input(cin);
        cout << "Enter the second test rational in form X/Y." << endl;
        test2.input(cin);
        cout << "Do you want the results in reduced form? (Y/y for yes, anything else for no)" << endl;
        cin >> reduce_input;
        if (toupper(reduce_input) == 'Y')
        {
            reduce_choice = true;
        }
        else reduce_choice = false;

            //test add
        test1.output(cout);
        cout << " + ";
        test2.output(cout);
        cout << " = ";
        test1.add(test2, reduce_choice).output(cout);
        cout << endl;
            //test sub
        test1.output(cout);
        cout << " - ";
        test2.output(cout);
        cout << " = ";
        test1.sub(test2, reduce_choice).output(cout);
        cout << endl;
            //test mul
        test1.output(cout);
        cout << " x ";
        test2.output(cout);
        cout << " = ";
        test1.mul(test2, reduce_choice).output(cout);
        cout << endl;
            //test div
        test1.output(cout);
        cout << " / ";
        test2.output(cout);
        cout << " = ";
        test1.div(test2, reduce_choice).output(cout);
        cout << endl;
            //test neg
        cout << "Negative function test:" << endl << "-1 * ";
        test1.output(cout);
        cout << " = ";
        test1.neg().output(cout);
        cout << endl;
            //test less
        cout << "Less and eq function test:" << endl;
        if (test1.less(test2))
        {
            test1.output(cout);
            cout << " is less than ";
            test2.output(cout);
            cout << "." << endl;
        }
        else if (test1.eq(test2))
        {
            test1.output(cout);
            cout << " is equal to ";
            test2.output(cout);
            cout << "." << endl;
        }
        else
        {
            test1.output(cout);
            cout << " is greater than ";
            test2.output(cout);
            cout << "." << endl;
        }

        cout << "\nTest other rationals?\n";
        cin >> quit;
    }
    while (toupper(quit) == 'Y');
}
// rational class constructor definitions
rational::rational()
{
    numerator = 0;
    denominator = 0;
}

rational::rational(int a, int b)
{
    if (b == 0)
    {
        cout << "Rational Initialization Error: Denominator cannot be zero.\n";
        exit(1);
    }
    if (b < 0)
    {
        a = -1 * a;
        b = abs(b);
    }
    numerator = a;
    denominator = b;
}

rational::rational(int a)
{
    numerator = a;
    denominator = 1;
}

// rational class member function definitions

rational rational::value()
{
    rational temp(numerator, denominator);
    return temp;
}

void rational::input(istream& instream)
{
    char slash;
    instream >> numerator >> slash >> denominator;
}

void rational::output(ostream& outstream)
{
    outstream << numerator << "/" << denominator;
}

bool rational::less(rational x)
{
    //(a/b) < (c/d) means (a * d) < (c * b)
    if ((numerator * x.denominator) < (x.numerator * denominator))
    {
        return true;
    }
    else return false;
}

bool rational::eq(rational x)
{
    rational temp(numerator,denominator);
    temp.reduce();
    x.reduce();
    if (x.numerator == temp.numerator && x.denominator == temp.denominator)
    {
        return true;
    }
    else return false;

}

rational rational::neg()
{
    rational temp(-1*numerator,denominator);
    return temp;
}

void rational::reduce()
{
    int a = abs(numerator);
    int b = abs(denominator);
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

rational rational::add(rational x, bool reduce)
{
    //a/b + c/d = (a * d + b * c) / (b * d)

    rational temp ;
    temp.numerator = (numerator * x.denominator + denominator * x.numerator);
    temp.denominator = (denominator * x.denominator);
    if (reduce == true)
    {
        temp.reduce();
    }
    return temp;

}

rational rational::sub(rational x, bool reduce)
{
    //a/b - c/d = (a * d - b * c) / (b * d)

    rational temp;
    temp.numerator = numerator * x.denominator - denominator * x.numerator;
    temp.denominator = denominator * x.denominator;
    if (reduce == true)
    {
        temp.reduce();
    }
    return temp;
}

rational rational::mul(rational x, bool reduce)
{
    //(a/b) * (c/d) = (a * c) / (b * d)

    rational temp;
    temp.numerator = numerator * x.numerator;
    temp.denominator = denominator * x.denominator;
    if (reduce == true)
    {
        temp.reduce();
    }
    return temp;
}

rational rational::div(rational x, bool reduce)
{
    //(a/b) / (c/d) = (a * d) / (c * b)

    rational temp;
    temp.numerator = numerator * x.denominator;
    temp.denominator = x.numerator * denominator;
    if (reduce == true)
    {
        temp.reduce();
    }
    return temp;
}
