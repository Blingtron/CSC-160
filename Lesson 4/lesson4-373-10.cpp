//file name: lesson4-373-10.cpp
//last changed: 2/21/2016
//student: Shane Kirkley

//description: find the ranking of baby names

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

void fileErrorCheck(ios& stream);
// checks an in/out stream for file opening error.

void babyNameSearch(ifstream& inStream, string name);
// checks specified ifstream for a name, displays rank for boy and girl

string stringUpper(string str);
// Converts a string to uppercase.

int main()
{
    char quit;
    do
    {
        ifstream inFile;
        inFile.open("babynames2012.txt");
        fileErrorCheck(inFile);

        string inputName;

        cout << "Enter a name to check it's popularity in 2012. (not case sensitive)\n";
        cin >> inputName;

        babyNameSearch(inFile, inputName);
        cout << "Would you like to try another name?" << endl << "(enter y/Y for yes, anything else quits)\n";
        cin >> quit;
        quit = toupper(quit);
    }
    while (quit == 'Y');
}

string stringUpper(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void babyNameSearch(ifstream& inStream, string name)
{
    string girlName, boyName;
    int rank, boyFlag = 0, girlFlag = 0;
    // convert name to uppercase
    string nameUpper = stringUpper(name);
    while (!inStream.eof())
    {
        // get rank, boyName, girlName, convert to uppercase, check against input name, set flag if found
        inStream >> rank >> boyName >> girlName;
        boyName = stringUpper(boyName);
        girlName = stringUpper(girlName);
        if (nameUpper == boyName)
        {
            cout << name << " is ranked number " << rank << " for most popular boy names.\n";
            boyFlag++;
        }
        if (nameUpper == girlName)
        {
            cout << name << " is ranked number " << rank << " for most popular girl names.\n";
            girlFlag++;
        }
    }
    if (boyFlag == 0)
    {
        cout << name << " is not ranked on the most popular boy's name list.\n";
    }
    if (girlFlag == 0)
    {
        cout << name << " is not ranked on the most popular girl's name list.\n";
    }
}

void fileErrorCheck(ios& stream)
{
    if (stream.fail())
    {
        cout << "File opening failed.\n";
        exit(1);
    }
}
