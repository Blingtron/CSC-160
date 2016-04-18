#include "List.h"

using namespace std;

int main()
{
    char quit;
    do
    {
        List test1;
        cout << "Please enter up to " << MAX_ARRAY_SIZE << " values to put in a test List object." << endl;
        cout << "Terminate input with -1." << endl;
        try
        {
            double temp;
                for (int i = 0 ; i < MAX_ARRAY_SIZE; i++)
                {
                    cin >> temp;
                    test1.addValue(temp);
                }
        }
        catch (int x)
        {
            if (x==1)
            {
                cout << "Cannot add number to List, array is full.\n";
            }
            else if (x==2)
            {
                cout << "List terminated with -1." << endl;
            }
        }

        cout << "There are " << test1.getSize() << " values in the list." << endl;
        cout << "The values of the list are: ";
        test1.printList();
        if (test1.isFull())
        {
            cout << "The test list is full." << endl;
        }
        else
        {
            cout << "The test list is not full." << endl;
        }
        cout << "\nDeleting the last element of the list..." << endl << endl;
        test1.deleteLast();
        cout << "There are now " << test1.getSize() << " values in the list." << endl;
        cout << "The values of the list are: ";
        test1.printList();
        if (test1.isFull())
        {
            cout << "The test list is full." <<endl;
        }
        else
        {
            cout << "The test is not full." << endl;
        }
        cout << "End of List class test. enter Y or y to try again, anything else quits." << endl;
        cin >> quit;

    }
    while (toupper(quit) == 'Y');
}
