//File Name: lesson1-105-5.cpp
//Description: Chapter 2 Practice Program Exercise 5
//Last Changed: 1/31/2016
//Student: Shane Kirkley

// This program fixes errors in the program presented in the text.

#include <iostream>
using namespace std;

int main()
{
    double radius, volume;
    cout << "Enter radius of a sphere." << endl;
    cin >> radius;
    volume = (4.0 / 3.0) * 3.1415 * radius * radius;
    cout << "The volume of the sphere is: : " << volume << "." << endl;
    return 0;
}
