//The standard deviation of a list of numbers is a measure of how much the
//numbers deviate from the average. If the standard deviation is small, the
//numbers are clustered close to the average. If the standard deviation is large,
//the numbers are scattered far from the average.

//Define a function
//that takes a partially filled array of numbers as its arguments and returns
//the standard deviation of the numbers in the partially filled array. Since
//a partially filled array requires two arguments, the function will actually
//have two formal parameters: an array parameter and a formal parameter
//of type int that gives the number of array positions used. The numbers
//in the array will be of type double. embed your function in a suitable test
//program.

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double average(const double arr[], int size);
double std_dev(const double arr[], int size);
void getArrayValues(double arr[], const int max_size, int& actual_size);
// actual_size will be the size of the array input by user, and will be used in other functions as "size".
void printInfo(const double arr[], int size);

int main()
{
    char quit;
    int MAX_ARRAY_SIZE = 10;
    cout << "I will compute the average and standard deviation of the values entered." << endl;
    do
    {
        int size = 0;
        double test1[MAX_ARRAY_SIZE];
        getArrayValues(test1, MAX_ARRAY_SIZE, size);
        printInfo(test1, size);
        cout << "Try another set of values?\n(Y or y for yes, anything else quits.)" << endl;
        cin >> quit;
    }
    while (toupper(quit) == 'Y');
}

double average(const double arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

double std_dev(const double arr[], int size)
{
    double avg = average(arr, size);
    double variance = 0;

    for (int i = 0; i < size; i++)
    {
        variance += pow((arr[i]-avg),2);
    }
    return sqrt(variance/(size-1));
}

void getArrayValues(double arr[], const int max_size, int& actual_size)
{
    double temp;
    int size = 0;
    cout << "Enter up to " << max_size << " values, separated by white space, terminate input with a NEGATIVE number." << endl;
    for (int i = 0; i < max_size; i++)
    {
        cin >> temp;
        if (temp < 0)
            break;
        arr[i] = temp;
        size++;
    }
    actual_size = size;
}
void printInfo(const double arr[], int size)
{
        cout << "The mean of the values is: " << average(arr, size) << endl;
        cout << "The standard deviation of the values is: " << std_dev(arr, size) << endl << endl;
}
