#ifndef PASSWORD_H
#define PASSWORD_H
#include <iostream>
using namespace std;

namespace Authenticate
{
    void inputPassword();
        // prompts user to enter password. Must be 8 or more characters, at least one nonletter.
    string getPassword();
        // returns user's password.
}

#endif // PASSWORD_H
