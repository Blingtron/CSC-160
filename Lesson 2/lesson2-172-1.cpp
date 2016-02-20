// File Name: lesson2-172-1.cpp
// Last Changed: 2/7/2016
// Student: Shane Kirkley

// Description: This program plays rock paper scissors between two players and keeps score.

#include <iostream>
using namespace std;

// these functions are just for less typing later
void p1_wins(char p1_choice, char p2_choice)
{
    cout << p1_choice << " beats " << p2_choice << "! Player one wins!" << endl << endl;
}
void p2_wins(char p1_choice, char p2_choice)
{
    cout << p2_choice << " beats " << p1_choice << "! Player one wins!" << endl << endl;
}

int main()
{
    char p1_choice, p2_choice, quit;
    int p1_score = 0;
    int p2_score = 0;

    do
    {
        //get user variables
        cout << endl << "Player One, please enter either R)ock, P)aper, or S)cissors." << endl;
        cin >> p1_choice;
        cout << "Player Two, please enter either R)ock, P)aper, or S)cissors." << endl;
        cin >> p2_choice;

        //case for tie
        if (p1_choice == p2_choice)
        {
            cout << "It's a tie!" << endl;
        }
        else if (p1_choice == 'R' || p1_choice == 'r')
        {
            if (p2_choice == 'S' || p2_choice == 's')
            {
                p1_wins(p1_choice, p2_choice);
                p1_score++;
            }
            else
            {
                p2_wins(p1_choice, p2_choice);
                p2_score++;
            }
        }
        else if (p1_choice == 'S' || p1_choice == 's')
        {
            if (p2_choice == 'P' || p2_choice == 'p')
            {
                p1_wins(p1_choice, p2_choice);
                p1_score++;
            }
            else
            {
                p2_wins(p1_choice, p2_choice);
                p2_score++;
            }
        }
        else
        {
            if (p2_choice == 'R' || p2_choice == 'r')
            {
                p1_wins(p1_choice, p2_choice);
                p1_score++;
            }
            else
            {
                p2_wins(p1_choice, p2_choice);
                p2_score++;
            }
        }
        //display score, prompt to play again
        cout << "The current score is:\n";
        cout << "     Player One: " << p1_score << endl;
        cout << "     Player Two: " << p2_score << endl;
        cout << "Would you like to play again?\n" << "(Enter Y/y for yes or anything else to quit.)\n";
        cin >> quit;
    }
    while (quit == 'Y' || quit == 'y');

    return 0;
}
