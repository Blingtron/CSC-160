#include "rational.h"

using namespace std;

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
