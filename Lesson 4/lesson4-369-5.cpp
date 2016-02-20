//file name: lesson4-369-5.cpp
//last changed: 2/17/2016
//student: Shane Kirkley

//description: gives programming advice from a file and allows user to overwrite that advice with their own.

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream file_in;
    ofstream file_out;
    file_in.open("hw4pr02.input.txt");

    if(file_in.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }



}
