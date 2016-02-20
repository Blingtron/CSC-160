//File Name: lesson1-106-4.cpp
//Description: Chapter 2 Programming Project 4
//Last Changed: 1/31/2016
//Student: Shane Kirkley

//This program calculates the initial value needed in a discount loan
//to receive an entered amount.

#include <iostream>
using namespace std;

int main()
{
    double final_amount, interest_rate, period_months;
    char quit;

    cout << "This is a Discount Installment Loan Calculator." << endl;

    //enclose program in do-while loop so it can be run again without termination
    do
    {
    cout << "\nWhat is the loan amount that you need to receive?\n";
    cin >> final_amount;
    cout << "What is the interest rate on the loan? (i.e. 0.10 = 10%)\n";
    cin >> interest_rate;
    cout << "What is the loan period in months?\n";
    cin >> period_months;
    cout << endl;

    //convert months to years
    double period_years = period_months / 12;

    //solve for principle
    double principle = final_amount / ( 1 - interest_rate * period_years);

    //calculate payment per month
    double payment = principle / period_months;

    // Ensure output displays in standard dollar format
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "You will need a loan with a face value of $" << principle << "." << endl;
    cout << "Your monthly payment will be $" << payment << "." << endl << endl;

    cout << "Would you like to calculate a new loan?\n";
    cout << "(Enter Y for yes or N for no)\n";
    cin >> quit;
    }
    while (quit == 'Y' || quit == 'y');

    return 0;
}
