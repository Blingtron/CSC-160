//File Name: lesson1-104-2.cpp
//Description: Chapter 2 Practice Program exercise 2
//Last Changed: 1/31/2016
//Student: Shane Kirkley

// This program calculates the Babylonian square root of a number
// using 100 iterations.

#include <iostream>
using namespace std;

int main()
{
   double n;

   cout << "What number would you like to estimate the square root of?\n";
   cin >> n;

   double guess = n/2;

   int count = 100;
   while (count > 0)
   {
      double r = n/guess;
      guess = (guess + r)/2;
      count = count - 1;
   }
   cout << "\nThe estimated square root of " << n << " is " << guess << ".\n";

   return 0;



}
