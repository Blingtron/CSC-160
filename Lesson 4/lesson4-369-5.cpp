//file name: lesson4-369-5.cpp
//last changed: 2/17/2016
//student: Shane Kirkley

//description: gives programming advice from a file and allows user to overwrite that advice with their own.

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void printFile(istream& in_stream);
// prints the contents of the specified file stream.

void writeFile(ostream& out_stream);
// writes user input to the specified file stream. is not pretty function but it works.

int main()
{

    ifstream fileIn;
    ofstream fileOut;
    fileIn.open("hw4pr02input.txt");

    if(fileIn.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    cout << "Here is some advice from a fellow programmer:\n";
    printFile(fileIn);
    fileIn.close();

    fileOut.open("hw4pr02input.txt");

    if(fileOut.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    cout << "Now enter some new advice for other programmers.\n" << "Press enter twice to declare the end of your message.\n";
    writeFile(fileOut);
    fileOut.close();

    cout << "Thank you for the sage wisdom.\n";


}

void printFile(istream& in_stream)
{
    char nextSymbol;
    do
    {
        in_stream.get(nextSymbol);
        cout << nextSymbol;
    }
    while (!in_stream.eof());
}

void writeFile(ostream& out_stream)
{
    char nextSymbol;
    int quit = 1;
    while (quit == 1)
    {
    cin.get(nextSymbol);
    out_stream << nextSymbol;
    if (nextSymbol == '\n')
        {
            cin.get(nextSymbol);
            if (nextSymbol == '\n')
            {
                quit = 0;
            }
            out_stream << nextSymbol;
        }
    }
}
