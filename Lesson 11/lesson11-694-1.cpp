//In Chapter 8 we discussed vectors, which are like arrays that can grow in
//size. Suppose that vectors were not defined in C++. Define a class called
//VectorDouble that is like a class for a vector with base type double. Your
//class VectorDouble will have a private member variable for a dynamic
//array of doubles. It will also have two member variables of type int; one
//called max_count for the size of the dynamic array of doubles; and one
//called count for the number of array positions currently holding values.
//(max_count is the same as the capacity of a vector; count is the same as the
//size of a vector.)

//If you attempt to add an element (a value of type double) to the vector
//object of the class VectorDouble and there is no more room, then a new
//dynamic array with twice the capacity of the old dynamic array is created
//and the values of the old dynamic array are copied to the new dynamic array.
//Programming Projects 695

//Your class should have all of the following:
//** Three constructors: a default constructor that creates a dynamic array
//for 50 elements, a constructor with one int argument for the number
//of elements in the initial dynamic array, and a copy constructor.
//** A destructor.
//** A suitable overloading of the assignment operator =.
//** A suitable overloading of the equality operator ==. To be equal, the
//values of count and the count array elements must be equal, but the
//values of max_count need not be equal.
//** Member functions push_back, capacity, size, reserve, and resize
//that behave the same as the member functions of the same names for
//vectors.
//** Two member functions to give your class the same utility as the
//square brackets: value_at(i), which returns the value of the ith
//element in the dynamic array; and change_value_at(d, i), which
//changes the double value at the ith element of the dynamic array
//to d. Enforce suitable restrictions on the arguments to value_at and
//change_value_at. (Your class will not work with the square brackets.
//It can be made to work with square brackets, but we have not covered
//the material which tells you how to do that.)

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ** VectorDouble CLASS DECLARATION ** //

class VectorDouble
{
public:
    VectorDouble();
    VectorDouble(int arr_size);
    VectorDouble(const VectorDouble& duplicate);
    ~VectorDouble();
    void operator=(const VectorDouble& other);
    friend bool operator==(const VectorDouble& first, const VectorDouble& second);
    void push_back(double d);
    int capacity();
    int size();
    void reserve(int size);
    void resize(int new_size);
    double value_at(int i);
    void change_value_at(double d, int i);

private:
    double* arr;
    int count;
    int max_count;
};

// ** MAIN TEST FUNCTION ** //

int main()
{
    VectorDouble test1(50);

    test1.push_back(12.1);
    test1.push_back(15.8);
    test1.push_back(19.1);
    test1.push_back(222.1);
    test1.push_back(90.7);
    test1.push_back(2);

    cout << "Testing member functions of VectorDouble class:\n";
    cout << "Capacity of VectorDouble test1: " << test1.capacity() << endl;
    cout << "Size of VectorDouble test1: " << test1.size() << endl;
    cout << "Values in test1:\n";
    for (int i = 0; i < test1.size(); i++)
    {
        cout << "value at index " << i << " = " << test1.value_at(i) << endl;
    }

    cout << "Changing value at index 2 in test 1.\n";
    test1.change_value_at(12.24, 2);
    cout << "The value at index 2 is now: " << test1.value_at(2);
    cout << "Resizing test1...";
    test1.resize(20);
    cout << "test1 is now size " << test1.size() << endl;
    cout << "testing copy constructor (copying test1 to copy1)...";

    VectorDouble copy1(test1);
    cout << "copy1:" << endl;
    for (int i = 0; i < copy1.size(); i++)
    {
        cout << copy1.value_at(i);
    }

}

// ** VectorDouble CLASS MEMBER FUNCTION DEFINITIONS ** //

VectorDouble::VectorDouble()
{
    max_count = 50;
    count = 0;
    arr = new double [max_count];
}
VectorDouble::VectorDouble(int arr_size)
{
    max_count = arr_size;
    count = 0;
    arr = new double [max_count];
}
VectorDouble::VectorDouble(const VectorDouble& duplicate)
{
    double *temp = new double[duplicate.count];

    count = duplicate.size();
    for (int i = 0; i < duplicate.size(); i++)
    {
        temp[i] = duplicate.value_at(i);
    }
    arr = temp;
}
VectorDouble::~VectorDouble()
{
    delete [] arr;
}
void VectorDouble::operator=(const VectorDouble& other)
{
    count = other.count;
    max_count = other.max_count;
    for (int i = 0; i < count; i++)
    {
        arr[i] = other.arr[i];
    }
}
bool operator==(const VectorDouble& first, const VectorDouble& second)
{
    if(first.count != second.count)
    {
        return false;
    }
    for(int i = 0; i < first.count; i++)
    {
        if (first.arr[i] != second.arr[i])
        {
            return false;
        }
    }
    return true;

}
void VectorDouble::push_back(double d)
{
    arr[count] = d;
    count++;
}
int VectorDouble::capacity()
{
    return max_count;
}
int VectorDouble::size()
{
    return count;
}
void VectorDouble::reserve(int size)
{
    if (size < 0)
    {
        cout << "error: size cannot be negative";
        return;
    }
    if (max_count >= size)
    {
        return;
    }
    else
    {
        max_count = size;
        double *new_arr = new double [max_count];
        for (int i = 0; i < count; i++)
        {
            new_arr[i] = arr[i];
        }
        arr = new_arr;
        delete [] new_arr;
    }
}
void VectorDouble::resize(int new_size)
{
    if (new_size < 0)
    {
        cout << "error: size cannot be negative.\n";
        return;
    }
    else
    {
        max_count = new_size;
        double *new_arr = new double [max_count];
        if (count > max_count)
        {
            for (int i = 0; i < max_count; i++)
            {
                new_arr[i] = arr[i];
            }
            count = max_count;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                new_arr[i] = arr[i];
            }
        }
        arr = new_arr;
        delete [] new_arr;
    }
}
double VectorDouble::value_at(int i)
{
    if (i < 0 || i > count)
    {
        cout << "invalid value_at parameter. Either less than zero or greater than vector size.\n";
    }
    else return arr[i];
}
void VectorDouble::change_value_at(double d, int i)
{
    if (i < 0 || i > count)
    {
        cout << "invalid change_value_at parameter, either less than zero or greater than vector size.\n";
    }
    else arr[i] = d;
}
