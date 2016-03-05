//file name: lesson5_611_1.cpp
//last changed: 3/5/2016
//student: Shane Kirkley

//description: defines a CD Account class with functions that do stuff to the account.

#include <iostream>

using namespace std;

class CDAccount
{
public:
    CDAccount(double initial_balance, double interest, int term_months);
        // creates CDAccount with given balance, interest, and term.

    CDAccount();
        // default constructor: creates CDAccount with $0.00 balance, 0 % interest, and 0 term.

    double get_initial_balance();
        // returns the initial balance of the account.

    double get_mature_balance();
        // returns the balance of the account after maturity.

    int get_term();
        // returns the number of months to maturity on the account.

    double get_interest_rate();
        // returns the interest rate on the account.
    void setBalance(double _balance);
    void setTerm(int _term);
    void setInterestRate(double rate);

private:
    double balance;
    double interest_rate;
    int term;
};

int main()
{
    cout << "This is a test of the CDAccount class." << endl;
    CDAccount account1;
    double test_balance, test_rate;
    int test_term;
    cout << "Enter the balance, interest rate(decimal), and term as a space seperated list. (example: 8000 .08 24)" << endl;
    cin >> test_balance >> test_rate >> test_term;
    account1.setBalance(test_balance);
    account1.setTerm(test_term);
    account1.setInterestRate(test_rate);
    cout << "The initial balance of the account is $" << account1.get_initial_balance() << endl;
    cout << "The interest rate on the account is " << account1.get_interest_rate() << endl;
    cout << "The term of the account is " << account1.get_term() << " months." << endl;
    cout << "The value of the matured CD Account is $" << account1.get_mature_balance();



}

CDAccount::CDAccount()
{
    balance = 0;
    interest_rate = 0;
    term = 0;
}

CDAccount::CDAccount(double initial_balance, double interest, int term_months)
{
    balance = initial_balance;
    interest_rate = interest;
    term = term_months;
}

double CDAccount::get_initial_balance()
{
    return balance;
}

double CDAccount::get_interest_rate()
{
    return interest_rate;
}

double CDAccount::get_mature_balance()
{
    return balance + (interest_rate * balance * (term/12));
}

int CDAccount::get_term()
{
    return term;
}

void CDAccount::setBalance(double _balance)
{
   balance = _balance;
}

void CDAccount::setInterestRate(double rate)
{
    interest_rate = rate;
}

void CDAccount::setTerm(int _term)
{
    term = _term;
}
