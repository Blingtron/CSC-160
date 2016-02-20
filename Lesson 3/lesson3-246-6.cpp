// File Name: lesson3-246-6.cpp
// Last Changed: 2/14/2016
// Student: Shane Kirkley

// Description: Give the interest due on a compounding credit account.

#include <iostream>
using namespace std;

double interestDue(double initialBalance, double interestRate, double duration);
// initialBalance: Balance of account in dollars
// interestRate: interest rate in decimal form
// duration: amount of months for which interest is due
// function: returns the interest due for a compounding interest credit account

int main()
{
    cout << "This program calculates the interest due on a compounding credit card account." << endl;
    char quit;
    do
    {
        double initialBalance, interestRate, duration;

        cout << "Enter the initial balance on the account." << endl;
        cin >> initialBalance;
        cout << "Enter the interest rate in decimal format for the account. (i.e 10% = .10)" << endl;
        cin >> interestRate;
        cout << "Enter the number of months for which interest must be paid." << endl;
        cin >> duration;

        double interest = interestDue(initialBalance, interestRate, duration);

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout << "The interest accumulated on the account is $" << interest << "." << endl;
        cout << "Would you like to try again?" << endl;
        cout << "(Enter Y/y for yes, anything else to quit)" << endl;
        cin >> quit;
    }
    while (quit == 'Y' || quit == 'y');
}

double interestDue(double initialBalance, double interestRate, double duration)
{
    double balance = initialBalance;
    double totalInterest = 0;

    for (int i = 0; i < duration; i++)
    {
        totalInterest = totalInterest + (balance * interestRate);
        balance = balance + (balance * interestRate);
    }
    return totalInterest;
}
