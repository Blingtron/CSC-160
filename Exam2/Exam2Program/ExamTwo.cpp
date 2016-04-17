---------------------------------------------------------------------------
 CSC160 Exam Two - ExamTwo.cpp
---------------------------------------------------------------------------
#include <iostream>

#include "Date.h"
#include "DateException.h"
using namespace std;
using namespace ExamTwo;
int main()
{
    try
    {
        Date testOne(2, 27, 2012), testTwo, testThree;
        Date oneWeek(7), oneDay(1);
        for (int count = 0; count < 5; count++)
        {
            try
            {
                cout << "\n\nThe starting date is " << testOne;
                testTwo = testOne + oneWeek;
                cout << "\nOne week later is : " << testTwo;
                testThree = testTwo - oneDay;
                cout << "\nOne day before that is : " << testThree;
            }
            catch (DateException e)
            {
                cout << "Exception: " << e.errorMessage() << endl;
            }
            testOne = testOne + 30;
        }
    }
    catch (DateException e)
    {
        cout << "Exception: " << e.errorMessage() << endl;
    }
    catch (int e)
    {
        cout << "Exception: " << e << endl;
    }
    catch (...)
    {
        cout << "Exception Encountered" << endl;
    }
    cout << endl
    system("PAUSE");
    return 0;
}

