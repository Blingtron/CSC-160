/* Section CSC 160 Comp Sci I : C++
** Name: SHANE KIRKLEY
** Student ID:
** File name: Lesson10-502-10.cpp
** Last Updated : 4/25/2016

** Array program that reads a file and counts the occurances of the numbers in the array and sorts them.

*/
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void check_input(ifstream& iPut);
void set_vector(ifstream& iPut, vector <int>& test);
void sort_vector(vector <int>& test);
void check_repeats(vector <int>& test);

int main()
{
    ifstream iPut;
    vector <int> test;

    cout << "Homework 10: Vector modification of solution to Chapter 7 Project 5" << endl;
    cout << "\n";

    iPut.open("hw10input.txt");

    check_input(iPut);

    set_vector(iPut, test);

    check_repeats(test);

    iPut.close();

    return 0;
}

void check_input(ifstream& iPut)
{
    if(iPut.fail())
    {
        cout << "Input file opening failed. \n";
        exit(1);
    }
}

void set_vector(ifstream& iPut, vector <int>& test)
{
    int input;
    while(iPut >> input)
    {
        test.push_back(input);
    }

    sort_vector(test); // Call to selecting sort to sort vector before output.

}

void sort_vector(vector <int>& test)
{
    int pos, mini, i;

    for (vector<int>::size_type place = 0; place < test.size(); ++place )
    {
        vector<int>::size_type mini = place;

        for ( vector<int>::size_type i = place + 1; i < test.size(); ++i )
        {
            if ( test[i] < test[mini] ) mini = i;
        }

        if ( mini != place )
        {
            swap( test[mini], test[place] );
        }
    }

}

void check_repeats(vector<int>& test)
{
    for(int i = 0; i < test.size(); i++)
    {
        int count = 0;
        int flag = 1;
        for (int j = 0; j < i; j++)
        {
            if (test[i] == test[j])
            flag += 1;
        }
            if ( flag == 1 )
            {
                for(int k = 0; k < test.size(); k++)
                {
                    if (test[i] == test[k])
                    count += 1;
                }

                cout << test[i] << " " << count << endl;
            }
      }
}
