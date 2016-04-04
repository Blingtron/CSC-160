#include <iostream>
#include "Student.h"
#include "StudentException.h"
using namespace std;

int main()
{
    cout << "Testing the handling of student exceptions...\n\n";
    try
    {
    Student studentTest1("S0993842");
    Student studentTest2("S0135823");
    Student studentTest3("S0234567");
    cout << "3 students created successfully.\n\n";
    studentTest1.enroll("CSC-160-001");
    studentTest1.enroll("ART-290-004");
    studentTest2.enroll("BUS-290-004");
    studentTest3.enroll("MAT-255-001");
    cout << "Testing complete! No exceptions thrown.";
    }
    catch (StudentException err)
    {
        cout << err.errorMessage();
    }
    catch (...)
    {
        cout << "Unknown exception occured. Oh no!";
    }

}
