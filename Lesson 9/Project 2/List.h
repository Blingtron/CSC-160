#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_ARRAY_SIZE = 5;

class List
{
private:
    double arr[MAX_ARRAY_SIZE];
    int arr_size;
public:
    List();
        //constructs a List object with the size of static int MAX_ARRAY_SIZE.
    void addValue(double number);
        // appends number to the end of the List array.
    double getLast();
        //returns the last item on the list.
    void deleteLast();
        //"deletes" the last item on the list by setting it to 0 and decrementing arr_size.
    int getSize();
        //return the size of the list.
    double getValue(int position);
        //returns the value at position in the array.
    void printList();
        //outputs the values of the list.
    bool isFull();
        //returns TRUE if the List array is full (determined by static int MAX_ARRAY_SIZE)
};
