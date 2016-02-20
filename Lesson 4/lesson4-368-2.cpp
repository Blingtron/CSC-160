//file name: lesson4-368-2.cpp
//last changed: 2/17/2016
//student: Shane Kirkley

//description: Finds the average of values of type double from file "hw4pr01input.txt"

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


int main()
{
	ifstream in_stream;
	in_stream.open("hw4pr01input.txt");

	// If file doesn't exist
	if (in_stream.fail())
	{
	    cout << "Input file opening failed.\n";
	    exit(1);
	}

	double next;
	double sum = 0;
	int counter = 0;

    // Grab next number, add to sum and increment counter
    while(in_stream >> next)
    {
        sum = sum + next;
        counter++;
    }

    // Empty file check.
    if (counter == 0)
    {
        cout << "File is empty! Please put some values in the file :)\n";
        exit(1);
    }

    double average = sum / counter;

    cout << "The average of the " << counter << " numbers in the file is " << average << ".\n";
    in_stream.close();
    return 0;

}
