// File Name: lesson3-245-3.cpp
// Last Changed: 2/14/2016
// Student: Shane Kirkley

// Description: Gives the total value of the users stock, given a mixed number stock price.

#include <iostream>
using namespace std;

double stockPrice(int whole, int numerator, int denominator);
// Returns the value of a single stock, based on the user defined mixed number price

int main()
{
    cout << "This program will calculate the total value of your stocks, given" << endl;
    cout << "the number of stocks and price in whole + fraction format" << endl << endl;
    char quit;
    do
    {
        int whole, numerator, denominator;
        int quantity;

        cout << "Please enter the value of a single stock in the" << endl;
        cout << "order whole, numerator, denominator." << endl;
        cout << "(for example, if the value is 10 5/8, enter 10 then 5 then 8)" << endl;
        cin >> whole >> numerator >> denominator;

        cout << "Please enter the number of stocks that you own." << endl;
        cin >> quantity;

        double unitValue = stockPrice(whole, numerator, denominator);
        double totalValue = unitValue * quantity;

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout << quantity << " stocks at a value of $" << unitValue << " each brings the total" << endl;
        cout << "value of your stocks to $" << totalValue << "." << endl << endl;
        cout << "Would you like to try again?" << endl;
        cout << "(Enter Y/y for yes, anything else to quit.)" << endl;
        cin >> quit;
        cout << endl;
    }
    while(quit == 'Y' || quit == 'y');
}

double stockPrice(int whole, int numerator, int denominator)
{
    double price = whole + static_cast<double>(numerator)/denominator;
    return price;
}
