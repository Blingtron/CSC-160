#include <string>
#include <iostream>
#include "password.h"

namespace
{
    string password;
    bool isValid()
    {
        int alpha_count = 0;
        for (int i = 0; i < password.size(); i++)
        {
            if (isalpha(password[i]))
            {
                alpha_count++;
            }
        }
        return (password.size() >= 8 && alpha_count != password.size());
    }
}

namespace Authenticate
{
    void inputPassword()
    {
        do
        {
            cout << "Enter your password (at least 8 characters " <<
            "and at least one nonletter)" << endl;
            cin >> password;
        } while (!isValid());
    }
    string getPassword()
    {
        return password;
    }
}
