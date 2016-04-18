#include "List.h"

using namespace std;

List::List()
    {
        arr_size = 0;
    }

void List::addValue(double number)
    {
        if (this->isFull())
        {
            throw(1);
            return;
        }
        if (number == -1)
        {
            throw (2);
            return;
        }
        arr[arr_size] = number;
        arr_size++;
    }

double List::getLast()
    {
        return arr[arr_size];
    }
void List::deleteLast()
    {
        arr[arr_size] = 0;
        arr_size--;
    }
int List::getSize()
    {
        return arr_size;
    }

double List::getValue(int position)
    {
        return arr[position];
    }

void List::printList()
    {
        for (int i = 0; i < arr_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

bool List::isFull()
    {
        if (arr_size >= MAX_ARRAY_SIZE)
        {
            return true;
        }
        else return false;
    }
