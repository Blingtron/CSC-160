//file name: lesson10-498-2.cpp
//student: Shane Kirkley
//date modified: 4/24/16

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
string convertToPig(string first, string last);
    // returns a string that is the full name converted to pig latin.
void lowerCase(string& text);
    // changes the string to lowercase.
bool vowelCheck(string t);
    // returns true if the first letter of the string is a lowercase vowel (a,e,i,o,u)
void stringShift(string& text);
    // moves the first letter of the text to the end of the text, shifts other characters to beginning.

int main()
{
    char quit;
    string first;
    string last;

    do
    {
        cout << "Enter your first name.\n";
        cin >> first;
        cout << "Enter your last name.\n";
        cin >> last;
        string piggy = convertToPig(first,last);
        cout << "Your Pig Latin name is " << piggy << "." << endl;
        cout << "Try another name?\n";
        cin >> quit;
    }
    while (toupper(quit) == 'Y');
}

string convertToPig(string first, string last)
{
    string pig_name;

    if (vowelCheck(first))
    {
        pig_name = first + "way ";
    }
    else
    {
        lowerCase(first);
        stringShift(first);
        first[0] = toupper(first[0]);
        pig_name = first + "ay ";
    }
    if (vowelCheck(last))
    {
        pig_name = pig_name + last + "way";
    }
    else
    {
        lowerCase(last);
        stringShift(last);
        last[0] = toupper(last[0]);
        pig_name = pig_name + last + "ay";
    }
    return pig_name;
}

void lowerCase(string& text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }
}

bool vowelCheck(string t)
{
    if (t[0]=='a' || t[0]=='e' || t[0]=='i' || t[0]=='o' || t[0]=='u')
    {
        return true;
    }
    else return false;
}

void stringShift(string& text)
{
    char temp = text[0];
    for(int i=0; i < text.length(); i++)
    {
        text[i] = text[i+1];
    }
    text.erase(text.length()-1, 1);
    text = text + temp;
}
