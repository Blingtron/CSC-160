#include <iostream>
#include <string>

using namespace std;

class DigitalTimeException
{
public:
    DigitalTimeException(int error_number, string error_message);
        // Constructor used in DigitalTime for exceptions
    int errorNumber();
        // Returns the exception number
    string errorMessage();
        // Returns the exception message
private:
    int error_number;
    string error_message;
};
