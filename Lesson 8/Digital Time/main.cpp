#include "DigitalTime.h"
#include "DigitalTimeException.h"

using namespace std;

int main()
{
    try
    {
        DigitalTime test(59,2555);
    }
    catch (DigitalTimeException thisError)
    {
        cout << "Exception Number " << thisError.errorNumber() << ": ";
        cout << thisError.errorMessage();
    }

    try
    {
        DigitalTime digTest;
        cout << "Enter time.\n";
        cin >> digTest;
    }
    catch (DigitalTimeException thisError)
    {
        cout << "Exception Number " << thisError.errorNumber() << ": ";
        cout << thisError.errorMessage();
    }
}
