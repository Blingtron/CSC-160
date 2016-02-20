// File Name:lesson2-176-6.cpp
// Last Changed: 2/7/2016
// Student: Shane Kirkley

// Description: This program finds the amount of green crud with user
//              specified time period and initial amount of green crud.

#include <iostream>
using namespace std;

int main()
{
    char quit;
    int growthPeriod = 5;

    do
    {
        int totalTime = 0;
        int initialCrud = 0;

        // get variables
        cout << "Enter the initial pounds of green crud." << endl;
        cin >> initialCrud;
        cout << "Enter the number of days for the crud to reproduce." << endl;
        cin >> totalTime;

        // find number of periods
        int periods = totalTime / growthPeriod;

        // fibonacci variables
        int oldCrud = 0;
        int currentCrud = initialCrud;
        int nextCrud;

        // fibonacci loop
        for (int i = 0; i < periods; i++)
        {
            nextCrud = currentCrud + oldCrud;
            oldCrud = currentCrud;
            currentCrud = nextCrud;
        }

        // print result, prompt user to try again
        cout << "After " << totalTime << " days, there should be " << currentCrud;
        cout << " pounds of crud scumming the pond." << endl;
        cout << "Would you like to try again? (Y/y for yes, anything else for no)" << endl;
        cin >> quit;
    }
    while (quit == 'Y' || quit == 'y');

}
