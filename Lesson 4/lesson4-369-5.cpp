//file name: lesson4-369-5.cpp
//last changed: 2/17/2016
//student: Shane Kirkley

//description: gives programming advice from a file and allows user to overwrite that advice with their own.

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void printFile(ifstream& in_stream);
// prints the contents of the specified file stream.

void writeFile(ofstream& out_stream);
// writes user input to the specified file stream. is not pretty function but works.

void fileErrorCheck(ios& stream);
// checks an in/out stream for file opening error.

int main()
{
    ifstream fileIn;
    ofstream fileOut;
    fileIn.open("hw4pr02input.txt");
    fileErrorCheck(fileIn);

    cout << "Here is some advice from a fellow programmer:\n";
    printFile(fileIn);

    fileOut.open("hw4pr02input.txt");
    fileErrorCheck(fileOut);

    cout << "\nNow enter some new advice for other programmers.\n" << "Press enter twice to declare the end of your message.\n\n";
    writeFile(fileOut);

    cout << "Thank you for your sage wisdom.\n";
}

void printFile(ifstream& in_stream)
{
    char nextSymbol;
    do
    {
        in_stream.get(nextSymbol);
        cout << nextSymbol;
    }
    while (!in_stream.eof());
    in_stream.close();
}

void writeFile(ofstream& out_stream)
{
    // figure out cleaner way to do this
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
    out_stream.close();
}

void fileErrorCheck(ios& stream)
{
    if (stream.fail())
    {
        cout << "File opening failed.\n";
        exit(1);
    }
}

