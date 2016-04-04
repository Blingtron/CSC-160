#include "DigitalTimeException.h"

using namespace std;

DigitalTimeException::DigitalTimeException(int number, string message)
{
    error_number = number;
    error_message = message;
}

string DigitalTimeException::errorMessage()
{
    return error_message;
}

int DigitalTimeException::errorNumber()
{
    return error_number;
}
