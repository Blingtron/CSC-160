// File Name: lesson3-300-5.cpp
// Last Changed: 2/14/2016
// Student: Shane Kirkley

// Description: Gives the wind speed factor for temperatures less than 10 C.

#include <iostream>
#include <cmath>
using namespace std;

double windChill (double v, double t);
// v: the windspeed in m/s
// t: the temperature in degrees C (<=10)
// function: returns the windchill index using formula
// w = 13.12 + 0.6215 * t – 11.37 * v^0.16 + 0.3965 * t * v^0.16

int main()
{
    char quit;
    do
    {
        double v, t;

        cout << "Enter the temperature in Celsius (<= 10 C)" << endl;
        cin >> t;
        while (t > 10)
        {
            cout << "Temperature must be less than 10 C, try again." << endl;
            cin >> t;
        }

        cout << "Enter the wind speed (meters/second)" << endl;
        cin >> v;

        double w = windChill(v, t);

        cout << "The wind chill factor is " << w << "." << endl;
        cout << "Would you like to try again?" << endl;
        cout << "(Y/y for yes, anything else to quit)" << endl;
        cin >> quit;
    }
    while (quit == 'y' || quit == 'Y');
}

double windChill (double v, double t)
{
    double w = 13.12 + (0.6215 * t) - (11.37 * pow(v,0.16)) + (0.3965 * t * pow(v,0.16));
    return w;
}
